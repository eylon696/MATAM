#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct stud//structure definition, student type (name,mark,average)
{
	char *name;
	int marks[4];
	float avg;
}student;

/*functions declaration*/
student* Create_Class(int size);
void Print_One(student *s);
void Avg_Mark(student *s);

int main()
{
	int size, i;
	student *arr;
	printf("\nEnter the number of students:");
	scanf("%d", &size);
	arr=Create_Class(size);
	for (i = 0; i < size; i++)
	{
		if (arr[i].avg > 85)//a loop that checks whether the student average is greater than to 85 if it is sent to print else goes on
			Print_One(&arr[i]);
	}
	for (i = 0; i < size; i++)//loop which frees the allocation of space
		free(arr[i].name);
	free(arr);
	getch();
	return 0;
}
void Print_One(student* s)//a function that prints the student name and average marks
{
	printf("\nThe average of %s is %.1f\n",s->name, s->avg );
}

void Avg_Mark(student* s)//A function that calculates the student average marks
{
	int i;
	float sum=0;
	 for (i = 0; i < 4; i++)
		 sum += s->marks[i];
	 s->avg = (sum / 4.0);
}
student* Create_Class(int size)//a function which inserts values into an array of structures according to the struct 'student'
{
	char temp[50];
	int i, j;
	student* arr;
	arr = (student *)malloc(sizeof(student)*size);//dynamic memory allocation 
	if (arr == NULL)//check if the memory allocation was successful 
	{
		printf("Error! memory not allocated.");
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		printf("\nEnter your name:");
		scanf("%s", temp);
		arr[i].name = (char*)malloc(strlen(temp) + 1);
			if (arr[i].name == NULL)//check if the memory allocation was successful 
			{
				printf("Error! memory not allocated.");
				exit(0);
			}
		strcpy(arr[i].name,temp);
		printf("\nEnter your marks:");
		for (j = 0; j < 4; j++)
			scanf("%d", &arr[i].marks[j]);
		Avg_Mark(&arr[i]);
	}
	return arr;
}


