#include <stdio.h>

void getchar_putchar();
void gets_puts();
void scanf_demo();

int main() {

    getchar_putchar();
    gets_puts();
    scanf_demo();

    return 0;
}

void getchar_putchar(){
    int c;

    printf ("Type a character: ");
    c = getchar();
    printf ("char: %c\n",c);
    putchar(c);
    printf("\n");
}

void gets_puts(){
    printf("-----unsafe input-----\n");
    char name[256];

    printf ("Your name: ");
    gets (name);
    printf ("name: %s\n",name);
    puts(name);

    printf("-----fget() input-----\n");
    name[0] = '\0'; // clear
    printf ("Your name: ");
    fgets(name,256,stdin);
    printf ("name: %s\n",name);
    puts(name);
}

void scanf_demo(){
    int num;
    char c;
    char city[15];
    float dec;

    printf("Please enter an integer value: ");
    scanf("%d", &num );

    // %c ignores space characters
    printf("Please enter a character: ");
    scanf(" %c", &c );

    printf("Please enter a city name (no space): ");
    scanf("%s", city );

    printf("Please enter a decimal value:  ");
    scanf("%f", &dec );

    printf("\n-----result-------\n");
    printf("number = %d\n", num );
    printf("character = %c\n", c );
    printf("city name = %s\n", city );
    printf("decimal number = %f\n", dec );
}