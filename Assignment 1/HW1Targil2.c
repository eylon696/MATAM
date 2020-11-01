#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define N 5
//define structure
typedef struct Division
{
	char code[10];
	char *name;
	int numOfProducts;
	int soldProductsToday;
}Division;

Division* build();

int main()
{
	int i;
	Division* pDivision = build();
	Division *temp, *temp1;
	Division **pArr;
	pArr = (Division**)malloc(sizeof(Division*)*N);  //memory allocation for the array of pointers
	if (pArr == NULL)
	{
		printf("Error! Memory Not Allocated!");
		exit(0);
	}
	for (i = 0; i < N; i++)
	{
		pArr[i] = &pDivision[i];  //matching the indexes of the pointer's array to the structure's array
	}
	int max, i_max, min, i_min;
	max = pDivision[0].soldProductsToday;  //initializing the max to the first index
	min = pDivision[N - 1].soldProductsToday;  //initializing the min to the last index
	i_max = 0;
	i_min = N - 1;
	for (i = 0; i < N; i++)  //start loop for finding the max, max index, min and min index
	{
		if (pDivision[i].soldProductsToday>max)
		{
			max = pDivision[i].soldProductsToday;
			i_max = i;
		}
		if (pDivision[i].soldProductsToday < min)
		{
			min = pDivision[i].soldProductsToday;
			i_min = i;
		}
	}  //end loop
	temp = pArr[0];
	temp1 = pArr[N - 1];
	pArr[0] = &pDivision[i_max];
	pArr[N - 1] = &pDivision[i_min];
	for (i = 1; i < N - 1; i++)  //start loop for checking if an adress shows up twice
	{
		if (&pDivision[i_max] == pArr[i])
		{
			pArr[i] = temp;
			break;
		}
	}  //end loop
	for (i = 1; i < N - 1; i++)  //start loop for checking if an adress shows up twice
	{
		if (&pDivision[i_min] == pArr[i])
		{
			pArr[i] = temp1;
			break;
		}
	}  //end loop
	printf("\nBest Division:\n");
	printf("Name: %s\nCode: %s", pArr[0]->name, pArr[0]->code);
	printf("\nWorst Division:\n");
	printf("Name: %s\nCode: %s", pArr[N - 1]->name, pArr[N - 1]->code);
	for (i = 0; i < N; i++)
	{
		free(pDivision[i].name);
	}
	free(pDivision);
	free(pArr);
	getch();
	return 0;
}

Division* build()
{
	char temp[20];
	int i;
	Division *pDivision;
	pDivision = (Division*)malloc(sizeof(Division)*N);  //memory allocating for the structure's array
	if (pDivision == NULL)
	{
		printf("Error! Memory Not Allocated!");
		exit(0);
	}
	printf("Enter %d division's stats:", N);
	for (i = 0; i < N; i++)  //start loop for scanning all the stats
	{
		printf("\nDivision's code (10 chars): ");
		scanf("%s", pDivision[i].code);  //code scanning
		printf("Division's name (maximum 20 chars): ");
		scanf("%s", temp);  //name scanning
		pDivision[i].name = (char*)malloc(strlen(temp) + 1);  //memory allocating for each division's name
		if (pDivision[i].name == NULL)
		{
			printf("Error! Memory Not Allocated!");
			exit(0);
		}
		strcpy(pDivision[i].name, temp);  //copying the temp string to the name
		while (1)  //scan valid stats
		{
			printf("Number of products in the division: ");
			scanf("%d", &(pDivision[i].numOfProducts));  //num of products scanning
			printf("Number of products sold per day: ");
			scanf("%d", &(pDivision[i].soldProductsToday));  //sold products today scanning
			if (pDivision[i].soldProductsToday < pDivision[i].numOfProducts)
				break;
			else
				printf("Please enter valid stats:\n");
		}
	}  //end loop
	return pDivision;
}