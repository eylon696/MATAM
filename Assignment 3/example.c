#include "example.h"

//structures definition
typedef struct SET
{
	struct node *head;
	struct node *tail;
	int size;  //the number of nodes in the set
	//pointers to specific functions
	int(*isequal)(void*, void*);
	int(*isgreater)(void*, void*);
	void(*print)(void*);
	void(*delete)(void*);
}SET;

typedef struct node
{
	void *data;
	struct node *next;
	struct node *prev;
}node;

//the function frees set
void FreeSet(PSET s)
{
	free(s);
}

//the function initializing the PSET at first
void Init(PSET* s, int(*isequal)(void*, void*), int(*isgreater)(void*, void*), void(*print)(void*), void(*delete)(void*))
{
	(*s) = (PSET)malloc(sizeof(SET));
	if ((*s) == NULL)
		Err_Msg("Memory!");
	(*s)->head = NULL;
	(*s)->tail = NULL;
	(*s)->size = 0;
	(*s)->isequal = isequal;
	(*s)->isgreater = isgreater;
	(*s)->print = print;
	(*s)->delete = delete;
}

//the function creates a linked list
void createSet(void* variable, PSET* s)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	if (temp == NULL)
	{
		(*s)->delete((*s)->head);
		FreeSet(s);
		Err_Msg("Memory!");
	}
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = variable;
	(*s)->size++;
	if ((*s)->head == NULL)
	{
		(*s)->head = temp;
		(*s)->tail = temp;
	}
	else
	{
		(*s)->tail->next = temp;
		temp->prev = (*s)->tail;
		(*s)->tail = temp;
	}
}

//the function closes the program in case not enough memory was allocated
void Err_Msg(char*s)
{
	printf("%s", s);
	exit(1);
}

//the function adds new element to and exsistant node
void addToSet(PSET* s, void *Element)
{
	int i = 0;
	node* temp = (*s)->head;
	while((i < (*s)->size) && (temp!=NULL))
	{
		if ((*s)->isequal(Element, temp->data))  //checks if Element is in the set
		{
			printf("The data already exsits int the SET!\n");
			break;
		}
		temp = temp->next;
		i++;
	}
	if (i == (*s)->size)  //in case the data isn't already in the set
	{
		createSet(Element, s);
		printf("The data has been added to the set!\n");
	}
	else if (temp == NULL)  //in case the set is empty
	{
		createSet(Element, s);
		printf("The data has been added to the set!\n");
	}
}

//the function deletes a node from the linked list
BOOL deleteFromSet(PSET* s, void* Element)
{
	int i;
	node *temp = (*s)->head;
	if (temp == NULL)
		return FALSE;
	for (i = 0; i < (*s)->size; i++)
	{
		if ((*s)->isequal(Element, temp->data))  //checks if Element is equal to temp->data
		{
			if (temp->prev == NULL)
			{
				(*s)->head = (*s)->head->next;
				(*s)->head->prev = NULL;
				(*s)->delete(temp->data);
				free(temp);
			}
			else if (temp->next == NULL)
			{
				(*s)->tail = (*s)->tail->prev;
				(*s)->tail->next = NULL;
				(*s)->delete(temp->data);
				free(temp);
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				(*s)->delete(temp->data);
				free(temp);
			}
			(*s)->size--;
			return TRUE;
		}
		temp = temp->next;
	}
	return FALSE;
}

//the function checks if the data appears in the set
BOOL findInSet(PSET* s, void* Element)
{
	int i;
	node* temp = (*s)->head;
	if (temp == NULL)
		return FALSE;
	for (i = 0; i < (*s)->size; i++)
	{
		if ((*s)->isequal(Element, temp->data))  //checks if Element is equal to temp->data
			return TRUE;
		temp = temp->next;
	}
	return FALSE;
}

//the function checks how many nodes are in the linked list
int setSize(PSET* s)
{
	return (*s)->size;
}

//the function checks which data is max
void *findMax(PSET* s)
{
	int i;
	void* Max;
	node* temp = (*s)->head;
	if (temp == NULL)
	{
		Max = NULL;
		return Max;
	}
	Max = temp->data;
	for (i = 0; i < (*s)->size; i++)
	{
		if (((*s)->isgreater)(Max, temp->data))  //checks if Max is greater than temp->data
			Max = temp->data;
		temp = temp->next;
	}
	return Max;
}

//the function checks which data is min
void *findMin(PSET* s)
{
	int i;
	void* Min;
	node* temp = (*s)->head;
	if (temp == NULL)
	{
		Min = NULL;
		return Min;
	}
	Min = temp->data;
	for (i = 0; i < (*s)->size; i++)
	{
		if (!((*s)->isgreater)(Min, temp->data))  //checks if Min is lower than temp->data
			Min = temp->data;
		temp = temp->next;
	}
	return Min;
}

//the function deletes the entire linked list
void deleteSet(PSET *s)
{
	node* temp;
	while ((*s)->head != NULL)
	{
		temp = (*s)->head;
		(*s)->head = (*s)->head->next;
		(*s)->delete(temp->data);  //delete node
		free(temp);
		(*s)->size--;
	}
}

//the function prints the entire set
void PrintAll(PSET *s)
{
	node* temp = (*s)->head;
	if (temp == NULL)
		printf("The set is empty!");
	else while (temp != NULL)
	{
		(*s)->print(temp->data);  //prints the data
		temp = temp->next;
	}
	printf("\n");
}

//the function prints the menu to the user
void PrintMenu()
{
	printf("Choose a number from the following functions:\n");
	printf("1. Add data to the set.\n");
	printf("2. Delete data from the set.\n");
	printf("3. Search for data in the set.\n");
	printf("4. Check the size of the set.\n");
	printf("5. Find the maximum data.\n");
	printf("6. Find the minimum data.\n");
	printf("7. Delete the set.\n");
	printf("8. Print the set.\n");
	printf("9. Exit the menu.\n");
}