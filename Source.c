#include <stdio.h>


int checkifsorted(int* arr) {
    int n, a = 1, d = 1, i;
    arr[100];

    i = 0;
    while ((a == 1 || d == 1) && i < arr[i] - 1) {
        if (arr[i] < arr[i + 1])
            d = 0;
        else if (arr[i] > arr[i + 1])
            a = 0;
        i++;
    }

    if (a == 1)
        // The array is sorted in ascending order
        return 1;
    else if (d == 1)
       //The array is sorted in descending order
        return 0;
    else
       //The array is not sorted
        return 0;


}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{ 
 
        int i, j, min_idx;
        // One by one move boundary of unsorted subarray
        for (i = 0; i < n - 1; i++)
        {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first element
            if (min_idx != i)
                swap(&arr[min_idx], &arr[i]);
        }
    
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (checkifsorted(arr, 6)) {
        while (l <= r) {
            int m = l + (r - l) / 2;

            // Check if x is present at mid
            if (arr[m] == x)
                return m + 1;

            // If x greater, ignore left half
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
    }
    else
    {
        selectionSort(arr, 6); //sort first then search
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (arr[m] == x)
                return m + 1;

           
            if (arr[m] < x)
                l = m + 1;

            else
                r = m - 1;
        }
    }
    // not present
    return -1;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11 ,35};
    int x=0,n = sizeof(arr) / sizeof(arr[0]);

    printf("The array before sorting: ");
    printArray(arr, n);

    printf("\nEnter the number you want to search for: ");
    scanf_s("%d", &x);
   
    int index = binarySearch(arr, 0, n - 1, x);
    printf("The sorted array: ");
    printArray(arr, n);

    if (index == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d",index);
    return 0;
}



