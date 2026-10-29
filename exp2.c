#include <stdio.h>
#include <string.h>

int main()
{
    char num[33], ones[33], twos[33];
    int i, len, carry = 1, ok = 1;

    printf("Enter a binary number: ");
    scanf("%32s", num);
    len = strlen(num);

    for (i = 0; i < len; i++)
        if (num[i] != '0' && num[i] != '1')
            ok = 0;

    if (!ok)
        printf("Invalid binary number\n");
    else
    {
        for (i = 0; i < len; i++)
            ones[i] = (num[i] == '0') ? '1' : '0';
        ones[len] = '\0';

        for (i = len - 1; i >= 0; i--)
        {
            if (carry == 1 && ones[i] == '1')
                twos[i] = '0';
            else if (carry == 1 && ones[i] == '0')
            {
                twos[i] = '1';
                carry = 0;
            }
            else
                twos[i] = ones[i];
        }
        twos[len] = '\0';

        printf("1's complement = %s\n", ones);
        printf("2's complement = %s\n", twos);
    }
    return 0;
}