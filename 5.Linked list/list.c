#include"list.h"

void listHeadInsert(pstu* xpphead, pstu* xpptail, int xnum)
{
	pstu pNew = (pstu)calloc(1, sizeof(stu));
	pNew->num = xnum;
	if (NULL == *xpphead)
	{
		*xpphead = pNew;
		*xpptail = pNew;
		//pNew->pNext = NULL;//calloc会初始化为NULL,可以不用写。但是malloc不会自己初始化，需要加memset！
	}
	else {
		pNew->pNext=*xpphead ;
		*xpphead = pNew;
	}
}

void listTailInsert(pstu* xpphead, pstu* xpptail, int xnum)
{
	pstu pNew = (pstu)calloc(1, sizeof(stu));
	pNew->num = xnum;
	if (NULL == *xpptail)
	{
		*xpphead = pNew;
		*xpptail = pNew;
		//pNew->pNext = NULL;//calloc会初始化为NULL,可以不用写。但是malloc不会自己初始化，需要加memset！
	}
	else {
		(*xpptail)->pNext = pNew;
		*xpptail = pNew;
		//pNew->pNext = NULL;//calloc会初始化为NULL,可以不用写。但是malloc不会自己初始化，需要加memset！
	}
	}

void listSortInsert(pstu* xpphead, pstu* xpptail, int xnum)
{
	pstu pCur, pPre;
	pstu pNew = (pstu)calloc(1, sizeof(stu));
	pNew->num = xnum;
	if (NULL == *xpptail)
	{
		*xpphead = pNew;
		*xpptail = pNew;
	}
	else if(pNew->num<=(*xpphead)->num){//修改符号改变排序顺序；头插法
		pNew->pNext = *xpphead;
		*xpphead = pNew;
	}
	else if (pNew->num >= (*xpptail)->num) {//修改符号改变排序顺序；尾插法
		(*xpptail)->pNext = pNew;
		*xpptail = pNew;
	}
	else {
		pCur = (*xpphead)->pNext;
		pPre = *xpphead;
		while (pNew->num >= pCur->num)//修改符号改变排序顺序；中间插入
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
		pPre->pNext = pNew;
		pNew->pNext = pCur;
		
	}
	
}

void listSort2Insert(pstu* xpphead, pstu* xpptail, int xnum)
{
	pstu pCur=*xpphead, pPre=*xpphead;
	pstu pNew = (pstu)calloc(1, sizeof(stu));
	pNew->num = xnum;
	if (NULL == pCur)//判断链表是否为空
	{
		*xpphead = pNew;
		*xpptail = pNew;
	}
	else if (xnum < pCur->num)//头插法；修改符号改变排序顺序
	{
		pNew->pNext = pCur;
		*xpphead = pNew;
	}
	else {
		while (pCur)//插入到中间
		{
			
			if (pCur->num > xnum)//修改符号改变排序顺序
			{
				pPre->pNext = pNew;
				pNew->pNext = pCur;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		if (NULL == pCur)//插入到尾部,不需要判断数字的大小。修改成从小到大排序更加方便
		{
			pPre->pNext = pNew;
			*xpptail = pNew;
		}
	}
	
}

void listDelet(pstu* xpphead, pstu* xpptail, int delNum)
{
	pstu pPre = *xpphead;
	pstu pCur = *xpphead;
	//判断链表是否为空
	if (NULL == pCur)
	{
		printf("This list is empty.\n");
		return;
	}
	//删除头节点
	else if (delNum == pCur->num) {
		*xpphead = pCur->pNext;
		//如果刚好删除表格，需要将头尾指针NULL，确保下次插入正确。开始漏写了
		if (NULL == *xpphead)
		{
			*xpptail = NULL;
		}
	}
	else {
		while (pCur)
		{
			if (delNum == pCur->num)
			{
				//简化代码
				pPre->pNext = pCur->pNext;
				if (*xpptail == pCur)
				{
					*xpptail = pPre;
				}
				break;
				////删除中间结点
				//if (pCur != *xpptail)
				//{
				//	pPre->pNext = pCur->pNext;
				//	break;
				//}
				////删除尾结点
				//else {
				//	pPre->pNext = NULL;
				//	*xpptail = pPre;
				//	break;
				//}
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		//要删除的值不存在
		if (NULL == pCur)
		{
			printf("The value to be deleted does not exist in this list.\n");
			return;
		}
	}
	//释放被删除结点的堆空间
	free(pCur);
	pCur = NULL;
}

void listPrintNum(pstu pPrint)
{
	while (NULL != pPrint)
	{
		printf("%5d", pPrint->num);
		pPrint = pPrint->pNext;
	}
	printf("\n");
}

void listPrintScore(pstu pPrint)
{
	while (NULL != pPrint)
	{
		printf("%5d %5.2f\n", pPrint->num,pPrint->score);
		pPrint = pPrint->pNext;
	}

}

void listModify(pstu phead, int num, float score)
{
	while (phead)
	{
		if (num == phead->num)
		{
			phead->score = score;
		}
		phead = phead->pNext;
	}
	if (NULL == phead)
	{
		printf("The score to be modified is't exist.\n");
	}

}