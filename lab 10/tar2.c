#include"example2.h"
//Define specific functions

//The function compare between two numbers
int Int_Comp(void *a, void *b)
{
	if (*(int*)a == *(int*)b)
		return 1;
	return 0;
}
//The function perform sum 
void Int_Sum(void *sum, void *num)
{
	*(int*)sum += *(int*)num;
}

//The function performs subtraction
void Int_Sub(void *sum, void *num)
{
	*(int*)sum -= *(int*)num;
}

//The function initializes a number
void Init(void *p)
{
	*(int*)p = 0;
}

int main()
{
	int num[] = { 5,8,23,20,23 }, i, answer;
	void *p_num[N];//Pointers array
	for (i = 0; i < N; i++)
	{
		p_num[i] = &num[i];//Fill the pointers array
	}
	answer = Do_It(&answer, p_num, Init, Int_Sum, Int_Sub, Int_Comp);
	if (answer == 1)
		printf("The answer is 'Yes'");
	else
		printf("The answer is 'No'");

	getch();
	return 0;
}