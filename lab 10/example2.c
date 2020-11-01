#include"example2.h"
//Define general functions and structures
//A function that sum numbers in the even places and subtracts numbers in the odd places and checks if the next number in the array equals the result 
int Do_It(void *sum, void** array, void(*p_Init)(void *), void(*p_Sum)(void*, void*), void(*p_Sub)(void*, void*), int(*p_Comp)(void*, void*))
{
	int i;
	p_Init(sum);//Initializing the variable sum
	for (i = 0; i < N-1; i++)
	{
		if ((i+1) % 2 != 0)
			p_Sum(sum, array[i]);
		else
			p_Sub(sum, array[i]);
		if (p_Comp(sum, array[i + 1]))
			return 1;
	}
	return 0;
}
