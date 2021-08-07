#include"seqlist.h"

//����һ���յ����Ա�
int initList(pSqlist L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L->date[i] = 0; //����Ԫ�س�ʼ��Ϊ0
	}
	L->length = 0;
	return OK;//
}

//�������Ա�
void destroyList(pSqlist L)
{
	if (L)
	{
		free(L);
	}
}

//������Ա�
void clearList(pSqlist L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L->date[i] = 0;
	}
	L->length = 0;
}

//�п�
_Bool listEmpty(pSqlist L) 
{
	if (0 == L->length)
	{ 
		printf("˳���Ϊ�ձ�");
		return true;
	}
	else {
		printf("˳����ǿձ�");
		return false;
	}
		
}

//���ر���Ԫ�ظ���
int listLength(pSqlist L)
{
	return L->length;
}

//��e���ر��е�i��Ԫ��
int getElem(pSqlist L, int i, ElemType*pElem)
{
	if (i<1||i>L->length)
	{
		printf("��������ȷ��λ��.\n");
		return ERROR;
	}
	else {
		*pElem = L->date[i - 1];
		return OK;
	}

}

//���ص�һ���봫��ֵ��ͬ��Ԫ�ص�λ��
int locateElem(pSqlist L, ElemType elem)
{

		for (int i = 0; i < L->length; i++)
		{
			if (elem == L->date[i])
			{
				return i + 1;
			}
		}
		return ERROR;
	
}

//��iλ�ò���һ��Ԫ��
void listInsert(pSqlist L, ElemType elem, int i)
{
	if (L->length < i || i < 1)
	{
		printf("��������ȷ��λ��");
		return ERROR;
	}
	if (L->length + 1 > MAXSIZE)
	{
		printf("�洢�ռ䲻��");
		return ERROR;
	}
		for (int j = L->length; j >=i; j--)
		{
			L->date[j] = L->date[j - 1];
		}
		L->date[i-1] = elem;
		L->length++;
		return OK;
}

//����λ��ɾ��һ��Ԫ��
void deletElem(pSqlist L, int i)
{
	if (listEmpty(L))
	{
		printf("The list is empty.Failed to delete.\n");
		return;
	}
	else {
		if (i <= L->length && i >= 1) 
		{
			for (int j = i; j < L->length; j++)
			{
				L->date[j-1] = L->date[j];
			}
			L->length--;
			printf("Successful deletion.\n");
		}
		else {
			printf("i is not in the scale.\n");
			return;
		}
	}
}

//������ӡ
int printList(pSqlist L)
{
	if (listEmpty(L))
	{
		printf("The list is empty.Failed to print.\n");
		return ERROR;
	}
	else
	{
		for (int j = 0; j < L->length; j++)
		{
			printf("%4d", L->date[j]);
		}
		printf("\n");
		return OK;
	}
}