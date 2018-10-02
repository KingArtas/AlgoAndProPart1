#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> 
#include <ctype.h>

int main()
{
	float e = 0.0001;
	float a, summa = 0;
	int n = 1;

	a = (n / 10.0);

	while (a > e)
	{
		summa += a;
		a *= n / 10.0;
		n++;
	}

	printf("%f\n", summa);

	_getch();
	return 0;
}