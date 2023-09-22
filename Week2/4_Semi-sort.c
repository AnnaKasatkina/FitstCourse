/*
Полукусорт
Написать программу, которая заполняет массив случайными значениями
(с использованием функции rand из stdlib.h),
потом преобразует его без использования дополнительных массивов так,
что в начале массива будут элементы, меньшие первого,
а в конце — большие либо равные первому.
Программа должна работать за линейное время.
*/

#include <stdio.h>
#include <stdlib.h>
#define LEN 50

int main()
{
    printf("Primordial array: ");
    int array[LEN] = {0};

    for (int i = 0; i < LEN; i++)
    {
        array[i] = rand() % 1000;
        printf("%d ", array[i]);
    }

    int firstNumber = array[0];
    int j = LEN - 1;
    int i = 0;
    int intermediate = 0;

    while (i != j)
    {
        if (array[i] > array[i + 1])
        {
            intermediate = array[i];
            array[i] = array[i + 1];
            array[i + 1] = intermediate;
            i++;
        }
        else
        {
            intermediate = array[j];
            array[j] = array[i + 1];
            array[i + 1] = intermediate;
            j--;
        }
    }

    printf("\nThe first number is %d\nSorting array: ", array[i]);

    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
