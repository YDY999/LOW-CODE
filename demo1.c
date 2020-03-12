#include<stdio.h>

int main(void)
{
	printf("第一次修改");
	int a = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 6 == 0)
			a += i;
	}
	printf("%d\n",a);
	return 0;
}
