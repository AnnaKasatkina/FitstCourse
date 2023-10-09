/*
Самый частый элемент
Переделать задачу про самый частый элемент в массиве из прошлого задания так,
чтобы сортировка была в отдельном модуле и читала входные данные из файла.
*/

#include <stdio.h>

void printing(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

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

int mostCommonElement(int *array, int lenght)
{
    int count = 1;
    int max = 0;
    int answer = 0;
    for (int i = 1; i < lenght; ++i)
    {
        if (array[i] == array[i - 1])
        {
            count++;
        }
        else
        {
            if (count >= max)
            {
                answer = array[i - 1];
                max = count;
                count = 1;
            }
            count = 1;
        }
    }
    return answer;
}

int main(void)
{
    FILE* fp = fopen("my_file.txt", "r");
    if (fp == NULL)
    {
        return 1;
    }

    int array[1000] = {};
    int lenght = 0;

    while (fscanf(fp, "%d ", &array[lenght]) == 1)
    {
        lenght++;
    }

    fclose(fp);

    quickSort(array, 0, lenght);

    printf("%d the most common element in the array: ", mostCommonElement(array, lenght));
    printing(array, lenght);

    return 0;
}
