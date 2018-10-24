#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>


int main()
{
	for(double x = 0.1; x <= 1.0; x += 0.1)
	{
		double summa1 = 1.0, summa2 = 1.0;
		double el1 = 1.0, el2 = 1.0;
		double y = (exp(x) + exp(-x)) / 2.0;
		double m = 2.0;


		for(double n = 2.0; n <= 10.0; n += 1.0)
		{
			el1 = el1 * ((x * x) / n);
			summa1 = summa1 + el1;
		}
		
		while(el2 > 0.0001)
		{
			el2 = el2 * ((x * x) / m);
			summa2 = summa2 + el2;
			m = m + 1.0;
		}

		printf("X = %f SN = %f SE = %f Y = %f\n", x, summa1, summa2, y);
	}

	_getch();
	return 0;
}
