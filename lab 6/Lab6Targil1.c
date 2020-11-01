#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

#define N 5

//struction decleration
typedef struct Item
{
	int Code;
	char Name[11];
	struct Item *next;
}Item;

int main()
{
	int i;
	Item *Head = NULL, *temp;
	for (i = 1; i <= N; i++)  //creating nodes and scanning data to them
	{
		temp = (Item*)malloc(sizeof(Item));
		if (temp == NULL)
		{
			printf("Error! Memory Not Allocated");
			exit(1);
		}
		printf("Enter a new code and name: ");
		scanf("%d%s", &(temp->Code), temp->Name);
		printf("\n");
		temp->next = Head;
		Head = temp;
	}  //end loop
	printf("\n\nThe List is:  ");
	while (temp !=NULL)
	{
		printf("%d %s --> ", temp->Code, temp->Name);
		temp = temp->next;
	}
	while (Head!=NULL)  //loop to free all the nodes
	{
		temp = Head;
		Head = Head->next;
		free(temp);
	}  //end loop
	getch();
	return 0;
}