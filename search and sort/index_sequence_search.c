#include <stdio.h>
#include <math.h>

int seqSearch(int a[], int start, int end, int key)
{
    for (int i = 0; i < end; i++)
    {
        if (a[i] > key)
            return 0;
        if (a[i] == key)
            return 1;
    }
    return 0;
}

int indexSequenceSearch(int a[], int size, int key)
{
    if (key < a[0])
        return 0;
    if (key > a[size - 1])
        return 0;
    int BS = ceil(sqrt(size));

    int k = 0;
    int index[BS];
    for (int i = 0; i < size; i += BS)
    {
        index[k++] = i;
    }
    for (int i = 0; i < BS; i++)
    {
        if (key <= a[index[i]])
        {
            int start = index[i - 1];
            int end = index[start + BS];
            seqSearch(a, start, end, key);
            break;
        }
    }
}

int main()
{
    int a[8] = {5, 9, 20, 25, 27, 30, 80, 91};
    int ans = indexSequenceSearch(a, 8, 80);
    if (ans == 1)
        printf("element found");
    else
        printf("not found");
}