/*
Пузырёк и подсчёт
Написать сортировки пузырьком и подсчётом.
С помощью функции clock() из time.h
сравнить времена их работы на массиве из 100000 элементов.
Задача предполагает использование выделяемого с помощью malloc()
и освобождаемого с помощью free() массива.
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 5

void bubbleSort(int *array)
{
    for (int i = 1; i < LEN; i++)
    {
        for (int j = 1; j < LEN; j++)
        {
            if (array[j] > array[j - 1])
            {
                int intermediate = array[j];
                array[j] = array[j - 1];
                array[j - 1] = intermediate;
            }
        }
    }
}

int main()
{
    int array[LEN] = {0};

    for (int i = 0; i < LEN; i++)
    {
        array[i] = rand() % 10000;
        printf("%d ", array[i]);
    }

    bubbleSort(array);
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", array[i]);
    }

}
