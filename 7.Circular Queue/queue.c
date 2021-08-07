#include"queue.h"

void initQueue(pQue initque)
{
	initque->front = 0;
	initque->rear = 0;
	memset(initque->date, 0, sizeof(int) * 5);

}

int isEmpty(pQue ifsize0)
{
	if (ifsize0->front == ifsize0->rear)
	{
		return 0;
	}
	else {
		return 1;
	}
}

void enQueue(pQue myque, int num)
{
	if ((myque->rear + 1) % Maxsize == myque->front)
	{
		printf("The queue is full.\n");
		return;
	}
	else {
		myque->date[myque->rear % Maxsize] = num;
		myque->rear = (myque->rear + 1) % Maxsize;//¼Ó1È¡Ä£
	}

}

void outQueue(pQue myque)
{
	if (0 == isEmpty(myque))
	{
		printf("The queue is empty.\n");
		return;
	}
	else {
		myque->date[myque->front] = 0;
		myque->front = (myque->front + 1) % Maxsize;
	}
}

void print(pQue myque)
{
	int i;
	for (i = 0; i < Maxsize; i++)
	{
		printf("%4d", myque->date[i]);
	}
	printf("\n");
}