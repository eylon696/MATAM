#include "Targil3.h"

//the function adding nodes to the tail of the linked list
void Enqueue(PQue Q, int new_elem)
{
	Item* temp;
	Q->size++;
	temp = (Item*)malloc(sizeof(Item));
	if (temp == NULL)
	{
		Dequeue(&Q,&new_elem);
		Err_Msg("Memory!");
	}
	temp->num = new_elem;
	temp->next = NULL;
	if (Q->head == NULL)  //in case the queue is empty
	{
		Q->head = temp;
		Q->tail = temp;
	}
	else  //in case the queue isn't empty
	{
		Q->tail->next = temp;
		Q->tail = temp;
	}
}

//the function deletes nodes from the head of the linked list
int Dequeue(PQue Q, int * del_value)
{
	Item* temp;
	if (Q->head != NULL)
	{
		*del_value = Q->head->num;
		temp = Q->head;
		Q->head = Q->head->next;
		free(temp);
		return 1;
	}
	return 0;
}

void Err_Msg(char *str)
{
	printf("%s\n", str);
	exit(1);
}