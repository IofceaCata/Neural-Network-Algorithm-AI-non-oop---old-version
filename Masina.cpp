#include<iostream>
#include<string>
#include <conio.h>
#include <windows.h>

using namespace std;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
string drum[100][100];
int height=10;
int width=10;
int gameOver = 0;
eDirecton dir;

int ok=0;
int x=8;
int y=1;

void draw_drum (){
    system("cls");

    for(int i=0;i<=10;i++)
        for(int j=0;j<=10;j++){
            if(i==0)
                drum[i][j]="#";
            else
            if(i==height-1)
                drum[i][j]="#";
            else
            if(j==0)
                drum[i][j]="#";
            else
            if(j==width-1)
                drum[i][j]="#";
            else
                drum[i][j]=" ";
        }



    drum[1][1]="#";
    drum[1][2]="#";
    drum[1][4]="#";
    drum[1][5]="#";

    drum[2][2]="#";
    drum[2][8]="#";
    drum[2][7]="#";

    drum[3][1]="#";
    drum[3][8]="#";

    drum[4][2]="#";
    drum[4][7]="#";

    drum[8][4]="A";




    if(drum[y][x]=="#"){
        ok=0;
        gameOver = 1;
    }
    else
    if(drum[y][x]=="A"){
        ok=1;
        gameOver = 1;
    }
    else
    drum[y][x]="X";


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cout<<drum[i][j];
        cout<<'\n';
    }



}



void Input()
{


    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}



void Logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

}


int main(){
    while (gameOver!=1){
        draw_drum();
        Input();
        Logic();
        Sleep(200);
    }
    if(ok==0)
        cout<<'\n'<<"Game Over";
    else
        cout<<'\n'<<"You Win !";


}
