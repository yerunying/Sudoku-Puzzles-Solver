//@file DPLLSolver.c
#include "Global.h"
status FreeCNodes(CHead **node)    //释放空间 
{
	CNode *p = NULL, *q = NULL;
	p = (*node)->right;
	q = p->next;
	if(q==NULL){
		free(p);
	}
	while(q!=NULL){
		free(p); 
		p = q;
		q = p->next;
	}
	return OK;
}
status DelClause(int x, CHead **C)    //去含x的子句 
{
	PHead p = *C, q = NULL;
	PNode m = NULL;
	int flag = 1;
	while(p!=NULL){
		m = p->right;
		while(m!=NULL){
			if(m->data==x){
				flag = 0;
				break;
			}
			m = m->next;
		}
		if(flag==1){
			break;
		}
		else if(flag==0){
			q = *C;
			*C = (*C)->down;
			p = *C;
			FreeCNodes(&q);
			free(q);
			q = NULL; 
			flag = 1;
		}
	}
	if(*C==NULL){
		return OK;
	}
	p = *C;
	q = p->down;
	flag = 0;
	while(q!=NULL){
		m = q->right;
		while(m!=NULL){
			if(m->data==x){
				flag = 1;
				p->down = q->down; 
				FreeCNodes(&q); 
				free(q);
				q = NULL;
				break;
			}
			m = m->next;
		}
		if(flag==0){
			p = p->down;
			q = q->down;
		}
		else if(flag==1){
			q = p->down;
			flag = 0;
		}
	}
	return OK;
}
status DelNode(int x, CHead **C)    //去多子句中的结点 
{
	PHead temp1 = *C;
	PNode temp2 = NULL, p = NULL, q = NULL; 
	while(temp1!=NULL){
		temp2 = temp1->right;
		while(temp2->data==opp(x)){
			temp1->right = temp2->next;
			free(temp2);
			temp2 = temp1->right;
			temp1->info--;
		}
		p = temp2;
		q = p->next;
		while(q!=NULL){
			if(q->data==opp(x)){
				p->next = q->next;
				free(q);
				q = p->next;
				temp1->info--;
			}
			else{
				p = q;
				q = p->next;
			}
		}
		temp1 = temp1->down;
	}
	return OK;	
}
status Simplification(int uni, CHead **C)    //在C中去掉uni 
{
	DelClause(uni, C);    //去单子句 
	DelNode(uni, C);      //去多子句中的结点 
	return OK;
}
status AddUniClause(int x, CHead **C)    //将一个值为x的新单子句加入C_copy1 
{
	PHead ne = NULL;
	ne = (PHead)malloc(sizeof(CHead));
	if(!ne) exit(ERROR);
	ne->down = *C;
	ne->right = NULL;
	ne->info = 0;
	*C = ne;
	ne->info = 1;
	PNode node = IniNode(&(ne->right));
	node->data = x;
	counter[abs(x)].count += 1;
	if(x>0){
		counter[abs(x)].positive += 1;
	}
	else{
		counter[abs(x)].negative += 1;
	}
	node = IniNode(&(node->next));
	return OK;
}
status DPLLSolver(CHead **C)
{
	PHead dnow = NULL; 
	int uni = 0;
	while((dnow=isUniClause(*C))!=NULL){                                         
		uni = dnow->right->data;                                                 
		uni > 0 ? (counter[abs(uni)].value = 1) : (counter[abs(uni)].value = -1);//value记录uni正负 
		Simplification(uni, C);                                                   
		if(*C==NULL) return TRUE;
		else if(isEmptyClause(*C)) return FALSE;    //有空子句,无法满足 
	}
	uni = strategy2(C);    //!!!                                                      
	uni > 0 ? (counter[abs(uni)].value = 1) : (counter[abs(uni)].value = -1);
	PHead copy1 = Duplication(C);                                                 
	AddUniClause(uni, &copy1);                                                    
	if(DPLLSolver(&copy1)) return TRUE;    //递归调用                                           
	else{
		PHead copy2 = Duplication(C);
		uni > 0 ? (counter[abs(uni)].value = -1) : (counter[abs(uni)].value = 1);
		AddUniClause(opp(uni), &copy2);    //将-uni加入C_copy2 
		return DPLLSolver(&copy2);         //递归调用 
	}
}
CHead* isUniClause(CHead *C)    //找单子句 
{
	CHead *temp = C;
	while(temp!=NULL){
		if(temp->info==1){    //返回第一个单子句出现的地址 
			return temp;
		}
		temp = temp->down;
	}
	return NULL;
}
status isEmptyClause(CHead *C)    //判断是否有空子句 
{
	CHead *temp = C;
	while(temp!=NULL){
		if(temp->info==0){
			return OK; 
		}
		temp = temp->down;
	}
	return FALSE;
}
CHead* Duplication(CHead **C)    //复制一个C,并返回新复制体地址 
{
	PHead p = *C, q = NULL, dt = NULL, dnow = NULL; 
	PNode rnow = NULL, rt = NULL; 
	while(p!=NULL){
		dnow = IniClause(&q);
		dnow->info = p->info;
		rt = p->right;
		while(rt!=NULL){
			rnow = IniNode(&(dnow->right));
			rnow->data = rt->data;
			rt = rt->next;
		}
		p = p->down;
	}
	return q;
}
int strategy1(CHead **C)    //直接选取第一个值作为uni! 
{
	return (*C)->right->data;
}
int strategy2(CHead **C)    //返回出现次数最多的x 
{
	PHead dnow = *C;
	PNode rnow = NULL;
	int x, pos = 0;
	double max = 0.0;
	while(dnow!=NULL){    //找count最大的x 
		rnow = dnow->right;
		while(rnow!=NULL){
			x = rnow->data;
			if(counter[x].count>max){
				max = counter[x].count;
				pos = x;
			}
			rnow = rnow->next;
		}
		dnow = dnow->down;
	}
	if(pos==0) pos = (*C)->right->data;    //找不到就用strategy1了 
	if(counter[pos].positive>counter[pos].negative) return pos;    //返回正负值中占大头的 
	else return opp(pos);
}
int EntrySAT(char FileName[])
{
	PHead C = NULL;
	int re, i;
	clock_t start_t, end_t;
	double total_t;
	FileReader(&C, FileName);    //根据文件构建数据结构                                  
	start_t = clock();           //记录开始时间                                     
	re = DPLLSolver(&C);                                         
	end_t = clock();             //记录结束时间                               
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC * 1000;    //计算总时间 
	SaveSATFile(re, total_t, FileName);    //保存输出文件 
	if(re==FALSE) return ERROR;                          
	return OK;
}
status SaveSATFile(int re, double t, char filename[])    //保存输出文件 
{
	int i;
	for(i=0; filename[i]!='\n'; i++){    //更改文件名 
		if(filename[i]=='.'){
			filename[i+1] = 'r';
			filename[i+2] = 'e';
			filename[i+3] = 's';
		}
	}
	FILE *fp;
	fp = fopen(filename, "w");
	if(!fp) exit(-1);
	if(re==TRUE){
		fprintf(fp, "s 1\n");    //表示satisfy 
		fprintf(fp, "v ");
		for(i=1; counter[i].data!=0 && i<MAXN; i++){
			if(counter[i].value==1){
				fprintf(fp, "%d ", i);
			}
			else if(counter[i].value==-1){
				fprintf(fp, "%d ", -i);
			}
		}
		fprintf(fp, "\n");
	}
	else{                        //表示unsatisfy 
		fprintf(fp, "s 0\n");
	}
	fprintf(fp, "t %f", t);
	fclose(fp);
	return OK;
}
