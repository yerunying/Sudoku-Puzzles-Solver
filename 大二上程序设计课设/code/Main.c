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
	    printf("       ���������ѡ��[0~2]:");
	    scanf("%d", &op);
	    switch(op){
	    	case 1:                                                          
	    		printf("�������ļ���:\n");
	    		scanf("%s", FileName);                                        
	    		if((pd=EntrySAT(FileName))==OK){                             
	    			printf("�ɹ�!������Ӧ�ļ��в鿴!\n\n");
	    			printf("�밴�س����ص����˵�!\n");
				}
				else{
					printf("unsatisfy!\n\n");
	    			printf("�밴�س����ص����˵�!\n");
				}
	    		getchar();getchar();
				break;
			case 2:
				printf("�������ڶ���:\n");                                  
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
			    printf(" ���������ѡ��[0~1]:");
			    scanf("%d", &op);
			    while(op && op!=3){
			    	switch(op){
				    	case 1:
				    		re = EntrySUDOKU(&C);                            
				    		pd = SaveSudokuFile(re, SudokuFileName);         
				    		if(pd==OK){
								printf("������д�ɹ�!������ļ��鿴!\n\n");
								printf("�밴�س����ص����˵�!\n");
							}
							else{
								printf("�����������޽�!\n");
							}
							getchar();getchar();
							system("cls");
							printf("\n");
							printf("       Welcome to My System!\n");
	                        printf("   -------------------------------\n");
	                        printf("       1. Sat        2. Sudoku\n");
	                        printf("       0. Exit\n");
	                        printf("   -------------------------------\n");
	                        printf("       ���������ѡ��[0~2]:");
						    scanf("%d", &op);
							getchar();
							break;
						case 0:
							break;
						default:
							printf("����Ƿ�!�밴�س�������ѡ��!\n");
							getchar();getchar();
							break;
					}//end of switch(interior)
				}//end of while(interior)
			case 0:
				break;
			default:
				printf("����Ƿ�!�밴�س�������ѡ��!\n");
				getchar();getchar();
				break;
		}//end of switch
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ!\n");
    return 0;
}//end of main
