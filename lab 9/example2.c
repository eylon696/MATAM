#include"example2.h"
//The function cheacks if the sum of two numbers is equal to third number 
BOOL Sum(BOOL(*f)(void *, void *, void *), void **p_num, void *number)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = i+1; j <= N-1; j++)
		{
			if (f((p_num)[i], p_num[j], number) == TRUE)
				return TRUE;
		}
	}
	return FALSE;
}