#include"example1.h"


float func1(int x)
{
	return (1.0 / x);
}

float func2(int x)
{
	return (x / 5.0);
}

int main()
{
	printf("The sum of func2: %.5lf\n", sum_square(2, 13,func2));
	printf("The sum of func1: %.5lf\n ", sum_square(1, 10000,func1));

	getch();
	return 0;
}


