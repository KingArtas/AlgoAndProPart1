#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;
	printf("Enter two numbers: \n");
	scanf("%d%d", &n, &m);
	if (n++ > m) {
		printf("%d > %d", n, m);
	}
	else {
		printf("Values don't satisfy the condition of inequality\n");
	}
	getchar();
	getchar();
	return 0;
}