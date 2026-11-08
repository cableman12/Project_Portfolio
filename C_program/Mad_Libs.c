#include <stdio.h>
#include <stdlib.h>

int main()
{

    char color[20];
    char PluralNoun[20];
    char personF[20];
    char personL[20];


    printf("Enter a color: ");
    scanf("%s", color);
    printf("Enter a plural noun: ");
    scanf("%s", PluralNoun);
    printf("Enter a person: ");
    scanf("%s %s", personF, personL);

    printf("Roses are %s\n", color);
    printf("%s are blue\n", PluralNoun);
    printf("I love %s %s\n", personF, personL);

}