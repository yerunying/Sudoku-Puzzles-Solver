//@file DPLLSolver.c
#include "Global.h"
status FreeCNodes(CHead **node)    //�ͷſռ� 
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
status DelClause(int x, CHead **C)    //ȥ��x���Ӿ� 
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
status DelNode(int x, CHead **C)    //ȥ���Ӿ��еĽ�� 
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
status Simplification(int uni, CHead **C)    //��C��ȥ��uni 
{
	DelClause(uni, C);    //ȥ���Ӿ� 
	DelNode(uni, C);      //ȥ���Ӿ��еĽ�� 
	return OK;
}
status AddUniClause(int x, CHead **C)    //��һ��ֵΪx���µ��Ӿ����C_copy1 
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
		uni > 0 ? (counter[abs(uni)].value = 1) : (counter[abs(uni)].value = -1);//value��¼uni���� 
		Simplification(uni, C);                                                   
		if(*C==NULL) return TRUE;
		else if(isEmptyClause(*C)) return FALSE;    //�п��Ӿ�,�޷����� 
	}
	uni = strategy2(C);    //!!!                                                      
	uni > 0 ? (counter[abs(uni)].value = 1) : (counter[abs(uni)].value = -1);
	PHead copy1 = Duplication(C);                                                 
	AddUniClause(uni, &copy1);                                                    
	if(DPLLSolver(&copy1)) return TRUE;    //�ݹ����                                           
	else{
		PHead copy2 = Duplication(C);
		uni > 0 ? (counter[abs(uni)].value = -1) : (counter[abs(uni)].value = 1);
		AddUniClause(opp(uni), &copy2);    //��-uni����C_copy2 
		return DPLLSolver(&copy2);         //�ݹ���� 
	}
}
CHead* isUniClause(CHead *C)    //�ҵ��Ӿ� 
{
	CHead *temp = C;
	while(temp!=NULL){
		if(temp->info==1){    //���ص�һ�����Ӿ���ֵĵ�ַ 
			return temp;
		}
		temp = temp->down;
	}
	return NULL;
}
status isEmptyClause(CHead *C)    //�ж��Ƿ��п��Ӿ� 
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
CHead* Duplication(CHead **C)    //����һ��C,�������¸������ַ 
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
int strategy1(CHead **C)    //ֱ��ѡȡ��һ��ֵ��Ϊuni! 
{
	return (*C)->right->data;
}
int strategy2(CHead **C)    //���س��ִ�������x 
{
	PHead dnow = *C;
	PNode rnow = NULL;
	int x, pos = 0;
	double max = 0.0;
	while(dnow!=NULL){    //��count����x 
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
	if(pos==0) pos = (*C)->right->data;    //�Ҳ�������strategy1�� 
	if(counter[pos].positive>counter[pos].negative) return pos;    //��������ֵ��ռ��ͷ�� 
	else return opp(pos);
}
int EntrySAT(char FileName[])
{
	PHead C = NULL;
	int re, i;
	clock_t start_t, end_t;
	double total_t;
	FileReader(&C, FileName);    //�����ļ��������ݽṹ                                  
	start_t = clock();           //��¼��ʼʱ��                                     
	re = DPLLSolver(&C);                                         
	end_t = clock();             //��¼����ʱ��                               
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC * 1000;    //������ʱ�� 
	SaveSATFile(re, total_t, FileName);    //��������ļ� 
	if(re==FALSE) return ERROR;                          
	return OK;
}
status SaveSATFile(int re, double t, char filename[])    //��������ļ� 
{
	int i;
	for(i=0; filename[i]!='\n'; i++){    //�����ļ��� 
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
		fprintf(fp, "s 1\n");    //��ʾsatisfy 
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
	else{                        //��ʾunsatisfy 
		fprintf(fp, "s 0\n");
	}
	fprintf(fp, "t %f", t);
	fclose(fp);
	return OK;
}
