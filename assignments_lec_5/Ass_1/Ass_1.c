#include <stdio.h>

int main() {
    int numValues = 10;
    int values[numValues];

  
    printf("Enter Numbers: %d \n", numValues);
    for (int i = 0; i < numValues; i++) {
		printf("please enter the Number %d :",(i+1));
        scanf("%d", &values[i]);
    }

   
    int minimum = values[0];
    int maximum = values[0];

    for (int i = 1; i < numValues; i++) {
        if (values[i] < minimum) {
            minimum = values[i];
        }
        if (values[i] > maximum) {
            maximum = values[i];
        }
    }

  
    printf("Minimum value: %d\n", minimum);
    printf("Maximum value: %d\n", maximum);

    return 0;
}