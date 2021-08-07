//输入5个字符串数据(每个不超过10个字符)，使用冒泡法比较字符串大小排序

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5

void inputTips(void)
{
	printf("请输入%d个字符串数据:\n", N);
}

void printNewString(char** ppstringDate)
{
	for (int row = 0; row < N; row++)
	{
		printf("%s\n", ppstringDate[row]);
	}
}

void printOldString(char(*stringDate)[10])
{
	for (int row = 0; row < N; row++)
	{
		printf("%s\n", stringDate[row]);
	}
}
void main(void)
{
	char stringDate[N][10] = { 0 };
	int count = 0;
	char* pstringDate[5] = { 0 };
	char* Switch;
	char** ppstringDate;
	inputTips();
	while (count < N&& fgets(stringDate[count], 10, stdin) != NULL)
	{
		pstringDate[count] = stringDate[count];//未排除换行键
		count++;
	}
	ppstringDate = pstringDate;

	for (int i = 4; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (strcmp(ppstringDate[j + 1], ppstringDate[j]) == 1)//pstringDate[]也可
			{
				Switch = ppstringDate[j];
				ppstringDate[j] = ppstringDate[j + 1];
				ppstringDate[j + 1] = Switch;
			}

		}
	}
	printNewString(ppstringDate);
	printOldString(stringDate);
}
