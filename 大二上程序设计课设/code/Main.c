//@main.c
#include "Global.h"
int main()
{
    int op = 1, choice = 1;                                                         
	int holes = 0;                                                                   
    int pd, re, uni = 111, flag = 1, flagg = 1, flag2 = 1, i, j, k;                 
    PHead C = NULL, temp1 = NULL, temp2 = NULL;                                     
    char FileName[200];
    char SudokuFileName[200] = "su.txt";
    while(op){                                                               
    	system("cls");                                                        
	    printf("\n\n");
	    printf("       Welcome to My System!\n");
	    printf("   -------------------------------\n");
	    printf("       1. Sat        2. Sudoku\n");
	    printf("       0. Exit\n");
	    printf("   -------------------------------\n");
	    printf("       请输入你的选择[0~2]:");
	    scanf("%d", &op);
	    switch(op){
	    	case 1:                                                          
	    		printf("请输入文件名:\n");
	    		scanf("%s", FileName);                                        
	    		if((pd=EntrySAT(FileName))==OK){                             
	    			printf("成功!请进入对应文件中查看!\n\n");
	    			printf("请按回车键回到主菜单!\n");
				}
				else{
					printf("unsatisfy!\n\n");
	    			printf("请按回车键回到主菜单!\n");
				}
	    		getchar();getchar();
				break;
			case 2:
				printf("请输入挖洞数:\n");                                  
				scanf("%d", &holes);                                        
				for(i=0; i<COL; i++){         
					for(j=0; j<ROW; j++){
						player[i][j] = 0;
					}
				}
				CreateSudokuToFile(SudokuFileName, holes);                  
				FileReader(&C, SudokuFileName);                              
				system("cls");
				print(player);                                               
				printf("\n\n");                                              
				printf("        Welcome to My Sudoku!\n");          
			    printf(" -------------------------------------\n");
			    printf(" |   1. Answer     |   0. Exit       |\n");
			    printf(" -------------------------------------\n");
			    printf(" 请输入你的选择[0~1]:");
			    scanf("%d", &op);
			    while(op && op!=3){
			    	switch(op){
				    	case 1:
				    		re = EntrySUDOKU(&C);                            
				    		pd = SaveSudokuFile(re, SudokuFileName);         
				    		if(pd==OK){
								printf("数独填写成功!请进入文件查看!\n\n");
								printf("请按回车键回到主菜单!\n");
							}
							else{
								printf("该数独棋盘无解!\n");
							}
							getchar();getchar();
							system("cls");
							printf("\n");
							printf("       Welcome to My System!\n");
	                        printf("   -------------------------------\n");
	                        printf("       1. Sat        2. Sudoku\n");
	                        printf("       0. Exit\n");
	                        printf("   -------------------------------\n");
	                        printf("       请输入你的选择[0~2]:");
						    scanf("%d", &op);
							getchar();
							break;
						case 0:
							break;
						default:
							printf("输入非法!请按回车键重新选择!\n");
							getchar();getchar();
							break;
					}//end of switch(interior)
				}//end of while(interior)
			case 0:
				break;
			default:
				printf("输入非法!请按回车键重新选择!\n");
				getchar();getchar();
				break;
		}//end of switch
    }//end of while
    printf("欢迎下次再使用本系统!\n");
    return 0;
}//end of main
