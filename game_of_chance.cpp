
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h> //  header file for gotoxy; will of course work only on windows machines

const int CONTINUE = 2;
const int WON = 1;
const int LOST = 0;
COORD coord={0,0}; // this is global variable
                    //center of axis is set to the top left cornor of the screen
void gotoxy(int , int);
void rollEffect(int, int);
int rollDice(void);
int game();
void showBalance(int);
int main(void)
{
    int balance = 1000;
    int wage;
    char ch;
    printf("Game of Chance:\n1. First Throw: If sum of dice 7 or 11 you win, else if 2, 3, 12 you lose.\nIf sum 4,5,6,8,9,10 then it becomes your 'point'.\n");
    printf("2. Program randomly keeps on throwing dice, till sum not equal to point i.e. you win \nor 7 is encountered, in which case you'll loose.\n");
    getchar();

    srand( time( NULL ) );
    printf("Initial Balance is $1000!!!\n");
    do{
        gotoxy(0,7);
        printf("Enter your Wage: ");
        scanf("%d",&wage);

        if(game())
        {   gotoxy(0,12);
            balance += wage;
            printf("You're up big. Now's the time to cash in your chips!  \n");
        }
        else{
            gotoxy(0,12);
            balance -= wage;
            printf("Oh, you're going for broke, huh?                      \n");
        }
        showBalance(balance);
        printf("Still feeling lucky? (y/n) :");
        fflush(stdin);
        scanf("%c",&ch);
    }while(balance>=wage && ch=='y');
    if(balance < wage)
        printf("Try your luck tomorrow.\n");
    getchar();
    return 0;
}
int game()
{   int sum;
    int myPoint;
    int gameStatus;

    //simulate first throw
    sum = rollDice();
    switch(sum){
    /* win on first roll */
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sum;
            printf("Point is %d       \n", myPoint);
            break;
    }
    //simulate successive throws
    while(gameStatus == CONTINUE){
        Sleep(300);      //wait after each throw to make it noticeable
        sum = rollDice();
        if(sum == myPoint ){
            gameStatus = WON;
        }
        else if(sum == 7){
            gameStatus = LOST;
        }
    }

    if( gameStatus == WON ){
        printf("Player Wins!!      \n");
    }
    else{
        printf("Player loses... :(\n");
    }
    return gameStatus;
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

// produces rolling effect at (x,y) coordinates
void rollEffect(int x, int y)
{
    int i=1;
    gotoxy(x,y);
    for(i=1; i<=9; ++i)
    {   printf("%d",i);
        Sleep(300);    //Sleep(sleep_for_x_milliseconds)
        gotoxy(x,y);
    }
}

void showBalance(int balance)
{
    gotoxy(60,6);
    printf("Balance: %d   ", balance);
    gotoxy(0,13);
}

int rollDice(void)
{
    int die1;
    int die2;
    int workSum;
    die1 = 1 + ( rand() % 6);
    die2 = 1 + ( rand()% 6);
    workSum = die1 + die2;

    rollEffect(34,9);
    printf("%d",die1);

    rollEffect(64,9);
    printf("%d",die2);
    getchar();
    gotoxy(0,10);
    printf("Player rolled %d + %d = %d \n", die1 , die2, workSum);      //don't remove space after the last %d otherwise bad output for 2 digit numbers preceding 1 digit no.
    return workSum;
}
