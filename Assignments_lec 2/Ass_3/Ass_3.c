#include <stdio.h>

void main (void){
	int num1,num2,num3;
	printf("Enter the Number 1: ");
	scanf("%d",&num1);
	printf("Enter the Number 2: ");
	scanf("%d",&num2);
	printf("Enter the Number 3: ");
	scanf("%d",&num3);
	int max =num1;
	if(max < num2)
		max=num2;
	else if (max < num3 )
		max =num3;
	
	printf("Maximum number is %d",max);
	
	
}