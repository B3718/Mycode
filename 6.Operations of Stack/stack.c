#include"stack.h"

void initialStack(pTag_t ptag)
{
	ptag->pHead = NULL;
	ptag->size = 0;
}

void pushStack(pTag_t ptag, int num, float score)
{
	pStack_t pNew = (pStack_t)calloc(1, sizeof(stack_t));
	pNew->num = num;
	pNew->score = score;
	pNew->pNext = ptag->pHead;
	ptag->pHead = pNew;
	ptag->size++;
}

void popStack(pTag_t ptag)
{
	//µ¯Õ»Ç°ÅÐ¶ÏÊÇ·ñÎª¿Õ
	if (0 == ptag->size)
	{
		printf("The stack is empty.\n");
		return;
	}
	else {
		pStack_t pCur = ptag->pHead;
		ptag->pHead = pCur->pNext;
		free(pCur);
		pCur = NULL;
		ptag->size--;
	}
}


int sizeStack(pTag_t ptag)
{
	return ptag->size;
}

int topStackNum(pTag_t ptag)
{
	return ptag->pHead->num;
}

float topStackScore(pTag_t ptag)
{
	return ptag->pHead->score;
}

void emptyStack(pTag_t ptag)
{
	if (0 == sizeStack(ptag))
	{
		printf("The stack is empty.\n");
	}
	else {
		printf("The stack num is %d", sizeStack(ptag));
	}
}

void printStack(pTag_t ptag)
{
	pStack_t pcurStack = ptag->pHead;
	while (pcurStack) 
	{
		printf("%5d %5.2f\n", pcurStack->num, pcurStack->score);
		pcurStack = pcurStack->pNext;
	}
}