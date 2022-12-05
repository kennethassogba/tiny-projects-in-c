#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 42, b = 22;
    printf("a = %d, b = %d\n", a, b);
    if (a > b)
    {
        printf("max(a,b)=a\n");
    }
    else
    {
        printf("max(a,b)=b\n");
    }
    return 0;
}
