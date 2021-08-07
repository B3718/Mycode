#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	int a, b, c, max = 0;
	int ret;
	while (rewind(stdin), (ret = scanf("%d%d%d", &a, &b, &c)) != EOF)
	{
		printf("正确匹配的字符个数为ret=%d\n", ret);
		max = (a > b ? a: b) > c ? (a > b ? a: b): c;
		printf("max=%d\n", max);

	}
}
