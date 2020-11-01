#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdio.h>
//define structures
#define MAX 256
typedef struct Book
{
	char code[10];
	char *name;
}Book;
typedef struct Library
{
	char name[MAX];
	int num_books;
	Book *books;
}Library;

//declertion function
void Get_Lost(char* str);
void input_book(Book* B, FILE *in);
void input_library(Library *L, FILE *in);
void output_book(Book* B, FILE *out);
void output_library(Library* L, FILE *out);

int main()
{
	FILE *in, *out;
	Library Libr;
	int i;

	in = fopen("input.txt", "rt");//open file for read "input.txt"
	if (in == NULL)//check if the open was successful
	{
		Get_Lost("Error faiile didn't open");//Handle case where couldn't open file. 
	}
	input_library(&Libr, in);
	fclose(in);
	out = fopen("output.txt", "wt");//open file for write "output.txt"
	if (out == NULL)//check if the open was successful
	{
		Get_Lost("Error faiile didn't open");//Handle case where couldn't open file. 
	}
	output_library(&Libr, out);
	fclose(out);
	for (i = 0; i < Libr.num_books; i++)
		free(Libr.books[i].name);
	free(Libr.books);

	getch();
	return 0;
}
void Get_Lost(char* str)
{
	printf("\n%s", str);
	exit(1);
}
void input_library(Library *L, FILE *in)//scan data from file"input.txt" to srtucture Library Libr
{
	int i;
	fscanf(in, "%s %d", L->name, &L->num_books);
	L->books = (Book*)malloc(sizeof(Book)*(L->num_books));
	if (L->books == NULL)
	{
		printf("Error! memory not Allocated");
		exit(1);
	}
	for (i = 0; i < L->num_books; i++)
	{
		input_book(&L->books[i], in);
	}
}
void input_book(Book* B, FILE *in)////scan data from file"input.txt" to srtucture Book code and name of book
{
	char  temp[MAX];
	fscanf(in, "%s %s", B->code, temp);
	B->name = (char*)malloc(strlen(temp) + 1);
	if (B->name == NULL)
	{
		printf("Error! memory not Allocated");
		exit(1);
	}
	strcpy(B->name, temp);
}
void output_library(Library* L, FILE *out)//print from Library Libr to "output.txt" file
{
	int i;
	fprintf(out, "%s\n", L->name);
	for (i = 0; i < L->num_books; i++)
		output_book(&L->books[i], out);
}
void output_book(Book* B, FILE *out)
{
	fprintf(out, "%-10s %s\n", B->code, B->name);
}

















/*
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
*/