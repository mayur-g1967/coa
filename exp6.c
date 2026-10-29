#include <stdio.h>

void printInBinary(int number, int total_bits) {
    int i, current_bit;
    for (i = total_bits - 1; i >= 0; i--) {
        current_bit = (number >> i) & 1;
        printf("%d", current_bit);
    }
}

int main() {
    int dividend, divisor, n;
    int A, M, Q, count;
    int cycle_number, dropped_bit_from_Q, bit_mask;

    printf("Enter Dividend: ");
    scanf("%d", &dividend);
    printf("Enter Divisor: ");
    scanf("%d", &divisor);
    printf("Enter Number of Bits: ");
    scanf("%d", &n);

    if (n < 1 || n > 10 || divisor <= 0 || dividend < 0
        || dividend >= (1 << n) || divisor >= (1 << n)) {
        printf("Invalid input\n");
        return 0;
    }

    A = 0;
    M = divisor;
    Q = dividend;
    count = n;
    bit_mask = (1 << n) - 1;

    printf("\nNon-Restoring Division Algorithm\n\n");
    printf("Initial values\n");
    printf("A     = "); printInBinary(A, n); printf("\n");
    printf("Q     = "); printInBinary(Q, n); printf("\n");
    printf("M     = "); printInBinary(M, n); printf("\n");
    printf("Count = %d\n", count);

    cycle_number = 1;
    while (count > 0) {
        printf("\nCycle %d\n", cycle_number);

        dropped_bit_from_Q = (Q >> (n - 1)) & 1;

        A = A << 1;
        A = A | dropped_bit_from_Q;

        Q = Q << 1;
        Q = Q & bit_mask;

        printf("Shift left A,Q  ->  A = "); printInBinary(A, n);
        printf("  Q = "); printInBinary(Q, n); printf("\n");

        if (A >= 0) {
            A = A - M;
            printf("A was positive  ->  A = A - M\n");
        }
        else {
            A = A + M;
            printf("A was negative  ->  A = A + M\n");
        }

        printf("                    A = "); printInBinary(A, n); printf("\n");

        if (A >= 0) {
            Q = Q | 1;
            printf("A is positive   ->  Q0 = 1\n");
        }
        else {
            Q = Q & ~1;
            printf("A is negative   ->  Q0 = 0\n");
        }

        printf("                    A = "); printInBinary(A, n);
        printf("  Q = "); printInBinary(Q, n); printf("\n");

        count = count - 1;
        printf("Count = %d\n", count);

        cycle_number++;
    }

    printf("\nFinal correction\n");
    if (A < 0) {
        printf("A is negative   ->  A = A + M\n");
        A = A + M;
        printf("                    A = "); printInBinary(A, n); printf("\n");
    }
    else {
        printf("A is positive, no correction needed\n");
    }

    printf("\nResult\n");
    printf("Quotient  = %d  (", Q); printInBinary(Q, n); printf(")\n");
    printf("Remainder = %d  (", A); printInBinary(A, n); printf(")\n");

    return 0;
}