#include"example2.h"

BOOL Int_Sum(void *a, void *b, void *c)
{
	if (*(int*)a + *(int*)b == *(int*)c)
		return TRUE;
	return FALSE;
}

BOOL Float_Sum(void *a, void *b, void *c)
{
	if (*(float*)a + *(float*)b == *(float*)c)
		return TRUE;
	return FALSE;
}

int main()
{
	int num[] = { 3,5,23,5,6 }, i, value;
	float  fnum[] = { 3.5,5.0,2.3,5.8,6.2 }, fvalue;
	void *p_num[N];
	for (i = 0; i < N; i++)//fillings the pointers array
	{
		p_num[i] = &num[i];
	}

	printf("\nPlease enter an integer number ");
	scanf("%d", &value);
	if (Sum(Int_Sum, p_num, &value) == TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");
	for (i = 0; i < N; i++)//fillings the pointers array
	{
		p_num[i] = &fnum[i];
	}
	printf("\nPlease enter a float number ");
	scanf("%f", &fvalue);
	if (Sum(Float_Sum, p_num, &fvalue) == TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");

	getch();
	return 0;
}





