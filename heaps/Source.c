#include<stdio.h>
#include<conio.h>

#define M 6

typedef struct Values
{
	int num;
	int index;
}Values;

int Find_Max(Values A[]);
int Find_Min(Values B[]);
void Init (int arr[],int count,Values A[],Values B[]);
void Del_Min(Values A[], Values B[], int *count, int i);
void Del_Max(Values B[], Values A[], int *count, int i);
void Heap_Extract_min(Values B[], Values A[], int *count);
void Heap_Extract_max(Values A[], Values B[],int *count);
void HeapifyDown_max(Values A[], Values B[],  int n, int i);
void BuildHeap_Max(Values A[], Values B[], int n);
void swap(int *x, int *y);
void HeapifyDown_Min(Values B[],Values A[], int n, int i);
void BuildHeap_Min(Values B[], Values A[], int n);
void Heapify_Up_min(Values B[], Values A[], int *count);
void Heap_Insert(Values A[], Values B[], int val, int *count);
void Heapify_Up_max(Values A[], Values B[], int *count);

int main()
{
	int i,flag,arr[M],count=0,val,num;
	Values A[M], B[M];
	printf("Insert values enter 999 to stop or no more than %d: \n",M);
	for (i = 0; i < M ; i++)
	{
		scanf("%d", &flag);
		if (flag == 999)
			break;
		arr[i] = flag;	
		count++;
	}
	Init(arr, count, A, B);

	while (1)
	{
		printf("\nchoose 1 option (1-6)\n");
		printf("1. Insert a new number to the heap\n");
		printf("2. find the min value\n");
		printf("3. find the max value\n");
		printf("4. delete the min value\n");
		printf("5. delete the max value\n");
		printf("6. print heap min\n");
		printf("7. print heap max\n");
		printf("8. exit\n");
		scanf("%d", &num);
		if (num == 1)
		{
			if (count == M)
				printf("The heap is full please select another option\n");
			else
			{
				count++;
				printf("enter num\n");
				scanf("%d", &val);
				Heap_Insert(A,B, val, &count);
				printf("Your number has been added\n");
			}	
		}
		if (num == 2)
			printf("The min value is:%d\n", Find_Min(B));
		if (num == 3)
			printf("The max value is:%d\n", Find_Max(A));
		if (num == 4)
		{
			if (count == 0)
				printf("The heap is empty please select another option");
			else
			{
				Heap_Extract_min(B, A, &count);
				count--;
				printf("The min value was deleted\n");
			}
		}
		if (num == 5)
		{
			if (count == 0)
				printf("The heap is empty please select another option");
			else
			{
				Heap_Extract_max(A, B, &count);
				count--;
				printf("The max value was deleted\n");
			}
		}
		if (num == 6)
		{
			for (i = 0; i < count; i++)
				printf("%d, ", B[i].num);
		}
		if (num == 7)
		{
			for (i = 0; i < count; i++)
				printf("%d, ", A[i].num);
		}
		if (num == 8)
			break;
	}

	getch();
	return 0;
}

//initializing Data Structures (heap max/heap min)
void Init(int arr[],int count, Values A[], Values B[])
{
	int  i, temp;
	for (i = 0; i < count; i++)
	{
		temp = arr[i];
		A[i].num = temp;
		B[i].num = temp;
		A[i].index = i;
		B[i].index = i;
	}
	BuildHeap_Min(B, A, count);
	BuildHeap_Max(A,B, count);
}

//Function that build heap max.
void BuildHeap_Max(Values A[], Values B[], int n)
{
	int  i;
	for (i = (n / 2) - 1; i >= 0; i--)
		HeapifyDown_max(A, B, n, i);
}

//Heapify Down function, fix the heap.
void HeapifyDown_max(Values A[], Values B[],  int n, int i)
{
	int *temp;
	int L = (2 * i + 1); //Left child of the root.
	int R = (2 * i + 2); //Right child of the root.
	int largest = i;	 //largest = root.

	if ((L < n) && (A[L].num > A[i].num)) 	// If left child is biger than the root
		largest = L;
	if ((R < n) && (A[R].num > A[largest].num))	// If right child is smaller than smallest so far
		largest = R;
	if (largest != i)		//If largest is not the root					
	{
		swap(&A[i].num  , &A[largest].num);
		swap(&A[i].index, &A[largest].index);
		swap(&B[A[i].index].index, &B[A[largest].index].index);
		HeapifyDown_max(A,B, n, largest);
	}
}

//Function that build heap min.
void BuildHeap_Min(Values B[], Values A[], int n)
{
	int  i;
	for (i = (n / 2) - 1; i >= 0; i--)
		HeapifyDown_Min(B, A, n, i);
}

//Heapify Down function, fix the heap.
void HeapifyDown_Min(Values B[], Values A[], int n, int i)
{
	int *temp;
	int L = (2 * i + 1); //Left child of the root.
	int R = (2 * i + 2); //Right child of the root.
	int largest = i;	 //largest = root.

	if ((L < n) && (B[L].num < B[largest].num)) 	// If left child is smaller than the root
		largest = L;
	if ((R < n) && (B[R].num < B[largest].num))	// If right child is smaller than smallest so far
		largest = R;
	if (largest != i)		//If largest is not the root					
	{
		swap(&B[i].num  , &B[largest].num);
		swap(&B[i].index, &B[largest].index);
		swap(&A[B[i].index].index, &A[B[largest].index].index);
		HeapifyDown_Min(B, A, n, largest);
	}
}

//Heapify up function, fix the heap.
void Heapify_Up_min(Values B[],Values A[], int *count)
{
	int parent,temp;
	temp = *count;
	parent = (temp-1) / 2;

	if (temp != 0 && B[temp-1].num < B[parent].num)
	{
		swap(&B[temp-1].num, &B[parent].num);
		swap(&B[temp - 1].index, &B[parent].index);
		swap(&A[B[temp - 1].index].index, &A[B[parent].index].index);
		parent++;
		Heapify_Up_min(B, A, &parent);
	}
}

//Insert value to heap max and heap min
void Heap_Insert(Values A[], Values B[], int val, int *count)
{
	int temp;
	temp = *count;
	A[temp - 1].num = val;
	A[temp - 1].index = (temp - 1);
	B[temp - 1].num = val;
	B[temp - 1].index = (temp - 1);
	Heapify_Up_max(A,B, &temp);
	Heapify_Up_min(B, A, &temp);
}

//Heapify up function, fix the heap.
void Heapify_Up_max(Values A[], Values B[], int *count)
{
	int parent, temp;
	temp = *count;
	parent = (temp - 1) / 2;

	if (temp != 0 && A[temp - 1].num > A[parent].num)
	{
		swap(&A[temp - 1].num, &A[parent].num);
		swap(&A[temp - 1].index, &A[parent].index);
		swap(&B[A[temp - 1].index].index, &B[A[parent].index].index);
		parent++;
		Heapify_Up_max(A,B, &parent);
	}
}

//Function that delete the min.
void Heap_Extract_min(Values B[], Values A[], int *count)
{
	int temp,min;
	int i;
	temp = *count;
	i = B[0].index;
	swap(&B[0].num, &B[temp - 1].num);
	swap(&B[0].index, &B[temp - 1].index);
	swap(&A[B[0].index].index, &A[B[temp - 1].index].index);
	temp--;
	HeapifyDown_Min(B,A, temp, 0);
	Del_Max(B, A, count, i);
}

//Function that delete the max.
void Heap_Extract_max(Values A[], Values B[], int *count)
{
	int temp, min;
	int i;
	temp = *count;
	i = A[0].index;
	swap(&A[0].num, &A[temp - 1].num);
	swap(&A[0].index, &A[temp - 1].index);
	swap(&B[A[0].index].index, &B[A[temp - 1].index].index);
	temp--;
	HeapifyDown_max(A,B, temp, 0);
    Del_Min(A, B, count, i);
}

void Del_Min(Values A[], Values B[], int *count, int i)
{
	int temp;
	temp = *count;
	swap(&B[i].num, &B[temp - 1].num);
	swap(&B[i].index, &B[temp - 1].index);
	swap(&A[B[i].index].index, &A[B[temp - 1].index].index);
	temp--;
	HeapifyDown_Min(B, A, temp, i);
	Heapify_Up_min(B,A, &temp);
}

void Del_Max(Values B[], Values A[], int *count,int i)
{
	int temp;
	temp = *count;
	swap(&A[i].num, &A[temp - 1].num);
	swap(&A[i].index, &A[temp - 1].index);
	swap(&B[A[i].index].index, &B[A[temp - 1].index].index);
	temp--;
	HeapifyDown_max(A, B, temp, i);
	Heapify_Up_max(A,B, &temp);
}

//Swap values
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Find_Max(Values A[])
{
	return A[0].num;
}

int Find_Min(Values B[])
{
	return B[0].num;
}