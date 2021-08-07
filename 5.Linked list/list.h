#include<stdio.h>
#include<stdlib.h>

typedef struct student {
	int num;
	struct student* pNext;
	float score;
}stu,*pstu;

void listHeadInsert(pstu* xpphead, pstu* xpptail, int xnum);

void listTailInsert(pstu* xpphead, pstu* xpptail, int xnum);

void listSortInsert(pstu* xpphead, pstu* xpptail, int xnum);

void listSort2Insert(pstu* xpphead, pstu* xpptail, int xnum);

void listDelet(pstu* xpphead, pstu* xpptail, int delNum);

void listPrintNum(pstu pPrint);

void listPrintScore(pstu pPrint);

void listModify(pstu phead, int num, float modifyscore);