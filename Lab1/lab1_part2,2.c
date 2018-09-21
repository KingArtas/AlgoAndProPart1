#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;
	printf("Enter two numbers: \n");
	scanf("%d%d", &m, &n);
	if (m-- < n) {
		printf("%d < %d", m, n);
	}
	else {
		printf("Values don't satisfy the condition of inequality\n");
	}
	getchar();
	getchar();
	return 0;
}