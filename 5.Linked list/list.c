#include"list.h"

void listHeadInsert(pstu* xpphead, pstu* xpptail, int xnum)
{
	pstu pNew = (pstu)calloc(1, sizeof(stu));
	pNew->num = xnum;
	if (NULL == *xpphead)
	{
		*xpphead = pNew;
		*xpptail = pNew;
		//pNew->pNext = NULL;//calloc���ʼ��ΪNULL,���Բ���д������malloc�����Լ���ʼ������Ҫ��memset��
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
		//pNew->pNext = NULL;//calloc���ʼ��ΪNULL,���Բ���д������malloc�����Լ���ʼ������Ҫ��memset��
	}
	else {
		(*xpptail)->pNext = pNew;
		*xpptail = pNew;
		//pNew->pNext = NULL;//calloc���ʼ��ΪNULL,���Բ���д������malloc�����Լ���ʼ������Ҫ��memset��
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
	else if(pNew->num<=(*xpphead)->num){//�޸ķ��Ÿı�����˳��ͷ�巨
		pNew->pNext = *xpphead;
		*xpphead = pNew;
	}
	else if (pNew->num >= (*xpptail)->num) {//�޸ķ��Ÿı�����˳��β�巨
		(*xpptail)->pNext = pNew;
		*xpptail = pNew;
	}
	else {
		pCur = (*xpphead)->pNext;
		pPre = *xpphead;
		while (pNew->num >= pCur->num)//�޸ķ��Ÿı�����˳���м����
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
	if (NULL == pCur)//�ж������Ƿ�Ϊ��
	{
		*xpphead = pNew;
		*xpptail = pNew;
	}
	else if (xnum < pCur->num)//ͷ�巨���޸ķ��Ÿı�����˳��
	{
		pNew->pNext = pCur;
		*xpphead = pNew;
	}
	else {
		while (pCur)//���뵽�м�
		{
			
			if (pCur->num > xnum)//�޸ķ��Ÿı�����˳��
			{
				pPre->pNext = pNew;
				pNew->pNext = pCur;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		if (NULL == pCur)//���뵽β��,����Ҫ�ж����ֵĴ�С���޸ĳɴ�С����������ӷ���
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
	//�ж������Ƿ�Ϊ��
	if (NULL == pCur)
	{
		printf("This list is empty.\n");
		return;
	}
	//ɾ��ͷ�ڵ�
	else if (delNum == pCur->num) {
		*xpphead = pCur->pNext;
		//����պ�ɾ�������Ҫ��ͷβָ��NULL��ȷ���´β�����ȷ����ʼ©д��
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
				//�򻯴���
				pPre->pNext = pCur->pNext;
				if (*xpptail == pCur)
				{
					*xpptail = pPre;
				}
				break;
				////ɾ���м���
				//if (pCur != *xpptail)
				//{
				//	pPre->pNext = pCur->pNext;
				//	break;
				//}
				////ɾ��β���
				//else {
				//	pPre->pNext = NULL;
				//	*xpptail = pPre;
				//	break;
				//}
			}
			pPre = pCur;
			pCur = pCur->pNext;
		}
		//Ҫɾ����ֵ������
		if (NULL == pCur)
		{
			printf("The value to be deleted does not exist in this list.\n");
			return;
		}
	}
	//�ͷű�ɾ�����Ķѿռ�
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