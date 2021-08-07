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

//����һ���յ����Ա�
int initList(pSqlist);

//�������Ա�
void destroyList(pSqlist);

//������Ա�
void clearList(pSqlist);

//�п�
_Bool listEmpty(pSqlist);

//���ر���Ԫ�ظ���
int listLength(pSqlist);

//��e���ر��е�i��Ԫ��
int getElem(pSqlist, int, ElemType *);

//���ص�һ���봫��ֵ��ͬ��Ԫ�ص�λ��
int locateElem(pSqlist, ElemType);

//����һ��Ԫ��
void listInsert( pSqlist, ElemType, int);

//����λ��ɾ��һ��Ԫ��
void deletElem(pSqlist, int);

//������ӡ
int printList(pSqlist);







