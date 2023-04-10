#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int extraMemoryAllocated;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
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

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        int* tempArr = (int*)malloc(sizeof(int) * (r - l + 1));
        if (tempArr == NULL)
        {
            printf("Cannot allocate memory\n");
            exit(-1);
        }

        int i = l;
        int j = m + 1;
        int k = 0;

        while (i <= m && j <= r)
        {
            if (arr[i] < arr[j])
            {
                tempArr[k++] = arr[i++];
            }
            else
            {
                tempArr[k++] = arr[j++];
            }
        }

        while (i <= m)
        {
            tempArr[k++] = arr[i++];
        }

        while (j <= r)
        {
            tempArr[k++] = arr[j++];
        }

        for (int p = 0; p < k; p++)
        {
            arr[l + p] = tempArr[p];
        }

        free(temp
