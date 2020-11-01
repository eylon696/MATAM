#include"example1.h"
//Define general functions and structures

typedef struct node
{
	void* data;                        /* Store the keystroke by the user */
	struct node *next;                /* Pointer to the next node */
} STACKNODE;

//The function creates a linked list
void push(void * key, PSTACKNODE *stack)
{
	STACKNODE *newnode;
	newnode = (STACKNODE *)malloc(sizeof(STACKNODE));
	newnode->data = key;
	newnode->next = (*stack);
	(*stack) = newnode;
}
//The function return the data (void*) to the main
void * top(PSTACKNODE stack)
{
	return stack->data;
}
//The function free node from linked list
void pop(PSTACKNODE * stack, void(*free_data)(void*))
{
	STACKNODE *oldnode;
	oldnode = (*stack);
	(*stack) = (*stack)->next;
	free_data(oldnode->data);
	free(oldnode);
}
//The function check if the linked list is empty
int isempty(PSTACKNODE stack)
{
	return (stack == NULL);
}
