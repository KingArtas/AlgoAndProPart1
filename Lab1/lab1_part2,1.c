#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m, x;
	printf("Enter two numbers: \n");
	scanf("%d%d", &n, &m);
	x = n-- - m;
	printf("%d\n", x);
	printf("n = %d\n m = %d\n", n, m);
	getchar();
	getchar();
	return 0;
}