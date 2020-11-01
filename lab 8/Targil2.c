#include "Targil2.h"

//the function initializing the stack
void InitStack(PStack s, int size)
{
	s->Array = (int*)malloc(sizeof(int)*size);
	if (s->Array == NULL)
		Err_Msg("Memory");
	s->size = size;
	s->count = 0;
	s->top = -1;
}

//add a new member to the array
void Push(PStack s, int   new_elem)
{
	if (s->count < s->size)
	{
		s->top++;
		s->count++;
		s->Array[s->top] = new_elem;
	}
	else
		printf("\nThe Stack is full");
}

//delete member from the array and return the deleted value  using  int * del_value
int Pop(PStack s, int * del_value)
{
	*del_value = 0;
	if (s->count > 0)
	{
		*del_value = s->Array[s->top];
		s->top--;
		s->count--;
	}
	else
		printf("The Stack is empty\n");
	return *del_value;
}

void Err_Msg(char *str)
{
	printf("%s\n", str);
	exit(1);
}