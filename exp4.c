#include <stdio.h>
#include <string.h>

int toNum(char *s, int base, int max)
{
    int n = 0;
    int i, d;

    if (strlen(s) > max)
        return -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            d = s[i] - '0';

        else if (s[i] >= 'A' && s[i] <= 'F')
            d = s[i] - 'A' + 10;

        else if (s[i] >= 'a' && s[i] <= 'f')
            d = s[i] - 'a' + 10;

        else
            return -1;

        if (d >= base)
            return -1;

        n = n * base + d;
    }

    return n;
}

void show(int n, int base)
{
    char s[40];
    int i = 0;

    if (n < 0)
    {
        printf("-");
        n = -n;
    }

    do
    {
        s[i] = "0123456789ABCDEF"[n % base];
        i++;

        n = n / base;

    } while (n > 0);

    while (i > 0)
    {
        i--;
        printf("%c", s[i]);
    }
}

int main()
{
    char x[32], y[32];
    int a, b;
    int choice, base, max;

    printf("1. Binary\n2. Hexadecimal\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            base = 2;
            max = 30;
            break;

        case 2:
            base = 16;
            max = 7;
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("Enter first number: ");
    scanf("%31s", x);

    printf("Enter second number: ");
    scanf("%31s", y);

    a = toNum(x, base, max);
    b = toNum(y, base, max);

    if (a < 0 || b < 0)
    {
        printf("Invalid number\n");
        return 0;
    }

    printf("Sum        = ");
    show(a + b, base);

    printf("\nDifference = ");
    show(a - b, base);

    printf("\n");

    return 0;
}
