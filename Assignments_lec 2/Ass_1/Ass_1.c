#include <stdio.h>

void main (void){
	int no1 ,no2,no3,no4,no5,no6,no7,no8,no9,no10;
	printf("plase enter the Number 1:");
	scanf("%d",&no1);
	printf("plase enter the Number 2:");
	scanf("%d",&no2);
	printf("plase enter the Number 3:");
	scanf("%d",&no3);
	printf("plase enter the Number 4:");
	scanf("%d",&no4);
	printf("plase enter the Number 5:");
	scanf("%d",&no5);
	printf("plase enter the Number 6:");
	scanf("%d",&no6);
	printf("plase enter the Number 7:");
	scanf("%d",&no7);
	printf("plase enter the Number 8:");
	scanf("%d",&no8);
	printf("plase enter the Number 9:");
	scanf("%d",&no9);
	printf("plase enter the Number 10:");
	scanf("%d",&no10);
	
	
	int search;
	printf("please enter number to search");
	scanf("%d",&search);
	
	if (no1 == search ){
		printf("The Value exists at the element Number : 1");
	}else if (no2 == search ){
		printf("The Value exists at the element Number : 2");
	}else if (no3 == search ){
		printf("The Value exists at the element Number : 3");
	}else if (no4 == search ){
		printf("The Value exists at the element Number : 4");
	}else if (no5 == search ){
		printf("The Value exists at the element Number : 5");
	}else if (no6 == search ){
		printf("The Value exists at the element Number : 6");
	}else if (no7 == search ){
		printf("The Value exists at the element Number : 7");
	}else if (no8 == search ){
		printf("The Value exists at the element Number : 8");
	}else if (no9 == search ){
		printf("The Value exists at the element Number : 9");
	}else if (no10 == search ){
		printf("The Value exists at the element Number : 10");
	}else {
		printf("The value doesn't exist");
	}
	
}