#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DATA_LEN 23

//structure definition
typedef struct Student
{
	char CourseName[4];
	char ID[5];
	char FullName[17];
}Student;

//function decleration
void Get_Lost(char *);
void Sort(FILE *);
void ScanTwoStudents(Student*stud1, Student*stud2, FILE* file);
void PrintToFile(Student*stud1, Student*stud2, FILE* file);

int main()
{
	FILE *file;
	file = fopen("Stud.txt", "r+");
	if (file == NULL)  //check if the open was successful
		Get_Lost("The input file is wrong");  //Handle case where couldn't open file.
	Sort(file);
	fclose(file);
	getch();
	return 0;
}

void Get_Lost(char *s)
{
	puts(s);
	exit(1);
}

void Sort(FILE *file)
{
	int i, j;
	Student stud1, stud2;
	int numOfStudents;
	char *tempID;
	fseek(file, 0, SEEK_END);
	numOfStudents = (ftell(file)) / DATA_LEN;  //checking how many students are in the file
	fseek(file, 0, SEEK_SET);
	for (j = 0; j < numOfStudents; j++)  //loop that runs numOfStudents times
	{
		for (i = 0; i < numOfStudents - j - 1; i++)  //loop to print to the file the maximum Student ID on the right
		{
			ScanTwoStudents(&stud1, &stud2, file);
			if (strcmp(stud1.ID, stud2.ID) > 0)  //checking which ID is greater
			{
				fseek(file, (-2)*DATA_LEN, SEEK_CUR);
				PrintToFile(&stud2, &stud1, file);
			}
			fseek(file, (-1)*DATA_LEN, SEEK_CUR);
		}  //end loop
		fseek(file, 0, SEEK_SET);
	}  //end loop

}

//the function scanning from the file the data of 2 students
void ScanTwoStudents(Student*stud1, Student*stud2, FILE* file)
{
	fgets(stud1->CourseName, 4, file);
	fgets(stud1->ID, 5, file);
	fgets(stud1->FullName, 17, file);
	fgets(stud2->CourseName, 4, file);
	fgets(stud2->ID, 5, file);
	fgets(stud2->FullName, 17, file);
}

//the function prints the data of to students to the file
void PrintToFile(Student*stud1, Student*stud2, FILE* file)
{
	fprintf(file, "%s%s%s", stud1->CourseName, stud1->ID, stud1->FullName);
	fprintf(file, "%s%s%s", stud2->CourseName, stud2->ID, stud2->FullName);
}