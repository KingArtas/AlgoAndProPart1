#include <stdio.h>
#include <math.h>

int main()
{
	float a = 1000, b = 0.0001;
	float c, e, f, g, h, i;
	e = pow(a - b, 3);
	f = pow(a, 3);
	g = 3 * a*pow(b, 2);
	h = pow(b, 3);
	i = 3 * (pow(a, 2))*b;
	c = (e - (f - g)) / (h - i);
	printf("%f \n", c);
	getchar();
	return 0;
}