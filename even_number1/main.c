//deteriner la parite de a
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10, b = 2, c = 0;
    printf("a = %d\n", a);
    c = a % b;
    if(c == 0)
    {
        printf ("Le nombre a est pair\n");

    }
    else
    {
        printf ("Le nombre a est impair\n");
    }
    return 0;
}
