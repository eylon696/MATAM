#include "example1.h"
//Define general functions and structures

typedef struct  ListNode
{
	void* data;
	struct  ListNode *next;
} ListNode;

//The function creates a linked list
BOOL insertEntry(PNode* head, PNode* tail, void *data, compare_func func)
{
	PNode temp=*head;
	while ((temp) != NULL)//A loop that checks that the information is not already in the linked list
	{
		if (func(temp->data, data) == TRUE)
			return FALSE;
		temp = temp->next;
	}
	temp = (PNode)malloc(sizeof(ListNode));//Create a node for information not in the linked list
	if (temp == NULL)//Check if the allocation was successful
	{
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		*tail = temp;
	}
	else
	{
			(*tail)->next = temp;
			(*tail) = temp;
	}
	return TRUE;
}
//A function that deletes a node from the linked list according to a given data from the user
BOOL deleteNode(PNode* head, PNode* tail, void *todel, compare_func func1, free_func func2)
{
	PNode temp = *head;
	PNode helper;
	if (*head == NULL)
		return FALSE;
	if(func1(todel,(*head)->data)==TRUE)
	{
		*head = (*head)->next;
		func2(temp->data);
		free(temp);
	}
	else
	{
		while (temp != NULL&&temp->next != NULL)
		{
			if (func1(todel, temp->next->data) == TRUE)
			{
				helper = temp->next;
				temp->next = temp->next->next;
				func2(helper->data);
				free(helper);
				return TRUE;
			}
			temp = temp->next;
		}
	}
	return FALSE;
}
//A function that deletes the entire linked list
void freeAll(PNode* head, free_func func)
{
	PNode temp;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		func(temp->data);
		free(temp);
	}
}
//General function for printing
void printAll(PNode head, print_func func)
{
	PNode temp = head;
	while (temp!=NULL)
	{
		func(temp->data);
		temp = temp->next;
	}
}