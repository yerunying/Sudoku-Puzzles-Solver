//@Global.h
#ifndef WORKSHOP_GLOBAL_H
#define WORKSHOP_GLOBAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1 
#define MAXN 1200
#define COL 9 
#define ROW 9
#define AC 0
#define WA -1

typedef int ElemType;
typedef int status;

typedef struct CNode{    //一个单纯的链表(记录一个结点) 
      ElemType data;
      struct CNode *next;
}CNode, *PNode;

typedef struct CHead{    //链表的链表(记录一个子句) 
	ElemType info; 
	struct CHead *down;
	struct CNode *right;
}CHead, *PHead;

typedef struct times{
	double count;
	ElemType data;
	double positive;
	double negative;
	ElemType value; 
}times;

times counter[MAXN];
int player[ROW][COL];

void test(CHead **C);
int opp(int x);

CHead* IniClause(CHead **C);
CNode* IniNode(CNode **right);
status FileReader(CHead **C, char filename[]);

status SaveSATFile(int re, double t, char filename[]);
status SaveSudokuFile(int re, char filename[]);

CHead* isUniClause(CHead *C);
status isEmptyClause(CHead *C);

status DPLLSolver(CHead **C);
CHead* Duplication(CHead **C);
int strategy2(CHead **C);
int strategy1(CHead **C);

status EntrySUDOKU(CHead **C);
int EntrySAT(char FileName[]);
void CreatePlay(int a[][COL], int b[][COL], int numDigits);
status CreateSudokuToFile(char SudokuFile[], int holes);
status TranToCNF(int a[][COL], int holes, char SudokuFile[]);
void print(int a[][COL]);

#endif
