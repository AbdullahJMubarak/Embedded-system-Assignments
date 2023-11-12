#include <stdio.h>

void main (void){
	int i,j,l,cnt ;
	int num;
	printf("Please enter the height of the pyramid :");
	scanf("%d",&num);
	for (i=0;i<num;i++)
	{
		j=i+2;
		while(j<=num)
		{
			printf(" ");
			j++;
		}
		l=2*num-(i);
		while(l<=2*num)
		{
			printf("*");
			l++;
		}
		for(cnt=0;cnt<i;cnt++)
			printf("*");
		printf("\n");
		
		
		
		
	}
		
	
	
}