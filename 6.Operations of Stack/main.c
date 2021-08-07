#include"stack.h"

void main(void)
{
	stack_t mystack;
	tag_t mystackTag;
	int stuNum;
	float stuScore;
	initialStack(&mystackTag);
	while (printf("input num and score:____\b\b"), rewind(stdout), scanf("%d%f", &stuNum, &stuScore) != EOF)
	{
		pushStack(&mystackTag, stuNum, stuScore);
	}
	printStack(&mystackTag);
	popStack(&mystackTag);
	printStack(&mystackTag);
	popStack(&mystackTag);
	printStack(&mystackTag);
	emptyStack(&mystackTag);
	

}
