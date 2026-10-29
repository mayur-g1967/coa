#include <stdio.h>

int main()
{
    int n, k = 5, i, j, c, total, nonpipe;
    char *stage[5] = {"IF", "ID", "EX", "MEM", "WB"};

    printf("Enter number of instructions: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Enter a number from 1 to 20\n");
        return 0;
    }

    total = k + n - 1;
    nonpipe = n * k;

    printf("\nPipeline timing diagram\n\n");
    printf("Instr ");
    for (c = 1; c <= total; c++)
        printf("C%-3d", c);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("I%-4d ", i + 1);
        for (c = 1; c <= total; c++)
        {
            j = c - i - 1;
            if (j >= 0 && j < k)
                printf("%-4s", stage[j]);
            else
                printf("%-4s", "-");
        }
        printf("\n");
    }

    printf("\nCycles without pipeline = %d\n", nonpipe);
    printf("Cycles with pipeline    = %d\n", total);
    printf("Speedup                 = %.2f\n", (float)nonpipe / total);

    return 0;
}