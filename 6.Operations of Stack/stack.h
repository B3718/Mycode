#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int num;
	float score;
	struct stack* pNext;
}stack_t,*pStack_t;

typedef struct tagStack {
	pStack_t pHead;
	int size;
}tag_t,*pTag_t;

void initialStack(pTag_t);

void pushStack(pTag_t,int,float);

void popStack(pTag_t);


int sizeStack(pTag_t);

void emptyStack(pTag_t);

int topStackNum(pTag_t);

float topStackScore(pTag_t);

void printStack(pTag_t);

