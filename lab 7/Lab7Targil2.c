#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define N 5

//structer definition
typedef struct Item
{
	int num;
	struct Item* next;
}*PItem;

//functions declaration
void Error_Msg(char*);
void CreateListFromArray(PItem*, PItem*, int *);
void DeleteList(PItem *);
void ListDisplay(PItem list);
int ListLength(PItem list);

int main()
{
	int Arr[N] = { 3,4,1,0,8 };

	PItem list = NULL, tail = NULL;

	CreateListFromArray(&list, &tail, Arr);
	printf("The length of the list is %d members\n", ListLength(list));
	printf("\nThe list is:\n");
	ListDisplay(list);

	DeleteList(&list);
	tail = NULL;
	getch();
	return 0;
}

void Error_Msg(char*msg)
{
	printf("\n%s", msg);
	exit(1);
}

//the function builds a linked list from the array
void CreateListFromArray(PItem* head, PItem* tail, int *Arr)
{
	int i;
	PItem temp;
	for (i = 0; i<N; i++)
	{
		temp = (PItem)malloc(sizeof(struct Item));
		if (temp == NULL)
		{
			DeleteList(head);
			Error_Msg("Memmory!");
		}
		temp->num = Arr[i];
		temp->next = NULL;
		if (*head == NULL)
			*head = temp;
		else
			(*tail)->next = temp;
		*tail = temp;
	}
}

//the function deletes all the linked list's nodes
void DeleteList(PItem *head)
{
	PItem tmp = *head;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

//the recursive function returns the number of nodes in the list 
int ListLength(PItem list)
{
	if (list == NULL)
		return 0;
	return
		ListLength(list->next) + 1;
}

//the recursive function prints the linked list
void ListDisplay(PItem list)
{
	if (list != NULL)
	{
		printf("%d  ", list->num);
		ListDisplay(list->next);
	}
}