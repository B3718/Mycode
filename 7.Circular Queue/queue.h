#include<stdio.h>
#include<stdlib.h>
#define Maxsize 5
typedef struct queue {
	int date[Maxsize];
	int front;
	int rear;
}que,*pQue;

void initQueue(pQue);

int isEmpty(pQue);

void enQueue(pQue,int);

void outQueue(pQue);

void print(pQue);




