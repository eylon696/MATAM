#include"example1.h"

double sum_square(int m, int n, float(*f)(int a))
{
	double sum = 0;
	while (n >= m)//calculate the sum squre from n to m 
	{
		sum += pow(f(n), 2);
		n--;
	}
	return sum;
}