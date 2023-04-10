#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int extraMemoryAllocated;

// implements heap sort
// extraMemoryAllocated counts bytes of memory allocated
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}


// implement merge sort
// extraMemoryAllocated counts bytes of extra memory allocated
void merge(int pData[], int l, int m, int r, int temp[]) 
{ 
    int i = l, j = m + 1, k = 0; 
  
    while (i <= m && j <= r) { 
        if (pData[i] <= pData[j]) 
            temp[k++] = pData[i++]; 
        else
            temp[k++] = pData[j++]; 
    } 
  
    while (i <= m) 
        temp[k++] = pData[i++]; 
  
    while (j <= r) 
        temp[k++] = pData[j++]; 
  
    for (i = l, k = 0; i <= r; i++, k++) 
        pData[i] = temp[k]; 
}

void mergeSortHelper(int pData[], int l, int r, int temp[]) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSortHelper(pData, l, m, temp); 
        mergeSortHelper(pData, m + 1, r, temp); 
  
        merge(pData, l, m, r, temp); 
    } 
} 

void mergeSort(int pData[], int l, int r)
{
    int *temp = (int *)malloc(sizeof(int) * (r-l+1));
    extraMemoryAllocated += sizeof(int) * (r-l+1);
    if (temp == NULL)
    {
        printf("Cannot allocate memory\n");
        exit(-1);
    }
    
    mergeSortHelper(pData, l, r, temp);
    
    free(temp);
}
