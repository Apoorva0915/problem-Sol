#include <stdio.h>

void show(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
        return max;
}

void countingSort(int arr[], int size, int div)
{
    int freq[10] = {0};

    for (int i = 0; i < size; i++)
    {
        freq[arr[i] / div % 10]++;
    }
    // printf("Frequency array\n");
    // show(freq,size);

    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }
    // printf("Cumalative sum array\n");
    // show(freq,size);

    int B[size] = {0};
    for (int i = size - 1; i >= 0; i--)
    {
        freq[arr[i] / div % 10]--;
        B[freq[arr[i] / div % 10]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = B[i];
    }
}

void radixSort(int arr[], int size)
{
    int max = findMax(arr, size);
    for (int div = 1; max / div > 0; div *= 10)
    {
        countingSort(arr, size, div);
        // show(arr, size);
    }
}

int main()
{
    int arr[] = {10, 116, 4, 8, 12, 489, 15, 6, 9,3444, 5};
    int size = 11;
    show(arr, size);
    printf("\n");
    radixSort(arr, size);
    show(arr, size);
}