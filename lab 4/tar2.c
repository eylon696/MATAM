#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//define structure
typedef struct Student
{
	char courseName[4];
	char ID[5];
	char Fullname[17];
}Student;
//declertion function
void Get_Lost(char *);
void Find(FILE *file, char *course);

int main()
{
	char course[4];
	FILE *file;
	file = fopen("Stud.txt", "rt");//open file for read "Stud.txt"
	if (file == NULL)//check if the open was successful
		Get_Lost("Cannot open file");//Handle case where couldn't open file.
	printf("\nEnter the name of course,up to 3 letters");
	scanf("%s", course);
	Find(file, course);
	fclose(file);
	getch();
	return 0;
}
void Find(FILE *file, char *course)
{
	char txtname[8],fullname[17];
	Student temp;
	int binaryID;
	FILE *fp;
	strcpy(txtname, course);//copy the name of course to textname
	strcat(txtname, ".txt");//add ".txt" to the end string textname
	fp = fopen(txtname,"wt");//open a new file called textname
	if (fp == NULL)//check if the open was successful
		Get_Lost("Cannot open file");//Handle case where couldn't open file.
	while (!feof(file))//loop for scanning data and compering the name of course in the file to what the user printed
	{
		fgets(temp.courseName,4,file);
		fgets(temp.ID,5,file);
		fgets(temp.Fullname,17,file);
		strcpy(fullname, temp.Fullname);
		if (!(strcmp(temp.courseName,course)))
		{
			binaryID = atoi(temp.ID);
			itoa(binaryID, temp.ID, 2);//converting the id to binary number
			fprintf(fp, "%s, %s, %s\n", temp.ID, fullname,temp.courseName );//print the data to the file
		}
	}
	fclose(fp);
}
void Get_Lost(char* str)
{
	printf("\n%s", str);
	exit(1);
}