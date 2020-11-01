#ifndef example1
#define example1

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

//PSTACKNODE is pointer to struct (node)
typedef struct node *PSTACKNODE;

//Functions declaration
void push(void *, PSTACKNODE *stack);
void pop(PSTACKNODE * stack, void(*free_data)(void*));
int isempty(PSTACKNODE stack);
void* top(PSTACKNODE stack);


#endif // !example1

