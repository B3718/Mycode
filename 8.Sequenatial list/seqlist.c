#include"seqlist.h"

//构造一个空的线性表
int initList(pSqlist L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L->date[i] = 0; //数组元素初始化为0
	}
	L->length = 0;
	return OK;//
}

//销毁线性表
void destroyList(pSqlist L)
{
	if (L)
	{
		free(L);
	}
}

//清空线性表
void clearList(pSqlist L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L->date[i] = 0;
	}
	L->length = 0;
}

//判空
_Bool listEmpty(pSqlist L) 
{
	if (0 == L->length)
	{ 
		printf("顺序表为空表");
		return true;
	}
	else {
		printf("顺序表不是空表");
		return false;
	}
		
}

//返回表中元素个数
int listLength(pSqlist L)
{
	return L->length;
}

//用e返回表中第i个元素
int getElem(pSqlist L, int i, ElemType*pElem)
{
	if (i<1||i>L->length)
	{
		printf("请输入正确的位序.\n");
		return ERROR;
	}
	else {
		*pElem = L->date[i - 1];
		return OK;
	}

}

//返回第一个与传入值相同的元素的位置
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

//在i位置插入一个元素
void listInsert(pSqlist L, ElemType elem, int i)
{
	if (L->length < i || i < 1)
	{
		printf("请输入正确的位序");
		return ERROR;
	}
	if (L->length + 1 > MAXSIZE)
	{
		printf("存储空间不足");
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

//根据位置删除一个元素
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

//遍历打印
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