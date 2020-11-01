#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//define structure
typedef struct Person
{
	char ID[10];
	char F_name[11];
	char L_name[16];
	int Age;
	char Addr[51];
}Person;

void Error_Msg(char*);

int main()
{
	Person temp;
	FILE *in, *out;
	in = fopen("the_first.txt", "rt");//open file for read "the_first.txt"
	if (in == NULL)//check if the open was successful
	{
		Error_Msg("Error in opening input file");/* Handle case where couldn't open file. */
	}
	out = fopen("the_second.txt", "wt");//open file for write "the_second.txt"
	if (out == NULL)//check if the open was successful
	{
		Error_Msg("Error in opening output file");/* Handle case where couldn't open file. */
	}
	fscanf(in, "%s %s %s %d %s", (temp.ID), (temp.F_name), (temp.L_name), &(temp.Age), (temp.Addr));//scan for variables from "the_first.txt"
	fprintf(out, "ID:%s\nFull name:%s %s\nAge:%d\nAddress:%s\n", (temp.ID), (temp.F_name), (temp.L_name), (temp.Age), (temp.Addr));//print variables to "the_second.txt"
	fclose(in);
	fclose(out);
	getch();
	return 0;
}
void Error_Msg(char* msg)
{
	printf("error\n%s", msg);
	exit(1);
}