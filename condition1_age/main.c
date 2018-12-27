#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 0;
    printf("Veillez enter votre age\n");
    scanf("%d", &age);
    if(age >= 18)
    {
        printf("Vous etes majeur\n");
    }
    return 0;
}
