//@file FileReader.c
#include "Global.h"
status FileReader(CHead **C, char filename[])    //�����ļ��������ݽṹ 
{   FILE *fp = NULL;
	fp = fopen(filename, "r");
	if(!fp) exit(ERROR);
	char ch;
	int num1, num2;
	while((ch=fgetc(fp))!='p'){    //�ֶ����������� 
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
	for(i=0; i<=num1; i++){    //��ʼ��counter 
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
		dnow = IniClause(C);    //�½�һ���Ӿ� 
		do{
			fscanf(fp, "%d", &x);
			counter[abs(x)].data = abs(x);
			rnow = IniNode(&(dnow->right));    //�ڸ��Ӿ����½�һ����� 
			rnow->data = x;
			dnow->info++;
		}while(x!=0);
	}
	fclose(fp);
	i = num2;
	dnow = *C;
	while(i>0){
		i--;
		rnow = dnow->right;    //�����Ӿ��ϵ�ÿ����� 
		do{                    //��¼�ܳ���Ƶ�ʺ���������Ƶ�� 
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
		dnow = dnow->down;    //����ÿ���Ӿ� 
	}
	return OK;
}
CHead* IniClause(CHead **C)    //��ʼ��һ���µ� CHead �ṹ�壬��������ӵ������ĩβ 
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
CNode* IniNode(CNode **right)    //��ʼ��һ���µ�����ڵ㣬��������ӵ�ָ�������ĩβ
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
