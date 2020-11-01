#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//structures definition
typedef struct Item
{
	int num;
	struct Item* next;
}Item;

typedef struct List
{
	int count;
	Item *head;
	Item *tail;
}List;

//function declerations
void Error_Msg(char*);
void AddAsFirst(Item*a, List*L);
void AddAsLast(Item*, List*);
void MoveToAnotherList(List* L, List* Posit, List* Negat);
void CreateList(List*, FILE *);
void PrintItem(Item*);
void PrintList(List*, char*);
void DeleteList(List* L);

int main()
{
	List L, Posit, Negat;
	FILE *in = fopen("ThreeLists.txt", "rt");
	if (in == NULL)
		Error_Msg("input file is wrong");
	L.head = NULL;
	L.tail = NULL;
	L.count = 0;

	Posit.head = NULL;
	Posit.tail = NULL;
	Posit.count = 0;

	Negat.head = NULL;
	Negat.tail = NULL;
	Negat.count = 0;

	CreateList(&L, in);
	PrintList(&L, "\nMy List:\n");
	MoveToAnotherList(&L, &Posit, &Negat);
	PrintList(&Posit, "\n\nThe Positive List:\n");
	PrintList(&Negat, "\n\nThe Negative List:\n\n");

	fclose(in);
	DeleteList(&Posit);
	DeleteList(&Negat);
	getch();
	return 0;
}


//the function represents that an error occured
void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}

//the function creates a linked list
void CreateList(List* L, FILE *f)
{
	int value;
	Item *temp;
	while (fscanf(f, "%d", &value) == 1)
	{
		temp = (Item*)malloc(sizeof(Item));
		if (temp == NULL)
		{
			DeleteList(L);
			Error_Msg("Memmory!");
		}
		temp->num = value;
		temp->next = NULL;
		if (L->head == NULL)
			L->head = temp;
		else
			L->tail->next = temp;
		L->tail = temp;
		L->count++;
	}
}

//the function prints one item
void PrintItem(Item* node)
{
	printf("%d--> ", node->num);
}

//the function prints the entire linked list
void PrintList(List* L, char* title)
{
	Item* temp = L->head;
	printf("%s", title);
	while (temp)
	{
		PrintItem(temp);
		temp = temp->next;
	}
	printf("\nThere are %d items in the list", L->count);
}

//the function adds a node to the head of the list
void AddAsFirst(Item* ptr, List* L)
{
	ptr->next = L->head;
	L->head = ptr;
	L->count++;
}

//the function adds a node to the tail of the list
void AddAsLast(Item* ptr, List* L)
{
	ptr->next = NULL;
	if (L->head == NULL)
		L->head = ptr;
	else
		L->tail->next = ptr;
	L->tail = ptr;
	L->count++;
}

//the function deletes the linked list
void DeleteList(List* L)
{
	Item *temp;
	while (L->head != NULL)
	{
		temp = L->head;
		L->head = L->head->next;
		free(temp);
	}
}

//the function creates new lists accordingly
void MoveToAnotherList(List*L, List*Posit, List*Negat)
{
	Item *temp;
	while (L->head != NULL)
	{		
		temp = L->head;
		L->head = L->head->next; 
		if (temp->num >= 0)
			AddAsLast(temp, Posit);
		else
			AddAsFirst(temp, Negat);
	}
	L->count = 0;
	L->tail = NULL;
}