#include <stdio.h>

// Function prototypes
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
int and(int num1, int num2);
int or(int num1, int num2);
int not(int num);
int xor(int num1, int num2);
int reminder(int num1, int num2);
int increment(int num);
int decrement(int num);

int main() {
    int operationID, numOperands;
    float operand1, operand2;
    int intOperand1, intOperand2;
    
    printf("Simple Calculator\n");
    printf("Operations:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. And\n");
    printf("6. Or\n");
    printf("7. Not\n");
    printf("8. Xor\n");
    printf("9. Reminder\n");
    printf("10. Increment\n");
    printf("11. Decrement\n");
    
    printf("Enter the operation ID: ");
    scanf("%d", &operationID);
    
    switch (operationID) {
        case 1:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%f%f", &operand1, &operand2);
            printf("Result: %.2f\n", add(operand1, operand2));
            break;
            
        case 2:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%f%f", &operand1, &operand2);
            printf("Result: %.2f\n", subtract(operand1, operand2));
            break;
            
        case 3:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%f%f", &operand1, &operand2);
            printf("Result: %.2f\n", multiply(operand1, operand2));
            break;
            
        case 4:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%f%f", &operand1, &operand2);
            printf("Result: %.2f\n", divide(operand1, operand2));
            break;
            
        case 5:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%d%d", &intOperand1, &intOperand2);
            printf("Result: %d\n", and(intOperand1, intOperand2));
            break;
            
        case 6:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%d%d", &intOperand1, &intOperand2);
            printf("Result: %d\n", or(intOperand1, intOperand2));
            break;
            
        case 7:
            numOperands = 1;
            printf("Enter an operand: ");
            scanf("%d", &intOperand1);
            printf("Result: %d\n", not(intOperand1));
            break;
            
        case 8:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%d%d", &intOperand1, &intOperand2);
            printf("Result: %d\n", xor(intOperand1, intOperand2));
            break;
            
        case 9:
            numOperands = 2;
            printf("Enter two operands: ");
            scanf("%d%d", &intOperand1, &intOperand2);
            printf("Result: %d\n", reminder(intOperand1, intOperand2));
            break;
            
        case 10:
            numOperands = 1;
            printf("Enter an operand: ");
            scanf("%d", &intOperand1);
            printf("Result: %d\n", increment(intOperand1));
            break;
            
        case 11:
            numOperands = 1;
            printf("Enter an operand: ");
            scanf("%d", &intOperand1);
            printf("Result: %d\n", decrement(intOperand1));
            break;
            
        default:
            printf("Invalid operation ID.\n");
    }
    
    return 0;
}

float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    return num2 != 0 ? num1 / num2 : 0;
}

int and(int num1, int num2) {
    return num1 & num2;
}

int or(int num1, int num2) {
    return num1 | num2;
}

int not(int num) {
    return ~num;
}

int xor(int num1, int num2) {
    return num1 ^ num2;
}

int reminder(int num1, int num2) {
    return num1 % num2;
}

int increment(int num) {
    return num + 1;
}

int decrement(int num) {
    return num - 1;
}
