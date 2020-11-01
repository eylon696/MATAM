#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//struct define
typedef struct Student
{
	char name[7], division[5];
	char grade1[4], grade2[4];
}Student;

//function declerations
void Error_Msg(char* str);
void CopyData(FILE*in, FILE*out);

int main()
{
	FILE *in, *out;
	if (!(in = fopen("Students.txt", "r")))  //opens and checks the openning of Students.txt for read
		Error_Msg("The input file is wrong");
	if (!(out = fopen("StudentsNew.txt", "w")))  //opens and checks the openning of StudentsNew.txt for write
		Error_Msg("The output file is wrong");
	CopyData(in, out);
	fclose(in);
	fclose(out);
	getch();
	return 0;
}


void Error_Msg(char* str)
{
	printf("\n%s", str);
	exit(1);
}

//the function copy the relevant data to the the new file
void CopyData(FILE*in, FILE*out)  
{
	Student stud;
	int grade1, grade2;
	float avg;
	while (fgets(stud.name, 7, in) != NULL)
	{
		fgets(stud.division, 5, in);
		fgets(stud.grade1, 4, in);
		fgets(stud.grade2, 4, in);
		if (!strcmp("Comp", stud.division))  //comparing "Comp" to the division
		{
			grade1 = atoi(stud.grade1);
			grade2 = atoi(stud.grade2);
			avg = (grade1 + grade2) / 2.0;
			fprintf(out, "%-7s %.2f\n", stud.name, avg);
		}
	}
}