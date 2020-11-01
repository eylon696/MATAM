#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 4

typedef struct Complex//structure definition, complex numbers type (x+yi)
{
	float real, img;
}Complex;

//declertion functions
float CRadius(Complex);
void Error_Msg(char* str);
void InputAndWriteToFile(FILE *f);
int CheckFile(FILE *f, float m);

int main()
{
	FILE *f;
	if (!(f = fopen("complex_numbers.txt", "wt")))//open and check the file for write "complex_numbers.txt"
		Error_Msg("The output file is wrong");
	InputAndWriteToFile(f);
	fclose(f);
	if (!(f = fopen("complex_numbers.txt", "rt")))//open and check the file for read "complex_numbers.txt"
		Error_Msg("The output file is wrong");
	printf("\nThere are %d big numbers\n", CheckFile(f, 4));
	fclose(f);
	getch();
	return 0;
}
void Error_Msg(char* str)
{
	printf("\n%s", str);
	exit(1);
}
float CRadius(Complex a)//a function that calculates the size of the radius
{
	float radius;
	radius = sqrt(pow(a.real, 2) + pow(a.img, 2));
	return radius;
}
void InputAndWriteToFile(FILE *f)//the function scan from the user complex numbers, calculate the radius of each complex number and print to the file
{
	int i;
	Complex arr[N];
	printf("Enter 4 complex numbers\n");
	for(i=0;i<N;i++)
	{
		scanf("%f %f", &arr[i].real, &arr[i].img);
		fprintf(f, "%.1f %.1f %.1f\n", arr[i].real, arr[i].img,CRadius(arr[i]));
	}
}
int CheckFile(FILE *f, float m)//the function checks how many radiuses are bigger then m and returns the number
{
	int count = 0, i;
	float temp;
	for (i = 0; i < N; i++)
	{
		fscanf(f, "%f %f %f", &temp,&temp,&temp);
		if ( temp > m)
			count++; 
	}
	return count;
}
