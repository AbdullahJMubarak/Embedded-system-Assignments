#include <stdio.h>
int  get_max(int a,int b,int c,int d);
int  get_min(int a,int b,int c,int d);
void main (void){
	int a,b,c,d,max,min;
	printf("please enter the first number : " );
	scanf("%d",&a);
	printf("please enter the second number :");
	scanf("%d",&b);
	printf("please enter the Third number : " );
	scanf("%d",&c);
	printf("please enter the Fourth number :");
	scanf("%d",&d);
	max=get_max(a,b,c,d);
	min=get_min(a,b,c,d);
	printf("the Maximum number is %d\n",max);
	printf("the minimum number is %d\n",min);
}

int get_max(int a,int b,int c,int d)
{
	int max,i;
	max =a ;
	
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	if(d>max)
		max=d;
	
	return max;
	
}
int get_min(int a,int b,int c,int d)
{
	int min;
	min =a ;
	
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	if(d<min)
		min=d;
	
	return min;
	
}