#include "example.h"

//the function checks if the int data is equal
int isequalint(void* element, void* data)
{
	if (*(int*)element == *(int*)data)
		return 1;
	return 0;
}

//the function checks if the char data is equal
int isequalst(void* element, void* data)
{
	if (!(strcmp((char*)element, (char*)data)))
		return 1;
	return 0;
}

//the function checks if data (int) is greater than element
int GreaterInt(void* element, void* data)
{
	if (*(int*)data > *(int*)element)
		return 1;
	return 0;
}

//the function checks if data (string) is greater than element
int GreaterStr(void* element, void* data)
{

	if (strcmp((char*)element, (char*)data) < 0)  //data is greater than element
		return 1;
	return 0;
}

//the function prints integers
void PrntNum(void* data)
{
	printf("%d ", *(int*)data);
}

//the function prints chars
void PrntChar(void* data)
{
	printf("%s ", (char*)data);
}

//the function deletes the data indside the set
void DeleteInt(void* data)
{
	free(data);
}

//the function deletes the data indside the set
void DeleteChar(void* data)
{
	free(data);
}

//the function executes the int menu
PSET MenuInt(PSET s)
{
	int choice;
	int IntData;
	int *NumData;
	printf("Enter an integer ('-999' to stop): ");
	scanf("%d", &IntData);
	while (IntData != -999)
	{
		NumData = (int*)malloc(sizeof(int));  //creates a specific address for every variable thats being scanned from the user
		if (NumData == NULL)  //check the memory allocation
		{
			deleteSet(&s);
			FreeSet(s);
			Err_Msg("Memory!");
		}
		*NumData = IntData;   //copying the data to the new address
		createSet(NumData, &s);  //creating the nodes and connecting them to the linked list
		printf("Enter an integer ('-999' to stop): ");
		scanf("%d", &IntData);
	}
	PrintMenu();  //shows the menu to the user
	scanf("%d", &choice);
	while (choice != 9)  //the user chooses an option to execute (1-8 and 9 to end)
	{
		switch (choice)
		{
		case 1:  //add new data
			printf("Enter a new integer: ");
			scanf("%d", &IntData);
			NumData = (int*)malloc(sizeof(int));   //creates a specific address for every variable thats being scanned from the user
			if (NumData == NULL)
			{
				deleteSet(&s);
				FreeSet(s);
				Err_Msg("Memory!");
			}
			*NumData = IntData;  //copying the data to the new address
			addToSet(&s, NumData);  //creats new node
			break;
		case 2:  //delete data
			printf("Enter an integer you want to delete from the set: ");
			scanf("%d", &IntData);
			if (deleteFromSet(&s, &IntData) == TRUE)  //in case the data is in the set
				printf("%d was removed from the set\n", IntData);
			else  //in case the data is not in the set
				printf("%d wasn't found in the set!\n", IntData);
			break;
		case 3:  //find data in the set
			printf("Enter an integer you want to find the set: ");
			scanf("%d", &IntData);
			if (findInSet(&s, &IntData) == TRUE)  //in case the data is in the set
				printf("%d was found in the set\n", IntData);
			else  //in case the data is not in the set
				printf("%d wasn't found in the set!\n", IntData);
			break;
		case 4:  //check the size of the set
			printf("There are %d integers in the set\n", setSize(&s));
			break;
		case 5:  //find the maximum data in the set
			if (findMax(&s) == NULL)
				printf("There is no set!\n");
			else printf("The maximum integer in the set is: %d\n", *(int*)findMax(&s));
			break;
		case 6:  //find the minimum data in the set
			if (findMin(&s) == NULL)
				printf("There is no set!\n");
			else printf("The minimum integer in the set is: %d\n", *(int*)findMin(&s));
			break;
		case 7:  //delete the entire set
			deleteSet(&s);
			printf("The set has been deleted!\n");
			break;
		case 8:  //print the entire set
			PrintAll(&s);
			break;
		default:  //in case the user didn't entered a valid option (1-9)
			printf("Input Error!\n");
			break;
		}
		PrintMenu();
		scanf("%d", &choice);
	}
	return s;
}

//the function executes the char menu
PSET MenuChar(PSET s)
{
	int choice;
	char CharData[256];
	char *StringData;
	printf("Enter a string ('end' to stop): ");
	scanf("%s", CharData);
	while (strcmp(CharData, "end"))
	{
		StringData = (char*)malloc(sizeof(char)*strlen(CharData) + 1);  //creates a specific address for every variable thats being scanned from the user
		if (StringData == NULL)  //check the memory allocation
		{
			deleteSet(&s);
			FreeSet(s);
			Err_Msg("Memory!");
		}
		strcpy(StringData, CharData);  //copying the data to the new address
		createSet(StringData, &s);  //creating the nodes and connecting them to the linked list
		printf("Enter a string ('end' to stop): ");
		scanf("%s", CharData);
	}
	PrintMenu();  //shows the menu to the user
	scanf("%d", &choice);
	while (choice != 9)  //the user chooses an option to execute (1-8 and 9 to end)
	{
		switch (choice)
		{
		case 1:  //add new data
			printf("Enter a new string: ");
			scanf("%s", CharData);
			StringData = (char*)malloc(sizeof(char)*strlen(CharData) + 1);  //creates a specific address for every variable thats being scanned from the user
			if (StringData == NULL)
			{
				deleteSet(&s);
				FreeSet(s);
				Err_Msg("Memory!");
			}
			strcpy(StringData, CharData);  //copying the data to the new address
			addToSet(&s, StringData);  //creats new node
			break;
		case 2:  //delete data
			printf("Enter a string you want to delete from the set: ");
			scanf("%s", CharData);
			if (deleteFromSet(&s, CharData) == TRUE)  //in case the data is in the set
				printf("%s was removed from the set\n", CharData);
			else  //in case the data is not in the set
				printf("%s wasn't found in the set!\n", CharData);
			break;
		case 3:  //find data in the set
			printf("Enter a string you want to find the set: ");
			scanf("%s", CharData);
			if (findInSet(&s, CharData) == TRUE)  //in case the data is in the set
				printf("%s was found in the set\n", CharData);
			else  //in case the data is not in the set
				printf("%s wasn't found in the set!\n", CharData);
			break;
		case 4:  //check the size of the set
			printf("There are %d strings in the set\n", setSize(&s));
			break;
		case 5:  //find the maximum data in the set
			if (findMax(&s) == NULL)
				printf("The is no set!\n");
			else printf("The maximum string in the set is: %s\n", (char*)findMax(&s));
			break;
		case 6:  //find the minimum data in the set
			if (findMin(&s) == NULL)
				printf("The is no set!\n");
			printf("The minimum string in the set is: %s\n", (char*)findMin(&s));
			break;
		case 7:  //delete the entire set
			deleteSet(&s);
			printf("The set has been deleted!\n");
			break;
		case 8:  //print the entire set
			PrintAll(&s);
			break;
		default:  //in case the user didn't entered a valid option (1-9)
			printf("Input Error!\n");
			break;
		}
		PrintMenu();
		scanf("%d", &choice);
	}
	return s;
}


int main()
{
	char ch;
	PSET s;
	while (1)  //loop to choose between chars and integers
	{
		printf("Choose Integers or Chars (i for integers, c for chars): ");
		scanf(" %c", &ch);
		if ((ch == 'i') || (ch == 'c'))  
			break;
		else
			printf("Input Error!\n");
	}

	if (ch == 'i')  //the program will work with integers
	{
		Init(&s, isequalint, GreaterInt, PrntNum, DeleteInt);  //initalizing manager structure
		s = MenuInt(s);
		deleteSet(&s);
	}

	else  //the program will work with strings
	{
		Init(&s, isequalst, GreaterStr, PrntChar, DeleteChar);  //initalizing manager structure
		s = MenuChar(s);
		deleteSet(&s);
	}
	printf("End of program!\n");
	FreeSet(s);
	getch();
	return 0;
}