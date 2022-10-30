#include <stdio.h>
#define ERROR   -1
#define ASC_ODER    1
#define DESC_ORDER  0
//added macros to add constants to the code

int checkifsorted(int* arr) { // the function chech whether the array sorted or nor as the search cannot be operated on an unsorted array
    int ascend = 1, descend = 1, i = 0;
    arr[100];

    while ((ascend == 1 || descend == 1) && i < arr[i] - 1) {
        if (arr[i] < arr[i + 1])
            ascend = 0;
        else if (arr[i] > arr[i + 1])
            descend = 0;
        i++;
    }

    if (ascend == 1)
        // The array is sorted in ascending order
        return ASC_ODER;
    else if (descend == 1)
        //The array is sorted in descending order
        return DESC_ORDER;
    else
        //The array is not sorted
        return DESC_ORDER;


}
void swap(int* xp, int* yp) //function used in sorting functions 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) //sorts the array
{
    int min_idx;
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }

}
int binarySearch(int arr[], int left, int right, int x)// search in the array using binary search
{
    //if the array is sorted the binary search function searches in the array of not it enters the ese scope then sort first then search as binary search apply only to sorted arrays
    if (checkifsorted(arr, 6)) {
        while (left <= right) {
            int m = left + (right - left) / 2;

            // Check if x is present at mid
            if (arr[m] == x)
                return m + 1;

            // If x greater, ignore left half
            if (arr[m] < x)
                left = m + 1;

            // If x is smaller, ignore right half
            else
                right = m - 1;
        }
    }
    else
    {
        selectionSort(arr, 6); //sort first then search
        while (left <= right) {
            int m = left + (right - left) / 2;

            if (arr[m] == x)
                return m + 1;


            if (arr[m] < x)
                left = m + 1;

            else
                right = m - 1;
        }
    }
    // not present
    return ERROR;
}

void printArray(int arr[], int size) //displays the array
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 ,35 };
    int element = 0, size = sizeof(arr) / sizeof(arr[0]); // this equation calc the actual size of the array


    printf("The array before sorting: "); 
    printArray(arr, size);

    printf("Enter the number you want to search for: ");
    scanf_s("%d", &element);

    int index = binarySearch(arr, 0, size - 1, element); //binary search returns the index of the elements we are searching for
    printf("The sorted array: ");
    printArray(arr, size);

    if (index == -1) 
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", index);
    return 0;
}



