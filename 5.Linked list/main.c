#include"list.h"

void main(void)
{
	pstu pHead=NULL;
	pstu pTail = NULL;
	int storeNum = 0;
	float modifyScore = 0;
	while (scanf("%d", &storeNum) != EOF)
	{
		//listHeadInsert(&pHead, &pTail, storeNum);
		//listTailInsert(&pHead, &pTail, storeNum);
		listSort2Insert(&pHead, &pTail, storeNum);
	}
	listPrintScore(pHead);
	/*while (printf("Enter the number to be deleted:___\b\b"),rewind(stdout),scanf("%d", &storeNum) != EOF)
	{
		listDelet(&pHead, &pTail, storeNum);
		listPrintNum(pHead);
	}*/
	while (printf("Enter the number to be modified:___\b\b"), rewind(stdout), scanf("%d%f", &storeNum,&modifyScore) != EOF)
	{
		listPrintScore(pHead);
		listModify(pHead, storeNum, modifyScore);//error第一个参数传递了一个一级指针的地址
		listPrintScore(pHead);
	}


	system("pause");
}
