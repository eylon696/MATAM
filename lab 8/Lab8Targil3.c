#include "Targil3.h"

int main()
{
	Queue Q;
	int i;
	int del_val;
	int num[NUM] = { 1,2,3,4,5 };
	Q.head = NULL;
	Q.tail = NULL;
	Q.size = 0;
	for (i = 0; i < NUM; i++)  //filling the queue
	{
		if (Q.size == NUM)
		{
			printf("The queue is full!\n");
			break;
		}
		Enqueue(&Q, num[i]);  //popping out from the queue
	}
	while (Dequeue(&Q, &del_val) == 1)
	{
		printf("The deleted value is: %d\n", del_val);
	}
	printf("The queue is now empty!");
	getch();
	return 0;
}