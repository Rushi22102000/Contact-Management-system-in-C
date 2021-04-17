#include<stdio.h>

#include<conio.h>

struct book
{
	char name[100];
	int phone;
	char address[100];
	char email[100];
}b,b1;

int main()

{
    int ch=0;
    char v;
    dd:
    main:
    system("cls");    /* ************Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)
    {
    case 0:
		{system("cls");
		char v;
        printf("\n\n\t\tAre you sure you want to exit?(Y/N)");
        scanf("\n%c",&v);
        if(v=='N')
		{
			goto dd;
		}
		break;
	}

    case 1:
    	{
		system("cls");
		FILE *fp;
		fp=fopen("contact.txt","a+");
	    for(;;)
	    {
		fflush(stdin);
		printf("Enter Name:");
		gets(b.name);
		printf("Enter Phone:");
		scanf("\n%d",&b.phone);
		fflush(stdin);
		printf("Enter address:");
		gets(b.address);
		fflush(stdin);
		printf("Enter Email:");
		gets(b.email);
		fflush(stdin);
	    fprintf(fp,"%s %d %s %s\n",b.name,&b.phone,b.address,b.email);
	    
	    printf("try again?Y/N");
		scanf("\n%c",&v);
		if(v=='N')
		{
			fclose(fp);
			break;
		}
		}
		goto main;
		break;
		}
		
   case 2:
    	{
		system("cls");
		FILE *fp;
		printf("Name\tPhone\tAddress\tE-mail\n");
		fp=fopen("contact.txt","r");
    	while(fscanf(fp,"%s %d %s %s\n",b.name,&b.phone,b.address,b.email)!=EOF)
    	{printf("%s\t%d\t%s\t%s\n",b.name,&b.phone,b.address,b.email);}
    	
		fclose(fp);
		getch();
		goto main;
		break;
	}

    case 3:
    	{
    	hh:
			system("cls");
			char v;
		FILE *fp;
		fp=fopen("contact.txt","r");
		
			
		printf("Enter name whose data want:");
		scanf("%s",b1.name);
		
		while(fscanf(fp,"%s %d %s %s\n",b.name,&b.phone,b.address,b.email)!=EOF)
    	{
    		if(strcmpi(b.name,b1.name)==0)
    		{			
				printf("Name:   %s",b.name);
    			printf("\nPhone:  %d",b.phone);
				printf("\nAddress:%s",b.address);
				printf("\nE-mail: %s\n\n",b.email);
			}
    }
    
    if(strcmpi(b.name,b1.name)!=0)
			{
				printf("Account Not found!");
			}
			
    printf("try again?Y/N");
		scanf("\n%c",&v);
		if(v=='Y')
		{
	goto hh;
		}
	fclose(fp);	
    break;
		
		}

    case 4:
    {
    	hhh:
    	system("cls");
    	int choice=0;
		int upphone=0;
    	char sy[100],add[100],mai[100];
		char x[100],v;
		FILE *fp,*newfp;
		fp=fopen("contact.txt","r");		
		newfp=fopen("coma.txt","a+");
		printf("Enter name whose data want to edit:");
		scanf("%s",b1.name);

		while(fscanf(fp,"%s %d %s %s\n",b.name,&b.phone,b.address,b.email)!=EOF)
    	{
    		if(strcmpi(b.name,b1.name)==0)
    		{			
				
			printf("\nWhich information do you want to change?\n1.Name\n2.Phone\n3.address\n4.email\n\nEnter your choice:");
            scanf("%d",&choice);
			if(choice==1)
			{
			system("cls");
			printf("Enter name to edit:");
			scanf("%s",sy);
			fprintf(newfp,"%s %d %s %s\n",sy,&b.phone,b.address,b.email);
			system("cls");
            printf("Changes saved!");
			}
			if(choice==2)
			{system("cls");
				
			printf("Enter phone to edit:");
			scanf("%d",&upphone);
			fprintf(newfp,"%s %d %s %s\n",b.name,&upphone,b.address,b.email);
			system("cls"); 
            printf("Changes saved!");
			}

			if(choice==3)
			{system("cls");
			printf("Enter phone to edit:");
			scanf("%s",add);
			fprintf(newfp,"%s %d %s %s\n",b.name,&b.phone,add,b.email);
			system("cls"); 
            printf("Changes saved!");
			}
			
			if(choice==4)
			{system("cls");
			printf("Enter phone to edit:");
			scanf("%s",mai);
			fprintf(newfp,"%s %d %s %s\n",b.name,&b.phone,b.address,mai);
			system("cls"); 
            printf("Changes saved!");
			}
			
			}
			
    }
    if(strcmpi(b.name,b1.name)!=0)
			{
				printf("Account Not found!");
			}
    
    printf("\nwanna continue?Y/N");
	scanf("\n%c",&v);
	if(v=='Y'){goto hhh;}
	
    fclose(fp);
    fclose(newfp);
    remove("contact.txt");
    rename("coma.txt","contact.txt");
    break;
    
}


    case 5:
    	{
    	hhhh:
    	system("cls");
    	FILE *fp,*newfp;
		fp=fopen("contact.txt","r");		
		newfp=fopen("coma.txt","a+");
		
    	printf("Enter name whose data want to edit:");
		scanf("%s",b1.name);
		while(fscanf(fp,"%s %d %s %s\n",b.name,&b.phone,b.address,b.email)!=EOF)
    	{
    		if(strcmpi(b.name,b1.name)==0)
    		{	
    		continue;
    	}
    	fprintf(newfp,"%s %d %s %s\n",b.name,&b.phone,b.address,b.email);
		
		}if(strcmpi(b.name,b1.name)!=0)
			{
				printf("Account Not found!");
			}
		
	printf("\nwanna continue?Y/N");
	scanf("\n%c",&v);
	if(v=='Y'){goto hhhh;}
	
    fclose(fp);
    fclose(newfp);
    remove("contact.txt");
    rename("coma.txt","contact.txt");
    break;
    
    }


}}
