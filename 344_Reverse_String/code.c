#include <stdlib.h>
#include <stdio.h>

#define sSize 6

int main(void)
{
    char s[sSize] = {'H', 'e', 'l', 'l', 'o', '!'};

    int i = 0, j = sSize - 1;
    int temp;
    for (int a = 0; a < sSize; a++)
    {
        printf("%c", s[a]);
    }

    while (i < j)
    {
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }

    for (int a = 0; a < sSize; a++)
    {
        printf("%c", s[a]);
    }
}