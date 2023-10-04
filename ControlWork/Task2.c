/*
Реализовать сортировку пузырьком только элементов
массива с чётными индексами. Например, массив [5, 4, 3, 2, 1]
должен быть отсортирован как [1, 4, 3, 2, 5].
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void scanfArray(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Input error ");
            break;
        }
    }
}

void printing(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

void bubbleSort(int *array, int lenght)
{
    for (int i = 2; i < lenght; i += 2)
    {
        for (int j = 2; j < lenght; j += 2)
        {
            if (array[j] < array[j - 1])
            {
                int intermediate = array[j];
                array[j] = array[j - 2];
                array[j - 2] = intermediate;
            }
        }
    }
}

void testArray(int *rightTestingArray, int *testingArray, int lenght)
{
    for (int i = 0; i < lenght; ++i)
    {
        assert(rightTestingArray[i] == testingArray[i]);
    }
}

void testIncreasingArray()
{
    int lenght = 6;
    int testingArray[] = {0, 1, 2, 3, 4, 5};
    int rightTestingArray[] = {0, 1, 2, 3, 4, 5};

    bubbleSort(testingArray, lenght);
    testArray(rightTestingArray, testingArray, lenght);
    printf("Test Increasing Array is OK\n");
}

void testDecreasingArray()
{
    int lenght = 5;
    int testingArray[] = {5, 4, 3, 2, 1};
    int rightTestingArray[] = {1, 4, 3, 2, 5};

    bubbleSort(testingArray, lenght);
    testArray(rightTestingArray, testingArray, lenght);
    printf("Test Decreasing Array is OK\n");
}

void testIdenticalCharacters()
{
    int lenght = 7;
    int testingArray[] = {6, 6, 6, 6, 6, 6, 6};
    int rightTestingArray[] = {6, 6, 6, 6, 6, 6, 6};

    bubbleSort(testingArray, lenght);
    testArray(rightTestingArray, testingArray, lenght);
    printf("Test Identical Characters is OK\n");
}

int main()
{
    testIncreasingArray();
    testDecreasingArray();
    testIdenticalCharacters();

    int lenght = 0;
    printf("Enter lenght of array: ");
    if (scanf("%d", &lenght) != 1)
    {
        printf("Input error");
        return 1;
    }

    int *array = calloc(lenght, sizeof(int));
    scanfArray(array, lenght);

    bubbleSort(array, lenght);
    printing(array, lenght);

    free(array);
    return 0;
}
