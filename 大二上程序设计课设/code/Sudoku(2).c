//@Sudoku.c
#include "Global.h"

/**
* @param   SudokuFile(数独CNF文件名), holes(挖洞数)
* @return  status 函数执行状态
* @brief   创建数独初始棋盘，并将其转化为CNF格式写入到CNF文件中  
*/
status CreateSudokuToFile(char SudokuFile[], int holes)
{
    int sudoku[ROW][COL]={0};       //声明数独终盘二维数组，并全部初始化为0 
    int play[ROW][COL]={0};         //数独初盘二维数组，并全部初始化为0 
    CreateSudoku(sudoku);           //生成数独终盘 
    CreatePlay(sudoku, play, holes);//生成初盘
    int i, j;
    for(i=0; i<COL; i++){
    	for(j=0; j<ROW; j++){
    		player[i][j] = play[i][j];
		}
	}
    
    //把数独初盘写进CNF文件
	TranToCNF(play, holes, SudokuFile);
	return OK;
}


/**
* @param  rows（用于存储数独棋盘的二维数组）
* @return void
* @brief  生成完整数独棋盘，用两个函数实现 
*/
void CreateSudoku(int rows[][COL])
{
	FirstRow(rows[0]);    //生成数独第一行 
	OtherRows(rows, 1, 0);//递归生成其他行 
	return;
}


/**
* @param   rows（用于存储数独棋盘的二维数组），i（第i行，从0开始数），j（第j列，从0开始数） 
* @return  status（函数执行状态） 
* @brief   利用递归给第i行第j列位置赋上一个数字，直至生成整个数独棋盘 
* @detail  check[COL+1]，值为WA时表示下标数字已经被同行或同列或同宫使用过，值为AC表示未使用过
* @todo     
*/
status OtherRows(int rows[][COL], int i, int j){
	if(i<ROW && j<COL){
		int x, y, k;
		int check[COL+1] = {AC};                  
		for(x=0; x<i; x++) check[rows[x][j]] = WA;//标记同列已使用过的数字 
		for(x=0; x<j; x++) check[rows[i][x]] = WA;//标记同行已使用过的数字 
		for(x=i/3*3; x<=i; x++){                  //标记同宫已使用过的数字 
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
				if(j==COL-1 && i!=ROW-1){//如果ij是一行的最后一列且不是最后一行，递归进入下一行 
					if(OtherRows(rows, i+1, 0)==AC) return AC;
					else flag = 0;
				}
				else if(j!=COL-1){//如果不是最后一列，递归进入下一列 
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
* @brief  利用当前系统时间随机生成数独棋盘第一行 
*/
void FirstRow(int firstrow[])
{
	int i, j;
	srand((unsigned int)time(NULL));
	for(i=0; i<COL; i++){
		firstrow[i] = rand() % 9 + 1;
		j = 0;
		while(j<i){//保证新的赋值不等于已有的数字
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
* @param   a(数独终盘二维数组), b(数独初盘二维数组), numDigits（挖洞数） 
* @return  void
* @brief   利用挖洞法随机生成数独初盘 
*/
void CreatePlay(int a[][COL], int b[][COL], int numDigits)
{
    int i, j, k;
    srand((unsigned)time(NULL));//用当前系统时间生成随机数种子 
    for(i=0; i<ROW; i++)        //对数独终盘数组进行复制 
        for(j=0; j<COL; j++)
            b[i][j] = a[i][j];

    int c[numDigits][2];
    int m, flag = 0;

    for(i=0; i<numDigits; i++){//随机选择位置 
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
* @param   a(数独初盘二维数组), holes（挖洞数），SudokuFile（文件名） 
* @return  void
* @brief   把数独初盘写进CNF文件 
*/
status TranToCNF(int a[][COL], int holes, char SudokuFile[])
{
	FILE *fp = fopen(SudokuFile, "w");
	if(!fp) exit(ERROR);
	fprintf(fp, "p cnf 729 %d\n", 6642+81-holes);
	int x, y, z;
	for(x=0; x<ROW; x++){//play盘的已知信息作为单子句加入子句集
		for(y=0; y<COL; y++){
			if(a[x][y]!=0){
				fprintf(fp, "%d 0\n", (x+1)*100 + (y+1)*10 + a[x][y]);
			}
		}
	} 
	for(x=1; x<=9; x++){//每个格子都可能填1-9的任意一个数字 
		for(y=1; y<=9; y++){
			for(z=1; z<=9; z++){
				fprintf(fp, "%d ", x*100 + y*10 + z);
			}
			fprintf(fp, "0\n");
		}
	}
	int i, j, k;
	
	//列约束
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
	
	//行约束 
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
	
	//宫约束 
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
* @param  CHead **C（链表头结点指针的指针） 
* @return 函数执行结果 
* @brief  从主函数进入Sudoku的入口函数  
*/
status EntrySUDOKU(CHead **C)
{
	int re, i;
	//clock_t start_t, end_t;
	//double total_t;
	//start_t = clock();
	re = DPLLSolver(C);
	//end_t = clock();
	//total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC * 1000;//计时换算
	if(re==OK) return re;
	else return ERROR;
}


/**
* @param  int re（DPLL的执行结果），filename（文件名） 
* @return status（函数执行状态） 
* @brief  将数独求解结果输入到.res文件中 
*/
status SaveSudokuFile(int re, char filename[])
{
	int i, j, k, x;
	//修改拓展名 
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
	if(re==TRUE){//如果re==TRUE，则将数独求解结果输入到文件中 
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
* @param   a（数独棋盘的二维数组） 
* @return  void
* @brief  在终端上输出数独棋盘 
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
