/*
Проверить, является ли строка палиндромом — то есть,
читается ли она одинаково в обоих направлениях.
Заглавные и строчные буквы считаются разными,
пробелы должны игнорироваться. Пример палиндрома: "я иду с мечем судия".
Строку можно задать как константу в коде, можно сделать ввод с клавиатуры.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool palindrome(char *string)
{
    int lenght = strlen(string);
    int firstIndex = 0;
    int secondIndex = lenght - 1;
    bool flag = 1;

    while (firstIndex < secondIndex)
    {
        if (string[firstIndex] == ' ')
        {
            firstIndex++;
        }
        if (string[secondIndex] == ' ')
        {
            secondIndex--;
        }

        if (string[firstIndex] == string[secondIndex])
        {
            firstIndex++;
            secondIndex--;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void testOne()
{
    char *testingString = "do geese see god";
    bool answer = true;
    assert(palindrome(testingString) == answer);
}

void testTwo()
{
    char *testingString = "Hello World!";
    bool answer = false;
    assert(palindrome(testingString) == answer);
}

int main()
{
    testOne();
    testTwo();

    char *string = "was it a car or a cat i saw";
    int lenght = strlen(string);

    if (palindrome(string))
    {
        printf("This is a palindrome");
    }
    else
    {
        printf("This is not a palindrome");
    }

    return 0;
}
