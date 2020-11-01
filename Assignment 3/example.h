#ifndef example
#define example

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct SET* PSET;
typedef struct node* pnode;

typedef enum {FALSE,TRUE} BOOL;

void FreeSet(PSET s);
void Init(PSET* s, int(*isequal)(void*, void*), int(*isgreater)(void*, void*), void(*print)(void*), void(*delete)(void*));
void createSet(void* variable, PSET* s);
void Err_Msg(char*s);
void addToSet(PSET* s, void *Element);
BOOL deleteFromSet(PSET* s, void* Element);
BOOL findInSet(PSET* s, void* Element);
int setSize(PSET* s);
void *findMax(PSET* s);
void *findMin(PSET* s);
void deleteSet(PSET* s);
void PrintAll(PSET* s);
void PrintMenu();


#endif // !example.c