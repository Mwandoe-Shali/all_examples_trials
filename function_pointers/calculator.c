#include <stdio.h>

/* prototypes for functions used */
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int main() {
    int (*ptOperator[])(int, int) = {add, subtract, divide, multiply}; 

    /* A pointer to an array of functions that take in two integer arguments and returns an integer */

    printf("Which operation do you want to perform? Press\n 0 for add\n 1 for subtract\n 2 for divide\n 3 for multiply\n\n");
    int choice;
    
    // Keep prompting the user until a valid choice is entered
    while (1) {
        printf("What do you choose: ");
        scanf("%d", &choice);

        // Check if the choice is within the valid range (0 to 3)
        if (choice >= 0 && choice <= 3) {
            break; // Valid choice, exit the loop
        } else {
            printf("Invalid input, try again.\n");
        }
    }

    printf("Enter the first operand: ");
    int operand1;
    scanf("%d", &operand1);

    printf("Enter the second operand: ");
    int operand2;
    scanf("%d", &operand2);

    int result =  (ptOperator[choice])(operand1, operand2);

    // Print the values of the operands, operator, and result in one line
    printf("%d %c %d = %d\n", operand1, "+-*/"[choice], operand2, result);

    return 0;
}

/* defining the various functions */
int add(int x, int y){
    return (x + y);
}

int subtract(int x, int y){
    return (x - y);
}

int multiply(int x, int y){
    return (x * y);
}

int divide(int x, int y){
    return (x / y);
}

