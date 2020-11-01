#ifndef Targil1
#define Targil1

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//structures definition
typedef struct Item {
	int num;
	struct Item* next;
}Item;

typedef struct Stack {
	Item* head;
	int size;         //a current number of items
}Stack, *PStack;

//functions declaration
void Push(PStack s, int   new_elem);    //add a new member to list of the stack
int Pop(PStack s, int * del_value);       //delete member from the stack and  return the deleted value  using  int * del_value
void Err_Msg(char *str);

#define NUM 5


#endif