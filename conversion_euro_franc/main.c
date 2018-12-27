#include <stdio.h>
#include <stdlib.h>

double conversion (double nombreEuro)
{
    return nombreEuro * 6.55957;
}

int main()
{
    double nombreEuro = 0;

    printf ("\t\t\t====Couversion Euro Francs====\n\n");
    printf("Veillez entrer un nombre en euro\n");
    scanf("%lf", &nombreEuro);

    printf("%f euro = %f francs", nombreEuro, conversion(nombreEuro));

    return 0;
}
