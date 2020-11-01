#ifndef example2
#define example2

#include<stdio.h>
#include<conio.h>

#define N 5

//Function declaration
int Do_It(void *sum, void** array, void(*p_Init)(void *), void(*p_Sum)(void*, void*), void(*p_Sub)(void*, void*), int(*p_Comp)(void*, void*));


#endif // !example2
