#include <stdio.h>
#include <math.h>
#include <conio.h>

#define N 10
//define structure
typedef struct Fraction
{
	int mone, mehane;
}Fraction;

//functions decleration
void fractionScanAndBuild(Fraction *arr);
int mehaneCommon(int a, int b);
int mone(Fraction *arr, int c);
void negToPos(Fraction *arr);

int main()
{
	int i;
	int newMehane, newMone;
	Fraction arr[N];
	printf("Enter fractions(max 9) by pairs of integers(0 0 to finish):\n");
	fractionScanAndBuild(arr);
	negToPos(arr);  //converting negate mone and mehane to positive
	newMehane = mehaneCommon(arr[1].mehane, arr[2].mehane); //initial common mehane
	for (i = 1; i < N; i++)  //calculating the mehane of all fractions
	{
		if (arr[i].mehane == 0)
			break;
		newMehane = mehaneCommon(newMehane, arr[i].mehane);
	}
	newMone = mone(arr, newMehane);  //calculating new common mone
	int x = newMehane;
	int j = newMone%newMehane;
	for (i = 2; i < N; i++)  //loop to make the remainder the most reduced
	{
		if (newMehane%i == 0 && j%i == 0)
		{
			newMehane /= i;
			j /= i;
			i = 2;
		}
	}
	printf("%d/%d", arr[1].mone, arr[1].mehane);
	for (i = 1; i < N-1; i++)  //loop for printing the end result given the sign of each fraction
	{
		if (arr[i + 1].mone == 0 && arr[i + 1].mehane == 0)
			break;
		if (arr[i + 1].mone>0)
			printf("+%d/%d", arr[i + 1].mone, arr[i + 1].mehane);
		else
			printf("%d/%d", arr[i + 1].mone, arr[i + 1].mehane);
	}  //end loop
	if (newMone/x < 0 && j < 0)
		j *= -1;
	printf(" = %d/%d = %d and %d/%d", newMone, x, (newMone / x), j, newMehane);
	getch();
	return 0;
}

//the function builds the array of structures correctly
void fractionScanAndBuild(Fraction *arr)
{
	int i;
	for (i = 1; i < N; i++)  //scanning all fractions as long as both mone and mehane aren't zero
	{
		printf("%d (mone mehane) : ", i);
		scanf("%d %d", &arr[i].mone, &arr[i].mehane);
		if (arr[1].mone == 0 && arr[1].mehane == 0)  //end program if the only numbers insterted are 0 and 0
		{
			printf("Bye Bye.");
			getch();
			exit(0);
		}
		while (arr[i].mone != 0 && arr[i].mehane == 0)  //asking for a valid fraction if the mehane is 0
		{
			printf("Please enter valid numbers (mehane != 0):\n");
			scanf("%d %d", &arr[i].mone, &arr[i].mehane);
			if (arr[1].mone == 0 && arr[1].mehane == 0)  //end program if the only numbers insterted are 0 and 0
			{
				printf("Bye Bye.");
				getch();
				exit(0);
			}
		}
		if (arr[i].mone == 0 && arr[i].mehane == 0)
			break;
	}
}

//the function returns the common mehane of 2 fractions
int mehaneCommon(int a, int b)
{
	int mehaneCommon;
	if (a > b)
		mehaneCommon = a;
	else
		mehaneCommon = b;
	while (1)
	{
		if (b == 0)
			break;
		if (mehaneCommon%a == 0 && mehaneCommon%b == 0)
			return mehaneCommon;
		mehaneCommon++;
	}
}

//the function returns the common mone of all fractions
int mone(Fraction*arr, int c)
{
	int i, new_mone = 0;
	for (i = 1; i < N; i++)
	{
		if (arr[i].mehane == 0)
			break;
		new_mone += (c*arr[i].mone) / arr[i].mehane;
	}
	return new_mone;
}

void negToPos(Fraction *arr)
{
	int i;
	for (i = 1; i < N; i++)
	{
		if (arr[i].mone < 0 && arr[i].mehane < 0)  //if both mone and mehane are negative, turns the fraction to positive
		{
			arr[i].mone *= -1;
			arr[i].mehane *= -1;
		}
		else if (arr[i].mone > 0 && arr[i].mehane < 0)  //if the mone is positive and the mehane is negative, switches signs between them
		{
			arr[i].mone *= -1;
			arr[i].mehane *= -1;
		}
		if (arr[i].mone == 0 && arr[i].mehane == 0)
			break;
	}
}