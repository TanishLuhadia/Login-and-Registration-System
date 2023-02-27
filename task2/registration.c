#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct User
{
char username[56];
char password[56];
};
void printLine(char g,int size)
{
int i;
for(i=1;i<=size;i++) printf("%c",g);
printf("\n");
}
void doRegistration()
{
FILE *f;
struct User t,g;
char name[56];
char m;
int h;
int x;
char passcode1[56];
char passcode2[56];
printf("Please enter your username :  ");
fgets(name,56,stdin);
name[strlen(name)-1]='\0';
fflush(stdin);
printf("Username : %s\n",name);
printf("Confirm\n");
printf("[1] Yes\n");
printf("[2] No\n");
scanf("%d",&h);
fflush(stdin);
if(h!=1)
{
printf("User not registered\n");
return;
}

f=fopen("registration.dat","rb");
if(f!=NULL)
{
while(1)
{
fread(&t,sizeof(struct User),1,f);
if(feof(f)) break;
if(strcmp(t.username,name)==0)
{
printf("That username is not available\n");
fclose(f);
return;
}
}
fclose(f);
}
printf("Please enter the password: ");
fgets(passcode1,56,stdin);
passcode1[strlen(passcode1)-1]='\0';
fflush(stdin);
printf("Please renter the password: ");
fgets(passcode2,56,stdin);
passcode2[strlen(passcode2)-1]='\0';
fflush(stdin);
x=strcmp(passcode1,passcode2);
if(x!=0)
{
printf("Password doesnt match\n");
return ;
}
strcpy(g.username,name);
strcpy(g.password,passcode1);
f=fopen("registration.dat","ab");
fwrite(&g,sizeof(struct User),1,f);
fclose(f);
printf("User registered sucessfully, press enter to continue.............");
getchar();
fflush(stdin);
}
void login()
{
FILE *f;
struct User t;
char name[56];
char passcode[56];
printf("Login Page\n");
printf("Enter username :  ");
fgets(name,56,stdin);
name[strlen(name)-1]='\0';
fflush(stdin);
f=fopen("registration.dat","rb");
if(f==NULL)
{
printf("Invalid username\n");
return;
}
int found=0;
char m;
while(1)
{
fread(&t,sizeof(struct User),1,f);
if(feof(f)) break;
if(strcmp(t.username,name)==0)		
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Username doesn't exist\n");
return ;
}
printf("Please enter the password: ");
fgets(passcode,56,stdin);
passcode[strlen(passcode)-1]='\0';
fflush(stdin);
found=0;
f=fopen("registration.dat","rb");
if(f==NULL)
{
printf("Invalid username\n");
return;
}
while(1)
{
fread(&t,sizeof(struct User),1,f);
if(feof(f)) break;
if(strcmp(t.username,name)==0)		
{
found=1;
break;
}
}
fclose(f);
if(strcmp(t.password,passcode)!=0)
{
printf("Incorrect password\n");
return ;
}
printf("Logged in successfully, press enter to continue.....................");
getchar();
fflush(stdin);
}
int main()
{
int ch;
printf("WELCOME------TO------LOGIN------REGISTRATION------SYSTEM\n\n");
while(1)
{
printf("Hello, Would you like to log in or register\n");
printf("1. Login\n");
printf("2. Register\n");
printf("3. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
login();
}else if(ch==2)
{
doRegistration();
}else if(ch==3)
{
break;
}
else 
{
printf("Invalid choice \n");
return 0;
}
}
return 0;
}