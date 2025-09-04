//@Sudoku.c
#include "Global.h"

/**
* @param   SudokuFile(����CNF�ļ���), holes(�ڶ���)
* @return  status ����ִ��״̬
* @brief   ����������ʼ���̣�������ת��ΪCNF��ʽд�뵽CNF�ļ���  
*/
status CreateSudokuToFile(char SudokuFile[], int holes)
{
    int sudoku[ROW][COL]={0};       //�����������̶�ά���飬��ȫ����ʼ��Ϊ0 
    int play[ROW][COL]={0};         //�������̶�ά���飬��ȫ����ʼ��Ϊ0 
    CreateSudoku(sudoku);           //������������ 
    CreatePlay(sudoku, play, holes);//���ɳ���
    int i, j;
    for(i=0; i<COL; i++){
    	for(j=0; j<ROW; j++){
    		player[i][j] = play[i][j];
		}
	}
    
    //����������д��CNF�ļ�
	TranToCNF(play, holes, SudokuFile);
	return OK;
}


/**
* @param  rows�����ڴ洢�������̵Ķ�ά���飩
* @return void
* @brief  ���������������̣�����������ʵ�� 
*/
void CreateSudoku(int rows[][COL])
{
	FirstRow(rows[0]);    //����������һ�� 
	OtherRows(rows, 1, 0);//�ݹ����������� 
	return;
}


/**
* @param   rows�����ڴ洢�������̵Ķ�ά���飩��i����i�У���0��ʼ������j����j�У���0��ʼ���� 
* @return  status������ִ��״̬�� 
* @brief   ���õݹ����i�е�j��λ�ø���һ�����֣�ֱ������������������ 
* @detail  check[COL+1]��ֵΪWAʱ��ʾ�±������Ѿ���ͬ�л�ͬ�л�ͬ��ʹ�ù���ֵΪAC��ʾδʹ�ù�
* @todo     
*/
status OtherRows(int rows[][COL], int i, int j){
	if(i<ROW && j<COL){
		int x, y, k;
		int check[COL+1] = {AC};                  
		for(x=0; x<i; x++) check[rows[x][j]] = WA;//���ͬ����ʹ�ù������� 
		for(x=0; x<j; x++) check[rows[i][x]] = WA;//���ͬ����ʹ�ù������� 
		for(x=i/3*3; x<=i; x++){                  //���ͬ����ʹ�ù������� 
			if(x==i){
				for(y=j/3*3; y<j; y++) check[rows[x][y]] = WA;
			}
			else{
				for(y=j/3*3; y<j/3*3 + 3; y++) check[rows[x][y]] = WA;
			}
		}
		
		int flag = 0;
		for(k=1; k<=COL && flag==0; k++){
			if(check[k]==AC){
				flag = 1;
				rows[i][j] = k;
				if(j==COL-1 && i!=ROW-1){//���ij��һ�е����һ���Ҳ������һ�У��ݹ������һ�� 
					if(OtherRows(rows, i+1, 0)==AC) return AC;
					else flag = 0;
				}
				else if(j!=COL-1){//����������һ�У��ݹ������һ�� 
					if(OtherRows(rows, i, j+1)==AC) return AC;
					else flag = 0;
				}
			}
		}
		if(flag==0){
			rows[i][j] = 0;
			return WA;
		}
	}
	return AC;
} 


/**
* @param   firstrow
* @return  void
* @brief  ���õ�ǰϵͳʱ����������������̵�һ�� 
*/
void FirstRow(int firstrow[])
{
	int i, j;
	srand((unsigned int)time(NULL));
	for(i=0; i<COL; i++){
		firstrow[i] = rand() % 9 + 1;
		j = 0;
		while(j<i){//��֤�µĸ�ֵ���������е�����
			if(firstrow[j]==firstrow[i]){
				firstrow[i] = rand() % 9 + 1;
				j = 0;
			}
			else{
				j++;
			}
		}
	}
}


/**
* @param   a(�������̶�ά����), b(�������̶�ά����), numDigits���ڶ����� 
* @return  void
* @brief   �����ڶ������������������ 
*/
void CreatePlay(int a[][COL], int b[][COL], int numDigits)
{
    int i, j, k;
    srand((unsigned)time(NULL));//�õ�ǰϵͳʱ��������������� 
    for(i=0; i<ROW; i++)        //����������������и��� 
        for(j=0; j<COL; j++)
            b[i][j] = a[i][j];

    int c[numDigits][2];
    int m, flag = 0;

    for(i=0; i<numDigits; i++){//���ѡ��λ�� 
        j = rand() % 9;
        k = rand() % 9;

        flag = 0;
        for(m=0; m<i; m++)
            if(j==c[m][0] && k==c[m][1])
                flag = 1;

        if(flag==0){
            b[j][k] = 0;
            c[i][0] = j;
            c[i][1] = k;
        }
        else
            i--;
    }
}


/**
* @param   a(�������̶�ά����), holes���ڶ�������SudokuFile���ļ����� 
* @return  void
* @brief   ����������д��CNF�ļ� 
*/
status TranToCNF(int a[][COL], int holes, char SudokuFile[])
{
	FILE *fp = fopen(SudokuFile, "w");
	if(!fp) exit(ERROR);
	fprintf(fp, "p cnf 729 %d\n", 6642+81-holes);
	int x, y, z;
	for(x=0; x<ROW; x++){//play�̵���֪��Ϣ��Ϊ���Ӿ�����Ӿ伯
		for(y=0; y<COL; y++){
			if(a[x][y]!=0){
				fprintf(fp, "%d 0\n", (x+1)*100 + (y+1)*10 + a[x][y]);
			}
		}
	} 
	for(x=1; x<=9; x++){//ÿ�����Ӷ�������1-9������һ������ 
		for(y=1; y<=9; y++){
			for(z=1; z<=9; z++){
				fprintf(fp, "%d ", x*100 + y*10 + z);
			}
			fprintf(fp, "0\n");
		}
	}
	int i, j, k;
	
	//��Լ��
	for(y=1; y<=9; y++){ 
		for(z=1; z<=9; z++){
			for(x=1; x<=8; x++){
				for(i=x+1; i<=9; i++){
					fprintf(fp, "%d ", opp(x*100 + y*10 +z));
					fprintf(fp, "%d 0\n", opp(i*100 + y*10 + z));
				}
			}
		}
	}
	
	//��Լ�� 
	for(x=1; x<=9; x++){
		for(z=1; z<=9; z++){
			for(y=1; y<=8; y++){
				for(i=y+1; i<=9; i++){
					fprintf(fp, "%d ", opp(x*100 + y*10 +z));
					fprintf(fp, "%d 0\n", opp(x*100 + i*10 + z));
				}
			}
		}
	}
	
	//��Լ�� 
	for(z=1; z<=9; z++){
		for(i=0; i<=2; i++){
			for(j=0; j<=2; j++){
				for(x=1; x<=3; x++){
					for(y=1; y<=3; y++){
						for(k=y+1; k<=3; k++){
							fprintf(fp, "%d ", opp((3*i+x)*100 + (3*j+y)*10 + z));
							fprintf(fp, "%d 0\n", opp((3*i+x)*100 + (3*j+k)*10 + z));
						}
						
					}
				}
			}
		}
	}
	int m;
	for(z=1; z<=9; z++){
		for(i=0; i<=2; i++){
			for(j=0; y<=2; j++){
				for(x=1; x<=3; x++){
					for(y=1; y<=3; y++){
						for(k=x+1; k<=3; k++){
							for(m=1; m<=3; m++){
								fprintf(fp, "%d ", opp((3*i+x)*100 + (3*j+y)*10 + z));
								fprintf(fp, "%d 0\n", opp((3*i+k)*100 + (3*j+m)*10 + z));
							}
						}
					}
				}
			}
		}
	}
	fclose(fp);
	return OK;
}


/**
* @param  CHead **C������ͷ���ָ���ָ�룩 
* @return ����ִ�н�� 
* @brief  ������������Sudoku����ں���  
*/
status EntrySUDOKU(CHead **C)
{
	int re, i;
	//clock_t start_t, end_t;
	//double total_t;
	//start_t = clock();
	re = DPLLSolver(C);
	//end_t = clock();
	//total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC * 1000;//��ʱ����
	if(re==OK) return re;
	else return ERROR;
}


/**
* @param  int re��DPLL��ִ�н������filename���ļ����� 
* @return status������ִ��״̬�� 
* @brief  ��������������뵽.res�ļ��� 
*/
status SaveSudokuFile(int re, char filename[])
{
	int i, j, k, x;
	//�޸���չ�� 
	for(i=0; filename[i]!='\n'; i++){
		if(filename[i]=='.'){
			filename[i+1] = 'r';
			filename[i+2] = 'e';
			filename[i+3] = 's';
		}
	}
	
	FILE *fp;
	fp = fopen(filename, "w");
	if(!fp) exit(-1);
	if(re==TRUE){//���re==TRUE����������������뵽�ļ��� 
		fprintf(fp, "s 1\n");
		fprintf(fp, "v ");
		for(i=1; i<=9; i++){
			for(j=1; j<=9; j++){
				for(k=1; k<=9; k++){
					x = i*100 + j*10 + k;
					if(counter[x].value==1){
						fprintf(fp, "%d ", x);
					}
				}
			}
		}
		fprintf(fp, "\n");
	}
	else{
		fprintf(fp, "s 0\n");
	}
	fclose(fp);
	/*
	if(re==TRUE){
		printf("s 1\n");
		printf("v\n");
		for(i=1; i<=9; i++){
			for(j=1; j<=9; j++){
				for(k=1; k<=9; k++){
					x = i*100 + j*10 + k;
					if(counter[x].value==1){
						printf("%d ", x);
					}
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	else{
		printf("s 0\n");
	}*/
	return OK;
}


/**
* @param   a���������̵Ķ�ά���飩 
* @return  void
* @brief  ���ն�������������� 
*/
void print(int a[][COL])
{
    int i, j;
    printf("     1  2  3    4  5  6    7  8  9\n");
    for(i=0; i<ROW; i++){
    	if(i%3==0) printf("   ----------------------------------\n");
    	printf("%d  ", i+1); 
        for(j=0; j<COL ; j++){
        	if(j%3==0) printf("| ");
        	if(a[i][j]!=0) printf("%d  ", a[i][j]);
        	else printf("_  ");
		}
		if(i%3==2) printf("|\n");
		else{
			printf("|\n");
        	printf("   |          |          |          |\n");
		}
    }
    printf("   ----------------------------------\n");
}
