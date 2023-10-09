#include <stdio.h>

int movementOfSigns(int *array, int left, int right)
{
    int pivot = array[(left + right) / 2];
    while (left <= right)
    {
        while (array[left] < pivot)
        {
            left++;
        }

        while (array[right] > pivot)
        {
            right--;
        }

        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }

    return left;
}

void insertionSort(int *array, int start, int end)
{
    for (start + 1; start < end; start++)
    {
        int sorted = start;
        while (sorted > -1 && array[sorted] > array[sorted + 1])
        {
            int temp = array[sorted];
            array[sorted] = array[sorted + 1];
            array[sorted + 1] = temp;
            sorted--;
        }
    }
}

void quickSort(int *array, int start, int end)
{
    if (end - start < 10)
    {
        insertionSort(array, start, end);
        return;
    }
    int rightStart = movementOfSigns(array, start, end);

    quickSort(array, start, rightStart - 1);
    quickSort(array, rightStart, end);
}