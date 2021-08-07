#include<stdio.h>
#include<stdlib.h>

void print(int(*p)[4], int row)
{
	int i ;
	int j ;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < sizeof(*p) / sizeof(int); j++)
		{
			printf("%4d", p[i][j]);
		}
		printf("\n");
	}
}
void main(void)
{
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int (*p)[4];
	p = a;
	print(p, 3);

}
