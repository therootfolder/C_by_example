#include <stdio.h>

int main() {
        int a,b;
        a = 10;
        b = 6;

        printf("%d == %d = %d\n",a,b,a==b);
        printf("%d != %d = %d\n",a,b,a!=b);
        printf("%d > %d = %d\n",a,b,a>b);
        printf("%d < %d = %d\n",a,b,a<b);
        printf("%d >= %d = %d\n",a,b,a>=b);
        printf("%d <= %d = %d\n",a,b,a<=b);

        return 0;
}