#include <stdio.h>
#include <string.h>
#include "foc_fa21.h"
int destnation()
{
int j=1;
while(j!=0)//infinte loop only way to get out when the user inputs 4
{
		int country;
		printf("1. America\n2. Europe\n3. Africa\n4. Back\n");
		printf("Where is your destnation\n");	

		scanf("%d",&country);

		if(country==1)// works when the user inputed 1 this statement saves the name of the user when he writes it and check his  visa number if it valid or not
		{
		char first_name[14];
		int visa_number;
		FILE *america=fopen("america.txt","a");

		printf("Please enter your firstname\n");

		scanf("%s",first_name);

		fprintf(america,"first name= %s  ",first_name);//saves the name that the user wrote in a file

		printf("Enter you visa number 5 digits\n");

		scanf("%d",&visa_number);

		fprintf(america,"visa number=%d\n",visa_number);//saves the visa number the user wrote in a file

		if(visa_number>=12300&&visa_number<=12399)
		{
		if(visa_number>=12350&&visa_number<=12380)
		printf("Please go to counter number Four\n");
		else
		printf("Sorry! your visa needs to be validated please check that with the USA 			Embassy.\n");
		}

		else
		{
		printf("invald visa sorry :(\n");
		}
fclose(america);
		}

	else if(country==2)//checks the schengen number if its valid or not and tell the user where is his destantion
	{
	FILE* europe=fopen("europe.txt","a");

	int num;
	printf("Please enter you Schengen Number\n");

	scanf("%d",&num);

	fprintf(europe,"Schengen Number=%d\n",num);// saves schengen number in a file

	if(num<10)
	printf("Invald Schengen Number\n");

	else if(num<100)
	printf("Germany Widnow 10\n");

	else if(num<1000)
	printf("Italy Window 11\n");

	else if(num<10000)
	printf("Spain Window 12\n");

	else if(num>=10000)
	printf("Greece Window 13\n");

	else{
	printf("Invald Schengen Number\n");
	}
	fclose(europe);
	}

	else if(country==3)// shows the user an image to tell him where to go
	{
	FILE* africa=fopen("africa.txt","a");
	fprintf(africa,"1\n");
	printf("Please go this place\n");
	int arr[200][400];
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<400;j++)
		{
			if(i==100||j==200||i>=40&&i<=60&&j>=290&&j<=310)
			arr[i][j]=255;
			else
			arr[i][j]=0;
		}

	}
showArray(200,400,arr);
	fclose(africa);
	}

	else if(country==4)//quits from the loop and goes back to int main
	{
	j=0;
	}

	else
	printf("Try again\n");
}

}

int emp()
{
int j=1;
while(j!=0)//infinte loop only way to  get out when the user inputs 3
{
int y;
printf("1. Get Statistics\n2. Check name\n3. Back\n");
	
scanf("%d",&y);

if(y==1)//reads the lines in every file and counts how many line are there,then it adds the lines togther and get the precntage of every file in all files combined
{
	char nam[100];
	int amer=0,eu=0,afr=0;
	int arr[200][600];
	int total;
		
	FILE* am=fopen("america.txt","r");
	FILE* eur=fopen("europe.txt","r");	
	FILE* af=fopen("africa.txt","r");
		
	while(fscanf(am,"%s",nam)!=EOF)
	{
		amer=amer+1;
	}

	while(fscanf(eur,"%s",nam)!=EOF)
	{
		eu=eu+1;
	}
		
	while(fscanf(af,"%s",nam)!=EOF)
	{
	afr=afr+1;
	}
	total=amer+afr+eu;
	amer=amer*100/total;
	eu=eu*100/total;
	afr=afr*100/total;
	
	amer=200-amer;
	eu=200-eu;
	afr=200-afr;	
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<600;j++)
		{			
			arr[i][j]=255;

			if(i>=100&&i<200)
			{
				if(j==80||j==100||j==280||j==300||j==480||j==500)
				arr[i][j]=0;

			}
			
			if(i==100)
			{
				if((j>=80&&j<=100)||(j>=280&&j<=300)||(j>=480&&j<=500))
				arr[i][j]=0;
			}
			
			if(i>100&&i>amer)
			{
				if(j>=80&&j<=100)
				arr[i][j]=0;
			}
					
			if(i>100&&i>eu)
			{
				if(j>=280&&j<=300)
				arr[i][j]=0;
			}
			
			if(i>100&&i>afr)
			{
				if(j>=480&&j<=500)
				arr[i][j]=0;
			}
			
		}

		}
		showArray(200,600,arr);	
		fclose(am);fclose(eur);fclose(af);
		}

		else if(y==2)//compares the emploeyee inputed name to a file with names if the inputed name is found in the file it will say this name is allowed to travel not found not allowed
		{
		FILE* fp=fopen("names.txt","r");
		char num[10];
		char name[100];
		char filenames[100];
		printf("Enter a name> ");
		scanf("%s",name);
		int h=1;
		{
		while((fscanf(fp,"%s %s",filenames,num)!=EOF)&&(h==1))
		{
			if(strcmp(name,filenames)==0)
			{
				if(strcmp(num,"1")==0)
				{printf("%s is allowed to travel\n",name);
				h=0;
				}
				else
				{
				printf("%s is not allowed to travel\n",name);
				h=0;
				}
			}
		}
		
		fclose(fp);
		}
		if(h==1)
		printf("%s is not found\n",name);
		}
		else if(y==3)
		{
		j=0;
		}

		else
		printf("Try again\n");

}


}



int main()
{
printf("** Welcome to Queen Alia Airport **\n");
int i=1;
while(i!=0)//infinte loop only way to get out is when the user inputs 3 
{
int type;
	printf("1. Passenger\n2. Employee\n3. Quit\n");	
	printf("Select a choice> ");

	scanf("%d",&type);

	if(type==1)
	destnation();// tells the compiler to go to this function
	else if(type==2)
	{
		char password[40];
		printf("Enter Password:");
		scanf("%s",password);

		if(strcmp(password,"admin")==0)//checks if the password is corret or no if it is correct it tells it to go to of function if it is not it tells it to try again
		emp();
		else
		printf("Try again\n");
	}

	else if(type==3)
	return 0;//quits from the program

	else
	printf("Try again\n");//if the user inputed something out of the above
}
return 0;
}

