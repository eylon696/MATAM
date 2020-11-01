#include "example1.h"
//Define specific functions

//The function checks if two chars are equal
BOOL cmp_char(void*a, void*b)
{
	if (*(char*)a == *(char*)b)
		return TRUE;
	return FALSE;
}
//The function free char 
void free_char(void* ch)
{
	free(ch);
}
//The function print char
void prnt_char(void* ch)
{
	printf("%c ", *(char*)ch);
}

int main()
{
	char ch, *temp;
	int n, i;
	BOOL res;
	PNode head = NULL, tail = NULL;//Initialization to head and tail

	printf("Enter number of characters ");
	scanf("%d", &n);
	printf("\nEnter %d characters,separated by enter", n);
	for (i = 0; i<n; i++)
	{
		temp = (char*)malloc(sizeof(char));//Creates a specific address for each variable that is scan from the user
		if (NULL == temp)//Check if the allocation was successful
		{
			printf("\nCan't allocate data memory");
			freeAll(&head, free_char);//Free the linked list
			return 1;
		}
		scanf(" %c", temp);
		res = insertEntry(&head, &tail, temp, cmp_char);
		if (FALSE == res)  /* if FALSE==res than there is something wrong with malloc */
		{
			printf("\nCan't allocate node memory or data is allready exists");
			freeAll(&head, free_char);
			return 1;
		}
	}
	printAll(head, prnt_char);//Print the linked list

	printf("\nEnter an element for deleting");
	scanf(" %c", &ch);
	res = deleteNode(&head, &tail, &ch, cmp_char, free_char);
	if (FALSE == res)
		printf("%c don't exists in list\n", ch);

	printAll(head, prnt_char);//Print the linked list

	freeAll(&head, free_char);//Free the linked list
	printf("\nYour list was destroyed\n");

	getch();
	return 0;
}