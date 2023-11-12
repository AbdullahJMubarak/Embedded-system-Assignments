#include <stdio.h>

void main (void){
int id,password;

printf("Please enter the ID:");
scanf("%d",&id);
switch(id)
{
	case 2030: 
	printf("Please enter the password");
	scanf("%d",&password);
	if(password == 1234)
		printf("welcomme Mohamed ");
	else 
			printf("wrong password");
	break;
	case 5060: 
		printf("Please enter the password");
		scanf("%d",&password);
		if(password == 5678)
			printf("welcomme youssef ");
		else 
			printf("wrong password: ");
	break;
	case 7080: 
		printf("Please enter the password: ");
		scanf("%d",&password);
		if(password == 9999)
			printf("welcomme Mahmoud ");
		else 
			printf("wrong password:");
	break;
	case 9010: 
		printf("Please enter the password:");
		scanf("%d",&password);
		if(password == 9632)
			printf("welcomme Kalid ");
		else 
			printf("wrong password");
	break;
	case 5050: 
		printf("Please enter the password");
		scanf("%d",&password);
		if(password == 1234)
			printf("welcomme Said ");
		else 
			printf("wrong password");
	break;
	default:
	printf("incorrect ID");
	break;
	
	
	
	
	
}
	
	
}