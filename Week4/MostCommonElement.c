/*
Самый частый элемент
Переделать задачу про самый частый элемент в массиве из прошлого задания так,
чтобы сортировка была в отдельном модуле и читала входные данные из файла.
*/

#include <stdio.h>

#include "Sorting.h"

void printing(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
        printf("%d ", array[i]);
    printf("\n\n");
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
    int lenght = 5;
    int array[] = {0, 3, 4, 7, 4};

    quickSort(array, 0, lenght);

    printf("%d the most common element in the array: ", mostCommonElement(array, lenght));
    printing(array, lenght);

    return 0;
}
