//@Sudoku.c
#include "Global.h"
status CreateSudokuToFile(char SudokuFile[], int holes)
{        
    int sudoku2[ROW][COL],i,j;
    int play[ROW][COL]={0};         
    srand(time(0));
    int rn = (rand() % 20) + 1;
    switch(rn){
    	case 1:{
    		int sudoku[ROW][COL]={{7,1,3,5,2,6,8,4,9},{5,8,2,4,9,1,6,3,7},{9,6,4,7,3,8,1,2,5},{8,5,6,1,7,4,2,9,3},{3,7,1,2,5,9,4,8,6},{2,4,9,8,6,3,5,7,1},{4,3,7,6,1,2,9,5,8},{1,2,5,9,8,7,3,6,4},{6,9,8,3,4,5,7,1,2}};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 2:{
    		int sudoku[ROW][COL] = {  
                {4, 6, 8, 2, 9, 1, 5, 3, 7},  
                {9, 5, 2, 3, 7, 8, 1, 4, 6}, 
                {1, 3, 7, 6, 4, 5, 9, 2, 8}, 
                {7, 8, 5, 1, 2, 3, 6, 9, 4},  
                {2, 9, 6, 7, 8, 4, 3, 1, 5}, 
                {3, 1, 4, 5, 6, 9, 8, 7, 2},  
                {5, 7, 1, 4, 3, 6, 2, 8, 9},  
                {8, 2, 3, 9, 5, 7, 4, 6, 1},  
                {6, 4, 9, 8, 1, 2, 7, 5, 3} 
            };
            for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
    		break;
    	}
    	case 3:{
    		int sudoku[ROW][COL]={6,7,4,1,3,2,5,8,9,2,9,5,8,4,7,6,1,3,8,3,1,5,6,9,7,2,4,1,4,8,3,9,6,2,5,7,3,5,7,2,8,1,9,4,6,9,6,2,4,7,5,8,3,1,7,1,3,6,2,8,4,9,5,4,2,6,9,5,3,1,7,8,5,8,9,7,1,4,3,6,2};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 4:{
    		int sudoku[ROW][COL]={6,1,7,3,4,9,2,8,5,2,3,9,6,5,8,7,1,4,5,8,4,2,1,7,6,3,9,4,6,1,9,2,3,8,5,7,7,2,5,1,8,4,9,6,3,8,9,3,7,6,5,4,2,1,3,5,2,4,7,6,1,9,8,1,4,8,5,9,2,3,7,6,9,7,6,8,3,1,5,4,2};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 5:{
    		int sudoku[ROW][COL]={1,8,6,2,3,4,7,9,5,7,3,9,6,8,5,2,1,4,4,2,5,9,1,7,6,3,8,3,7,2,4,5,9,8,6,1,8,6,4,3,7,1,5,2,9,9,5,1,8,6,2,4,7,3,5,1,3,5,2,8,9,4,7,5,4,7,1,9,6,3,8,2,2,9,8,7,4,3,1,5,6};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 6:{
    		int sudoku[ROW][COL]={2,6,3,9,7,8,5,4,1,7,4,9,6,1,5,8,2,3,5,8,1,4,2,3,6,7,9,6,3,2,8,4,7,1,9,5,9,5,8,1,3,2,7,6,4,4,1,7,5,9,6,2,3,8,3,7,4,2,5,1,9,8,6,1,9,6,7,8,4,3,5,2,8,2,5,3,6,9,4,1,7};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 7:{
    		int sudoku[ROW][COL]={2,6,7,8,1,9,3,4,5,3,9,4,6,7,5,1,8,2,8,5,1,3,2,4,7,6,9,7,2,6,5,3,1,8,9,4,1,8,9,7,4,2,5,3,6,5,4,3,9,6,8,2,1,7,4,7,2,1,9,3,6,5,8,9,3,5,2,8,6,4,7,1,6,1,8,4,5,7,9,2,3};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 8:{
    		int sudoku[ROW][COL]={9,2,4,3,1,7,5,6,8,5,6,7,9,8,2,4,1,3,1,8,3,5,6,4,7,9,2,6,5,2,1,7,3,9,8,4,4,7,8,6,5,9,3,2,1,3,1,9,4,2,8,6,7,5,8,3,6,7,4,1,2,5,9,7,9,1,2,3,5,8,4,6,2,4,5,8,9,6,1,3,7};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 9:{
    		int sudoku[ROW][COL]={7,4,6,8,1,2,5,9,3,5,3,2,6,7,9,4,8,1,8,1,9,5,4,3,2,6,7,9,5,7,1,3,6,8,4,2,6,8,3,2,5,4,7,1,9,4,2,1,7,9,8,3,5,6,2,7,4,9,8,1,6,3,5,3,9,5,4,6,7,1,2,8,1,6,8,3,2,5,9,7,4};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 10:{
    		int sudoku[ROW][COL]={8,4,7,2,3,9,1,6,5,3,5,6,8,1,7,4,9,2,1,2,9,5,4,6,3,8,7,4,6,3,7,5,8,9,2,1,9,8,1,4,2,3,7,5,6,2,7,5,6,9,1,8,4,3,5,3,4,1,8,2,6,7,9,6,1,2,9,7,4,5,3,8,7,9,8,3,6,5,2,1,4};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 11:{
    		int sudoku[ROW][COL]={4,5,2,3,8,9,6,1,7,3,1,7,2,5,6,9,4,8,6,9,8,4,1,7,5,3,2,1,8,4,5,7,3,2,6,9,2,7,9,1,6,4,3,8,5,5,6,3,8,9,2,4,7,1,8,3,1,9,4,5,7,2,6,7,2,5,6,3,1,8,9,4,9,4,6,7,2,8,1,5,3};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 12:{
    		int sudoku[ROW][COL]={7,3,4,2,8,1,5,6,9,1,5,6,9,7,4,2,8,3,8,2,9,5,6,3,1,4,7,3,9,5,1,4,6,7,2,8,4,6,8,7,2,9,3,5,1,2,7,1,3,5,8,6,9,4,9,8,7,6,3,5,4,1,2,6,4,2,8,1,7,9,3,5,5,1,3,4,9,2,8,7,6};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 13:{
    		int sudoku[ROW][COL]={1,2,4,5,8,6,7,9,3,9,7,6,3,1,4,8,2,5,8,5,3,2,7,9,4,1,6,5,3,9,6,4,8,1,7,2,6,8,1,7,9,2,3,5,4,2,4,7,1,3,5,6,8,9,4,9,5,8,6,7,2,3,1,3,6,8,9,2,1,5,4,7,7,1,2,4,5,3,9,6,8};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 14:{
    		int sudoku[ROW][COL]={9,8,4,1,5,6,2,7,3,6,7,1,2,3,9,5,4,8,3,5,2,8,7,4,9,1,6,1,9,7,3,2,8,4,6,5,4,3,8,9,6,5,7,2,1,5,2,6,7,4,1,3,8,9,7,4,5,6,1,3,8,9,2,8,1,3,4,9,2,6,5,7,2,6,9,5,8,7,1,3,4};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 15:{
    		int sudoku[ROW][COL]={5,2,3,8,1,6,7,9,4,4,6,7,9,3,5,2,1,8,8,1,9,2,7,4,6,3,5,2,9,8,1,6,7,5,4,3,3,7,5,4,8,9,1,2,6,6,4,1,5,2,3,9,8,7,7,5,2,3,9,8,4,6,1,1,3,4,6,5,2,8,7,9,9,8,6,7,4,1,3,5,2};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 16:{
    		int sudoku[ROW][COL]={2,1,7,8,6,5,3,4,9,8,3,9,1,7,4,5,2,6,5,4,6,2,3,9,7,1,8,9,5,4,7,2,3,6,8,1,3,2,1,5,8,6,4,9,7,6,7,8,4,9,1,2,3,5,4,8,5,6,1,2,9,7,3,7,6,3,9,4,8,1,5,2,1,9,2,3,5,7,8,6,4};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 17:{
    	   	int sudoku[ROW][COL]={1,4,7,6,3,8,5,9,2,6,8,5,7,2,9,3,4,1,9,2,3,4,1,5,8,7,6,4,1,2,5,8,6,7,3,9,3,7,8,1,9,2,4,6,5,5,6,9,3,4,7,2,1,8,2,9,1,8,7,4,6,5,3,8,5,4,9,6,3,1,2,7,7,3,6,2,5,1,9,8,4};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 18:{
    		int sudoku[ROW][COL]={9,5,8,6,4,7,2,3,1,1,7,4,2,5,3,6,9,8,3,2,6,9,1,8,5,7,4,4,8,3,1,7,6,9,2,5,2,1,5,3,8,9,4,6,7,6,9,7,4,2,5,1,8,3,8,4,2,7,6,1,3,5,9,5,3,1,8,9,2,7,4,6,7,6,9,5,3,4,8,1,2};
			for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 19:{
    		int sudoku[ROW][COL]={8,3,9,5,6,7,1,4,2,4,5,7,8,1,2,3,6,9,1,6,2,4,9,3,7,8,5,3,8,6,7,2,1,9,5,4,9,1,5,6,4,8,2,7,3,7,2,4,3,5,9,8,1,6,2,4,8,1,3,5,6,9,7,6,9,1,2,7,4,5,3,8,5,7,3,9,8,6,4,2,1};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
    	case 20:{
    		int sudoku[ROW][COL]={3,7,5,2,8,6,1,9,4,4,6,2,1,5,9,8,7,3,8,9,1,7,3,4,6,5,2,9,8,4,5,1,2,3,6,7,5,3,7,6,9,8,4,2,1,2,1,6,3,4,7,5,8,9,6,4,8,9,7,3,2,1,5,7,5,3,8,2,1,9,4,6,1,2,9,4,6,5,7,3,8};
    		for(i=0;i<ROW;i++){
		        for(j=0;j<COL;j++)
		            sudoku2[i][j]=sudoku[i][j];
	        }
			break;
    	}
	}
    CreatePlay(sudoku2, play, holes);
    for(i=0; i<COL; i++){
    	for(j=0; j<ROW; j++){
    		player[i][j] = play[i][j];
		}
	}
	TranToCNF(play, holes, SudokuFile);
	return OK;
}
void CreatePlay(int a[][COL], int b[][COL], int numDigits)
{
    int i, j, k;
    srand((unsigned)time(NULL));
    for(i=0; i<ROW; i++)        //b先照搬     
        for(j=0; j<COL; j++)
            b[i][j] = a[i][j];
    int c[numDigits][2];        //用于存储已经被挖的坐标 
    int m, flag = 0;
    for(i=0; i<numDigits; i++){    //开始挖洞 
        j = rand() % 9;        //随机生成行列 
        k = rand() % 9;
        flag = 0;
        for(m=0; m<i; m++)     //检查该位置是否已被挖掉 
            if(j==c[m][0] && k==c[m][1])
                flag = 1;
        if(flag==0){
            b[j][k] = 0;
            c[i][0] = j;
            c[i][1] = k;
        }
        else i--;
    }
}
status TranToCNF(int a[][COL], int holes, char SudokuFile[])
{
	FILE *fp = fopen(SudokuFile, "w");
	if(!fp) exit(ERROR);
	fprintf(fp, "p cnf 729 %d\n", 6642+81-holes);
	int x, y, z;
	for(x=0; x<ROW; x++){    //确定的数:单子句 
		for(y=0; y<COL; y++){
			if(a[x][y]!=0){
				fprintf(fp, "%d 0\n", (x+1)*100 + (y+1)*10 + a[x][y]);
			}
		}
	} 
	for(x=1; x<=9; x++){    //填的数是1~9 
		for(y=1; y<=9; y++){
			for(z=1; z<=9; z++){
				fprintf(fp, "%d ", x*100 + y*10 + z);
			}
			fprintf(fp, "0\n");
		}
	}
	int i, j, k;
	for(y=1; y<=9; y++){    //行约束 
		for(z=1; z<=9; z++){
			for(x=1; x<=8; x++){
				for(i=x+1; i<=9; i++){
					fprintf(fp, "%d ", opp(x*100 + y*10 +z));
					fprintf(fp, "%d 0\n", opp(i*100 + y*10 + z));
				}
			}
		}
	}
	for(x=1; x<=9; x++){    //列约束 
		for(z=1; z<=9; z++){
			for(y=1; y<=8; y++){
				for(i=y+1; i<=9; i++){
					fprintf(fp, "%d ", opp(x*100 + y*10 +z));
					fprintf(fp, "%d 0\n", opp(x*100 + i*10 + z));
				}
			}
		}
	}
	for(z=1; z<=9; z++){    //3*3子网络中的列约束 
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
	for(z=1; z<=9; z++){    //3*3子网络中的行约束 
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
	for(i=1;i<9;i++){    //对角线约束其一 
		for(j=i+1;j<=9;j++){
			for(k=1;k<=9;k++)
				fprintf(fp,"-%d -%d 0\n",i*100+i*10+k,j*100+j*10+k);
		}
	}
	for(i=1;i<9;i++){    //对角线约束其二 
		for(j=i+1;j<=9;j++){
			for(k=1;k<=9;k++)
			    fprintf(fp,"-%d -%d 0\n",i*100+(10-i)*10+k,j*100+(10-j)*10+k);
		}
	}
	fclose(fp);
	return OK;
}
status EntrySUDOKU(CHead **C)
{
	int re, i;
	re = DPLLSolver(C);
	if(re==OK) return re;
	else return ERROR;
}
status SaveSudokuFile(int re, char filename[])
{
	int i, j, k, x;
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
	if(re==TRUE){        //数独有解 
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
	else{               //数独无解 
		fprintf(fp, "s 0\n");
	}
	fclose(fp);
	return OK;
}
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
