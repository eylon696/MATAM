#include "Targil1.h"

//add a new member to list of the stack
void Push(PStack s, int   new_elem)
{
	Item *temp;
	s->size++;  //counting how many nodes in the linked list
	temp = (Item*)malloc(sizeof(Item));
	if (temp == NULL)
	{
		Pop(s, &new_elem);
		Err_Msg("Memory!");
	}
	temp->num = new_elem;  //initializing the new node
	temp->next = s->head;  //linking
	s->head = temp;  //linking
}

//delete member from the stack and  return the deleted value  using  int * del_value
int Pop(PStack s, int * del_value)
{
	Item* temp;
	if (s->head != NULL)  //delete the node
	{
		*del_value = s->head->num;
		temp = s->head;
		s->head = s->head->next;
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