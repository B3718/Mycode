#include"queue.h"

void main(void)
{
	que myQueue;
	initQueue(&myQueue);
	print(&myQueue);
	enQueue(&myQueue,1);
	print(&myQueue);
	enQueue(&myQueue, 2);
	print(&myQueue);
	enQueue(&myQueue, 3);
	print(&myQueue);
	enQueue(&myQueue, 4);
	print(&myQueue);
	enQueue(&myQueue, 5);
	print(&myQueue);
	outQueue(&myQueue);
	print(&myQueue);
	outQueue(&myQueue);
	print(&myQueue);
	outQueue(&myQueue);
	print(&myQueue);
	outQueue(&myQueue);
	print(&myQueue);
	outQueue(&myQueue);
	print(&myQueue);
	outQueue(&myQueue);
	print(&myQueue);
    
}
