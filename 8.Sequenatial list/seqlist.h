#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 10
#define OK 0
#define ERROR -1

typedef int ElemType;

typedef struct sqList {
	ElemType date[MAXSIZE];
	int length;
}Sqlist,*pSqlist;

//构造一个空的线性表
int initList(pSqlist);

//销毁线性表
void destroyList(pSqlist);

//清空线性表
void clearList(pSqlist);

//判空
_Bool listEmpty(pSqlist);

//返回表中元素个数
int listLength(pSqlist);

//用e返回表中第i个元素
int getElem(pSqlist, int, ElemType *);

//返回第一个与传入值相同的元素的位置
int locateElem(pSqlist, ElemType);

//插入一个元素
void listInsert( pSqlist, ElemType, int);

//根据位置删除一个元素
void deletElem(pSqlist, int);

//遍历打印
int printList(pSqlist);







