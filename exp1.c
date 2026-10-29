#include <stdio.h>

long binaryToDecimal(char *bin)
{
    long dec = 0;
    int i;
    for (i = 0; bin[i] != '\0'; i++)
    {
        if (bin[i] != '0' && bin[i] != '1')
            return -1;
        dec = dec * 2 + (bin[i] - '0');
    }
    return dec;
}

int octalToBinary(char *oct)
{
    char *map[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    int i;
    for (i = 0; oct[i] != '\0'; i++)
        if (oct[i] < '0' || oct[i] > '7')
            return 0;
    printf("Binary = ");
    for (i = 0; oct[i] != '\0'; i++)
        printf("%s", map[oct[i] - '0']);
    printf("\n");
    return 1;
}

int main()
{
    int choice;
    long result;
    char num[32];
    char ch;

    printf("1. Binary to Decimal\n2. Octal to Binary\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter binary number (max 31 digits): ");
        scanf("%31s", num);
        result = binaryToDecimal(num);
        if (result == -1)
            printf("Invalid binary number\n");
        else
            printf("Decimal = %ld\n", result);
        break;
    case 2:
        printf("Enter octal number (max 31 digits): ");
        scanf("%31s", num);
        if (!octalToBinary(num))
            printf("Invalid octal number\n");
        break;
    default:
        printf("Invalid choice\n");
    }

    printf("Press Enter to exit...");
    scanf("%c", &ch);
    scanf("%c", &ch);
    return 0;
}