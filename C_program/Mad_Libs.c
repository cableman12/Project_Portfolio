#include <stdio.h>
#include <stdlib.h>

int main()
{

    char color[20];
    char PluralNoun[20];
    char person[20];

    printf("Enter a color: ");
    scanf("%s", color);
    printf("Enter a plural noun: ");
    scanf("%s", PluralNoun);
    printf("Enter a person: ");
    scanf("%s", person);

    printf("Roses are %s\n", color);
    printf("%s are blue\n", PluralNoun);
    printf("I love %s\n", person);

}