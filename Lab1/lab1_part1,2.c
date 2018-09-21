#include <stdio.h>
#include <math.h>

int main()
{
	double a = 1000, b = 0.0001;
	double c, e, f, g, h, i; //add intermediate variables
	e = pow(a - b, 3);
	f = pow(a, 3);
	g = 3 * a*pow(b, 2);
	h = pow(b, 3);
	i = 3 * (pow(a, 2))*b;
	c = (e - (f - g)) / (h - i);
	printf("%.10f \n", c); //I use ".10" before f in order to avoid rounding off
	getchar(); //add "getchar()" to make a console delay
	return 0;
}