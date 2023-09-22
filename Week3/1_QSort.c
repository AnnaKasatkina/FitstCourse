/*
1. Умный QSort
Реализовать qsort, который для сортировки кусков массива 
размером меньше 10 использует сортировку вставкой. 
Поскольку qsort делит массив на части и сортирует каждую qsort-ом же, 
можно добиться заметного ускорения, если совсем уж маленькие части сортировать 
квадратичной сортировкой с меньшей константой. Эту идею и надо реализовать.
*/

#include <stdio.h>
#include <malloc.h>

void printing(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int main(void)
{
    int lenght = 0;
    printf("Enter lenght of array: ");
    scanf("%d", &lenght);

    int *array = calloc(lenght, sizeof(int));

    free(array);
    return 0;
}
