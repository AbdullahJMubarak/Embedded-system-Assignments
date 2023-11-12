#include <stdio.h>

void main (void){
int id,password;
int i;
printf("Please enter the ID:");
scanf("%d",&id);
switch(id)
{
	case 1234: 
		printf("Please enter the password: ");
		scanf("%d",&password);
			for( i=0;i<2;i++){
				if(password == 7788){
					printf("welcomme Ahmed ");
					break;
									}
		printf("Try again ");
		scanf("%d",&password);
								}
	if(i==2)
		printf("Incorrect password for 3 Times, no tries any more");
	break;
	case 5678: 
		printf("Please enter the password: ");
		scanf("%d",&password);
		for( i=0;i<2;i++){
			if(password == 5566){
				printf("welcomme Amr ");
					break;
					}
				printf("Try again ");
				scanf("%d",&password);
								}
		if(i==2)
			printf("Incorrect password for 3 Times, no tries any more");
	break;
	case 9870: 
			printf("Please enter the password: ");
			scanf("%d",&password);
			for( i=0;i<2;i++){
				if(password == 1122){
					printf("welcomme Wael ");
					break;
									}
			printf("Try again ");
			scanf("%d",&password);
								}
	if(i==2)
		printf("Incorrect password for 3 Times, no tries any more");
	break;
	
	default:
	printf("Your are not registered");
	break;
	
	
	
	
	
}
	
	
}