#ifndef Targil3
#define Targil3

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//structures definition
typedef struct Item {
	int num;
	struct Item* next;
}Item;

typedef struct Que {
	Item* head, *tail;
	int size;      //a current number of items
}Queue, *PQue;

//functions declaration
void Enqueue(PQue Q, int   new_elem);   //add a new member to list of the queue 
int Dequeue(PQue Q, int * del_value);     //delete member from the queue and  return the deleted value  using int *del_value
void Err_Msg(char *str);

#define NUM 5


#endif