#include <stdio.h>

int main()
{
    int mem[100], stack[10];
    int ax = 0, bx = 10, cf = 0, sp = 0;
    int choice, i, a, d;

    /* Initialize memory */
    for (i = 0; i < 100; i++)
        mem[i] = i * 10;

    do
    {
        printf("\nAX = %d  BX = %d  CF = %d  SP = %d\n",
               ax, bx, cf, sp);

        printf("\n--- Addressing Modes ---\n");
        printf("1. Implied Addressing\n");
        printf("2. Immediate Addressing\n");
        printf("3. Direct Addressing\n");
        printf("4. Register Addressing\n");
        printf("5. Register Indirect Addressing\n");
        printf("6. Displacement Addressing\n");
        printf("7. Stack PUSH AX\n");
        printf("8. Stack POP AX\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* Implied addressing */
            cf = !cf;
            printf("CMC simulated. CF = %d\n", cf);
            break;

        case 2:
            /* Immediate addressing */
            ax = 25;
            printf("MOV AX, 25 simulated. AX = %d\n", ax);
            break;

        case 3:
            /* Direct addressing */
            printf("Enter memory address (0-99): ");
            scanf("%d", &a);

            if (a < 0 || a >= 100)
                printf("Invalid address\n");
            else
            {
                ax = mem[a];
                printf("AX = MEM[%d] = %d\n", a, ax);
            }
            break;

        case 4:
            /* Register addressing */
            ax = bx;
            printf("MOV AX, BX simulated. AX = %d\n", ax);
            break;

        case 5:
            /* Register indirect addressing */
            if (bx < 0 || bx >= 100)
                printf("BX is out of range\n");
            else
            {
                ax = mem[bx];
                printf("AX = MEM[BX] = %d\n", ax);
            }
            break;

        case 6:
            /* Displacement addressing */
            printf("Enter displacement: ");
            scanf("%d", &d);

            a = bx + d;

            if (a < 0 || a >= 100)
                printf("Effective address is out of range\n");
            else
            {
                ax = mem[a];
                printf("Effective Address = BX + displacement = %d\n", a);
                printf("AX = MEM[%d] = %d\n", a, ax);
            }
            break;

        case 7:
            /* Stack PUSH */
            if (sp >= 10)
                printf("Stack overflow\n");
            else
            {
                stack[sp] = ax;
                sp++;
                printf("PUSH AX completed\n");
            }
            break;

        case 8:
            /* Stack POP */
            if (sp <= 0)
                printf("Stack underflow\n");
            else
            {
                sp--;
                ax = stack[sp];
                printf("POP AX completed. AX = %d\n", ax);
            }
            break;

        case 0:
            printf("Program terminated\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
