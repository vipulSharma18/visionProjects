#include<windows.h>     //  header file for gotoxy
#include <stdio.h>      //header file for standard input output

COORD coord={0,0};      // this is global variable
                        //center of axis is set to the top left corner of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void draw_board()
{
    //Draw intersections
    gotoxy(60,10);
    printf("%c",197);
    gotoxy(60,12);
    printf("%c",197);
    gotoxy(64,10);
    printf("%c",197);
    gotoxy(64,12);
    printf("%c",197);

    //Draw horizontal lines
    for(int x=56;x<=68;x++)
    {
        if(x!=60&&x!=64)
        {
           gotoxy(x,10);
           printf("%c",196);
           gotoxy(x,12);
           printf("%c",196);
        }
    }

    //Draw vertical lines
    for(int y=8;y<=14;y++)
    {
        if(y!=10&&y!=12)
        {
           gotoxy(60,y);
           printf("%c",179);
           gotoxy(64,y);
           printf("%c",179);
        }
    }

}

void draw_players()
{
    gotoxy(20,2);
    printf("Player - 1");
    gotoxy(24,3);
    printf("(x)");
    gotoxy(90,2);
    printf("Player - 2");
    gotoxy(94,3);
    printf("(0)");
}

void display_result(int result)
{
    if(result)
    {
        gotoxy(55,18);
        printf("Player %d WON!",result);
        gotoxy(50,22);
        return;
    }

    gotoxy(59,18);
    printf("Game TIED!");


    gotoxy(50,22);
}
