#include<stdio.h>
#include<string.h>
#include<windows.h> //  header file for gotoxy; will of course work only on windows machines

int main()
{   char user_name[20],pass[20],c;
    char opass[] = "password";
    int pos=0;
    printf("Enter a username: ");
    scanf("%s", user_name);
    fflush(stdout);
    c = '0';        //give some value to remove the garbage value stored in c

    while( c != 13)   //13 is ASCII value of enter key
    {   c = getch();
        printf("%c",c);
    	pass[pos++] = c;
        Sleep(500);
        printf("\b*");
    }
    printf("\nPlease wait verifying your credentials...\n");
   	Sleep(2000);
    pass[--pos] = '\0';
    if( strcmp(opass,pass) == 0 )       //checks if two strings are equal where "ABC" != "abc" , i.e. case-sensitive
        printf("Access granted\n");
    else
        printf("Try again....\n");
    return 0;
}
