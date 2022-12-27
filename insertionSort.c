#include <stdio.h>
#define arrSize 50

void shift_element(int *arr, int i)
    {
        int counter = 1;

        while (counter <= i)
        {
            *(arr + i + 1) = *(arr + i);
            i--;
        }
        
    }

void insertion_sort(int* arr , int len)
    {
        int i, current, j;
        for (i = 1; i < len; i++)
        {
            current = *(arr + i);
            j = i - 1;

        while (j >= 0 && *(arr+j) > current)  
            {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
            }
            *(arr + j + 1) = current;
        }
    }

int main()
{
    int arr[arrSize];
    int i = 0;

    while (i<arrSize)
    {
        scanf("%d", &(*(arr + i)));
        i++;
    }

    int length = sizeof(arr)/ sizeof(arr[0]);
    insertion_sort(arr,length);

    for (size_t i = 0; i < length; i++)
    {
        if ( i + 1 == length)  
            {
                printf("%d", arr[i]);
            }
        else
            {
                printf("%d,", arr[i]);
            } 
    }
}







