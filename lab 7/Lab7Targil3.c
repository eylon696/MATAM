#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//structure declaration
typedef struct Item
{
	int num;
	float price;
	struct Item* next;
}*PItem;

//functions definition
void Error_Msg(char*);
void AddNewItem(PItem *head, PItem *tail, int place, int a, float b);
void CreateList(PItem *, PItem *, FILE *);
void PrintItem(PItem);
void PrintList(PItem, char*);
void WriteListToFile(PItem head, FILE *in);
void DeleteList(PItem *);

int main()
{
	int a, place;
	float b;
	PItem head = NULL, tail = NULL;
	FILE *in = fopen("input_price.txt", "rt");
	if (in == NULL)
		Error_Msg("input file is wrong");
	CreateList(&head, &tail, in);
	PrintList(head, "\nThe Old List:\n");
	printf("\n\nEnter a number and the price\n");
	scanf("%d%f", &a, &b);
	printf("\nEnter a place for the new item:");
	scanf("%d", &place);
	AddNewItem(&head, &tail, place, a, b);
	PrintList(head, "\nThe New List:\n");
	fclose(in);
	in = fopen("input_price.txt", "wt");
	if (in == NULL)
		Error_Msg("input file is wrong");
	WriteListToFile(head, in);
	DeleteList(&head);
	tail = NULL;
	fclose(in);
	getch();
	return 0;
}

//the function represents that an error occured
void Error_Msg(char*msg)
{
	printf("\n%s", msg);
	exit(1);
}

//the function creates a linked list
void CreateList(PItem *head, PItem *tail, FILE *f)
{
	int a;
	float b;
	PItem temp;
	while (fscanf(f, "%d %f", &a, &b) == 2)
	{
		temp = (PItem)malloc(sizeof(struct Item));
		if (temp == NULL)
		{
			DeleteList(head);
			Error_Msg("Memmory!");
		}
		temp->num = a;
		temp->price = b;
		temp->next = NULL;
		if (*head == NULL)
			*head = temp;
		else
			(*tail)->next = temp;
		*tail = temp;
	}
}

//the function prints one item
void PrintItem(PItem node)
{
	printf("%d,%.1f-->", node->num, node->price);
}

//the function prints the entire linked list
void PrintList(PItem head, char* title)
{
	printf("%s", title);
	while (head)
	{
		PrintItem(head);
		head = head->next;
	}
}

//the function deletes the linked list
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

//the function puts the new item in it's right place
void AddNewItem(PItem *head, PItem *tail, int place, int a, float b)
{
	int i = 1;
	int counter = 0;
	PItem ptr = *head;
	PItem temp;
	temp = (PItem)malloc(sizeof(struct Item));
	if (temp == NULL)
		Error_Msg("Memory!");
	temp->num = a;
	temp->price = b;
	while (ptr != NULL)  //the loop counts how many nodes are in the list
	{
		counter++;
		ptr = ptr->next;
	}
	ptr = *head;
	if (place > counter)  //in case the new location is greater than the amount of nodes
	{
		(*tail)->next = temp;
		*tail = temp;
		(*tail)->next = NULL;
	}
	else if (place == 1)  //in case the new item needs to be added first
	{
		temp->next = *head;
		*head = temp;
	}
	else  //in case the new item needs to be added in the middle of the list
	{
		while (ptr != NULL)
		{
			if (i == place-1)
				break;
			ptr = ptr->next;
			i++;
		}
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

//the function prints to the file the new linked list
void WriteListToFile(PItem head, FILE *in)
{
	while (head != NULL)
	{
		fprintf(in, "%d %.1f ", head->num, head->price);
		head = head->next;
	}
}