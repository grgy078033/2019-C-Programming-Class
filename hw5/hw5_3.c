#include <stdio.h>
#define SIZE 31

int a[SIZE] ={15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
void mirror_iterative(int a[]);
void mirror_recursive(int root_index, int a[], int n);
void ReverseArray(int arr[], int start, int end);

int main()
{
	int i;
	
	for(i = 1; i <= a[0]; i++)
		{
			if(i == a[0])
				printf("%d", a[i]);
			else
				printf("%d,", a[i]); 
		}
	printf("\n");
	
	mirror_recursive(1, a, a[0]);
	
	for(i = 1; i <= a[0]; i++)
		{
			if(i == a[0])
				printf("%d", a[i]);
			else
				printf("%d,", a[i]); 
		} 
	printf("\n\n");
	
	mirror_recursive(1, a, a[0]);
	
	for(i = 1; i <= a[0]; i++)
		{
			if(i == a[0])
				printf("%d", a[i]);
			else
				printf("%d,", a[i]); 
		} 
	printf("\n");
	
	mirror_iterative(a);
	
	for(i = 1; i <= a[0]; i++)
		{
			if(i == a[0])
				printf("%d", a[i]);
			else
				printf("%d,", a[i]); 
		} 
	printf("\n");

	return 0;
}

void ReverseArray(int arr[], int start, int end) 
{ 
    int temp; 
    while (start < end) 
    { 
        temp = arr[start];    
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }    
}   

void mirror_recursive(int root_index, int a[], int n)
{
	int i, j;
	int b[SIZE];
	
	if(root_index * 2 > a[0])
		return;
		
	for(i = 1; i < SIZE; i++)
		{
			if(root_index * (1 << i) > a[0])
				break;
					
			for(j = 0; j < (1 << i) / 2; j++)
				{
					b[j] = a[(1 << i) * root_index + j];
					a[(1 << i) * root_index + j] = a[(1 << i) * root_index + (1 << i) / 2 + j];
					a[(1 << i) * root_index + (1 << i) / 2 + j] = b[j];
				}
		}
	mirror_recursive(2 * root_index, a, a[0]);
	mirror_recursive(2 * root_index + 1, a, a[0]);
}

void mirror_iterative(int a[])
{
	int i, start, end;
	
    for(i = 1; i < a[0]; i = i * 2)
        {
            start = i;
            end = i * 2 - 1;
            ReverseArray(a, start, end);
        }
}

