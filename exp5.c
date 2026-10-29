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

    printf("Enter Dividend (Numerator): ");
    scanf("%d", &dividend);
    printf("Enter Divisor (Denominator): ");
    scanf("%d", &divisor);
    printf("Enter Number of Bits (e.g., 4): ");
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

    printf("\n========\n");
    printf("INITIAL STATE:\n");
    printf("A (Accumulator) = "); printInBinary(A, n); printf("\n");
    printf("Q (Dividend)    = "); printInBinary(Q, n); printf("\n");
    printf("M (Divisor)     = "); printInBinary(M, n); printf("\n");
    printf("Count           = %d\n", count);
    printf("==========\n");

    cycle_number = 1;
    while (count > 0) {
        printf("\n--- CYCLE %d ---\n", cycle_number);

        dropped_bit_from_Q = (Q >> (n - 1)) & 1;

        A = A << 1;
        A = A | dropped_bit_from_Q;

        Q = Q << 1;
        Q = Q & bit_mask;

        printf("Step 1: Shift Left (A, Q)\n");
        printf("        A = "); printInBinary(A, n); printf("\n");
        printf("        Q = "); printInBinary(Q, n); printf("\n");

        A = A - M;

        printf("Step 2: Subtract (A <- A - M)\n");
        printf("        A = "); printInBinary(A, n); printf("\n");

        if (A < 0) {
            printf("Step 3: Result is NEGATIVE (A < 0)\n");

            Q = Q & ~1;

            A = A + M;

            printf("        Action: Set Q0 = 0 and RESTORE A\n");
            printf("        A = "); printInBinary(A, n); printf("\n");
            printf("        Q = "); printInBinary(Q, n); printf("\n");
        }
        else {
            printf("Step 3: Result is POSITIVE (A >= 0)\n");

            Q = Q | 1;

            printf("        Action: Set Q0 = 1 (No Restoration needed)\n");
            printf("        Q = "); printInBinary(Q, n); printf("\n");
        }

        count = count - 1;
        printf("Step 4: Decrement Count\n");
        printf("        Count is now = %d\n", count);

        cycle_number++;
    }

    printf("\n========\n");
    printf("FINAL OUTPUT (END):\n");
    printf("==========\n");
    printf("Quotient (Found in Q)  = %d (Binary: ", Q); printInBinary(Q, n); printf(")\n");
    printf("Remainder (Found in A) = %d (Binary: ", A); printInBinary(A, n); printf(")\n");
    printf("==========\n");

    return 0;
}