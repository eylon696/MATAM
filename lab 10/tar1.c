#include"example1.h"
//Define specific functions

//The function free char 
void free_char(void *elem)
{
	free(elem);
}

int main()
{
	PSTACKNODE stack = NULL;
	char key;
	char *ch;
	puts("Enter characters, separated by space. Press enter to stop\n");
	do//A do while loop that scan characters until the user insert enter
	{
		ch = (char*)malloc(sizeof(char));//Creates a specific address for each variable that is scan from the user
		key = getchar();
		*ch = key;
		_flushall();
		push(ch, &stack);
	} while (key != '\n');

	puts("Here are the characters in reverse order:\n");

	while (!isempty(stack))//A loop that prints data from a linked list as long as the list is not empty
	{
		printf(" %c ", *(char*)top(stack));
		pop(&stack,free_char);
	}

	getch();
	return 0;
}