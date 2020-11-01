#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//define structure
typedef struct
{
	char name[20];
	int grades[3];
}student;
//declertion function
void Error_Msg(char*);
int InputData(student **, FILE*);
void OutputData(int, student*, FILE*);

int main()
{
	FILE *fp;
	student * arr;
	int size;
	if (!(fp = fopen("Students.txt", "rt")))//open and check the file for read "Students.txt"
		Error_Msg("The input file is wrong");
	size = InputData(&arr, fp);
	fclose(fp);
	if (!(fp = fopen("Students.txt", "wt")))//open and check the file for write "Students.txt"
		Error_Msg("The output file is wrong");
	OutputData(size, arr, fp);
	fclose(fp);
	free(arr);
	getch();
	return 0;
}
int InputData(student ** p_array, FILE * fp)//the function scan and build array of structures from type of student* and return the number of students
{
	student *arr;
	int i = 1;
	arr = (student*)malloc(sizeof(student));
	if (arr == NULL)
	{
		printf("Erorr! memory not allocated");
		exit(0);
	}
	while (fscanf(fp, "%s %d %d %d", arr[i - 1].name, &arr[i - 1].grades[0], &arr[i - 1].grades[1], &arr[i - 1].grades[2]) != EOF)
	{
		arr = (student*)realloc(arr, sizeof(student)*(i+1));
		if (arr == NULL)
		{
			printf("Erorr! memory not allocated");
			exit(0);
		}
		i++;
	}
	*p_array = arr;//p_array is pointer to the array in the main
	return  i - 1;    /*return the number of students*/
}
void OutputData(int arr_size, student *arr, FILE* fp)//the function print to the file the max grade of each student
{
	int i,max,j;
	for (i = 0; i < arr_size; i++)
	{
		max = arr[i].grades[0];
		for (j = 1; j < 3; j++)
		{
			if (arr[i].grades[j] > max)
				max = arr[i].grades[j];
		}
		fprintf(fp, "name:%s max-grade:%d\n", arr[i].name, max);
	}
}
void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}