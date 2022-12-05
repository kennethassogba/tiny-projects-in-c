// gcc -Wall sizeof.c -o sizeof.exe

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 10;
	int i = 10;
	short s = 10;
	long l = 10;
	long long ll = 10;
	float f = 10.0;
	double d = 10.0;

	printf("!!!hello la classe preparatoire!!!\n");
	printf("\tchar: sizeof %zu\n", sizeof(char));
	printf("\tint: sizeof %zu\n", sizeof(int));
	printf("\tshort: sizeof %zu\n", sizeof(short));
	printf("\tlong: sizeof %zu\n", sizeof(long));
	printf("\tlong long: sizeof %zu\n", sizeof(long long));
	printf("\tfloat: sizeof %zu\n", sizeof(float));
	printf("\tdouble: sizeof %zu\n", sizeof(double));

	printf("voici les valeurs de mes variables:\n");
	printf("\tchar - val: %d\n", c);
	printf("\tint - val: %d\n", i);
	printf("\tshort - val: %d\n", s);
	printf("\tlong - val: %ld\n", l);
	printf("\tlong long - val: %lld\n", ll);
	printf("\tfloat - val: %f\n", f);
	printf("\tdouble - val: %f\n", d);

	printf("voici mes operateurs arithmetique par ordre de priorite:\n");
	printf("\t -, + binaire\n");
	printf("\t *, /, %%\n");
	printf("\t-, + unaire\n");

	printf("voici mes operateurs logique et de comparaison\n"
	"(moins prioritaires que les operateurs arithmetiques):\n");
	printf("\t ==, !=\n");
	printf("\t-, <,<=, >, >=\n");
	printf("\t-, &&, unaire\n");

    return 0;
}
