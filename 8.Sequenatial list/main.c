#include"seqlist.h"

void main(void)
{
	Sqlist list;
	pSqlist pList = &list;
	ElemType e;
	int a;
	int m = 0;
	int i = 0;

	initList(pList);

	while (scanf("%d", &a) != EOF)
	{
		if (pList->length < MAXSIZE)
		{
			pList->date[pList->length] = a;
			pList->length++;
		}
		else {
			break;
		}

	}
	a = listLength(pList);
	getElem(pList, 4, &e);
	i = locateElem(pList, 5);
	deletElem(pList, 2);
	listInsert(pList, 23, 1);
	printList(pList);
	clearList(pList);
	printList(pList);

}
