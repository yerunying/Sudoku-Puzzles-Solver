//@file FileReader.c
#include "Global.h"
status FileReader(CHead **C, char filename[])    //根据文件构建数据结构 
{   FILE *fp = NULL;
	fp = fopen(filename, "r");
	if(!fp) exit(ERROR);
	char ch;
	int num1, num2;
	while((ch=fgetc(fp))!='p'){    //手动跳过命令行 
		if(ch=='c'){
			while((ch=fgetc(fp))!='\n'){
				;
			}
		}
	}
	while((ch=fgetc(fp))!='f'){
		;
	}
	fscanf(fp, "%d %d", &num1, &num2);
	int i;
	for(i=0; i<=num1; i++){    //初始化counter 
		counter[i].count = 0.0;
		counter[i].data = 0;
		counter[i].negative = 0.0;
		counter[i].positive = 0.0;
		counter[i].value = 0;
	}
	int x;
	PHead dnow = NULL;
	PNode rnow = NULL;
	i = num2;
	while(i>0){
		i--;
		dnow = IniClause(C);    //新建一个子句 
		do{
			fscanf(fp, "%d", &x);
			counter[abs(x)].data = abs(x);
			rnow = IniNode(&(dnow->right));    //在该子句上新建一个结点 
			rnow->data = x;
			dnow->info++;
		}while(x!=0);
	}
	fclose(fp);
	i = num2;
	dnow = *C;
	while(i>0){
		i--;
		rnow = dnow->right;    //遍历子句上的每个结点 
		do{                    //记录总出现频率和正负出现频率 
			x = rnow->data;
			counter[abs(x)].count += pow(0.5, (double)(dnow->info - 1));
			if(x>0){
				counter[abs(x)].positive += pow(0.5, (double)(dnow->info - 1));
			}
			else{
				counter[abs(x)].negative += pow(0.5, (double)(dnow->info - 1));
			}
			rnow = rnow->next;
		}while(x!=0);
		dnow = dnow->down;    //遍历每个子句 
	}
	return OK;
}
CHead* IniClause(CHead **C)    //初始化一个新的 CHead 结构体，并将其添加到链表的末尾 
{
	CHead *ne = NULL, *temp = *C;
	ne = (PHead)malloc(sizeof(CHead));
	if(!ne) return FALSE;
	ne->down = NULL;
	ne->right = NULL;
	ne->info = -1;
	if(*C==NULL){
		*C = ne;
		return ne;
	}
	while(temp->down!=NULL){
		temp = temp->down;
	}
	temp->down = ne;
	return ne;
}
CNode* IniNode(CNode **right)    //初始化一个新的链表节点，并将其添加到指定链表的末尾
{
	CNode *ne = NULL, *temp = *right;
	ne = (PNode)malloc(sizeof(CNode));
	if(!ne) return FALSE;
	ne->next = NULL;
	ne->data = 0;
	if(*right==NULL){
		*right = ne;
		return ne;
	}
	while(temp->next!=NULL){ 
		temp = temp->next;
	}
	temp->next = ne;
	return ne;
}
int opp(int x)
{
	return -x;
}
