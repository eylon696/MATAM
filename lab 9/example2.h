#ifndef example2
#define example2

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>


#define N 5
//functions declaration 
typedef  enum { FALSE, TRUE } BOOL;
BOOL Sum(BOOL(*f)(void *, void *, void *), void **p_num, void *number);

#endif
