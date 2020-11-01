#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define NUM 3//Quantity of complex numbers
typedef struct Complex//structure definition, complex numbers type (x+yi)
{
	float real, img;
}Complex;
/*functions declaration*/
float CRadius(Complex a);
float* Cmax(Complex ar[]);
int main()
{
	int i;
	Complex *p;
	printf("Enter 3 complex numbers:\n");
	Complex *ar;
	ar = (Complex*)malloc(sizeof(Complex)*NUM);//dynamic memory allocation
	if (ar == NULL)//check if the memory allocation was successful 
	{
		printf("Error! memory not allocated.");
		exit(0);
	}
	for (i = 0; i < NUM; i++)
	{
		scanf("%f %f", &ar[i].real, &ar[i].img);
	}
	p = Cmax(ar);
	printf("the max complex number is %.2f+%.2fi\n", p->real, p->img);
	printf("the radius of the max number is %.2f\n", CRadius(*p));
	free(ar);//free the allocation of space
	getch();
	return 0;
}
float CRadius( Complex a)//a function that calculates the size of the radius
{
	float radius;
	radius = sqrt(pow(a.real, 2) + pow(a.img, 2));
	return radius;
}
float* Cmax(Complex ar[])//a function that checks the largest complex number according to the radius
{
	int i,max_index;
	float max_radius = 0;
	for (i = 0; i < NUM; i++)
	{
		if (CRadius(ar[i]) > max_radius)
		{
			max_radius = CRadius(ar[i]);
			max_index = i;
		}
	}
	return &ar[max_index];
}