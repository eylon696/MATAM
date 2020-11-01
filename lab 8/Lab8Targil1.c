#include "Targil1.h"

int main()
{
	Stack s;
	int i;
	int del_val;
	int num[NUM] = { 1,2,3,4,5 };
	s.head = NULL;
	s.size = 0;
	for (i = 0; i < NUM; i++)  //filling the stack
	{
		if (NUM == s.size)
		{
			printf("The stack is full!");
			break;
		}
		Push(&s, num[i]);
	}
	while (Pop(&s, &del_val)==1)  //popping out from the stack
	{
		printf("The deleted value is: %d\n", del_val);
	}
	printf("The stack is now empty!");
	getch();
	return 0;
}