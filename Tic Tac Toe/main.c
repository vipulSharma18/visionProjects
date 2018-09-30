#include"gotoxy.c"

int store[3][3]={ {0,0,0},
                  {0,0,0},
                  {0,0,0}
                };

void move(int player)
{
    int i,j,flag=0;
    for (i=0;i<3;i++)
    {
        for(js=0;j<3;j++)
        {
            if (store[i][j] == 0)
            {
                flag=1;
                break;
            }
        }
        if (flag)
            break;
    }

    gotoxy(58+i*4,9+2*j);
    char ch;
    while(1)
    {
        ch = getch();
        if (ch == '2' && j < 2)
            j+=1;
        else if (ch == '8' && j > 0)
            j-=1;
        else if (ch == '4' && i > 0)
            i-=1;
        else if (ch == '6' && i < 2)
            i+=1;
        else if (ch == 13)
            break;

        gotoxy(58+i*4,9+2*j);
    }

    if (player == 1)
    {
        printf("x");
        store[i][j]=1;
    }
    else if (player == 2)
    {
        printf("o");
        store[i][j]=2;
    }
}

int check(int player)
{
    int i,j;

    for(i = 0;i<3;i++)
    {
        if (store[i][0]==player && store[i][1] ==player && store[i][2] ==player)
            return player;
    }

    for(j=0;j<3;j++)
    {
        if( store[0][j]==player && store[1][j]==player && store[2][j]==player )
            return player;
    }

    if( store[0][0]==player && store[1][1]==player && store[2][2]==player )
        return player;

    if( store[0][2]==player && store[1][1]==player && store[2][0]==player )
        return player;

    return 0;
}

int main()
{
    draw_players();
    draw_board();

    int player=1,result =0,i=0;

    while (i<9)
    {
        move(player);
        result = check(player);
        if (result != 0)
            break;
        i++;
        if(i%2==0)
            player = 1;
        else
            player = 2;
    }

    display_result(result);

    return 0;
}
