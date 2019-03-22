#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
string drum[100][100];
int ala_tank[100];
int aia_tank[100][100];
int rand3[100];
int it_aia;


int scor[100];
int height=10;
int width=10;
int gameOver = 0;
eDirecton dir;
int maxim=0;

int gen=0;
int ok=0;
int x=8;
int y=1;

int distanta_maxima_parcursa=99999;
int numarul_minim_de_miscari = 999999;
int care_e;
int poz;

int sco;
int gagii[100][100];



void draw_drum (){
    Sleep(200);
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
    case LEFT://0
        x--;
        break;
    case RIGHT://1
        x++;
        break;
    case UP://2
        y--;
        break;
    case DOWN://3
        y++;
        break;

    }

}



void random_dudes(){
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            gagii[i][j] = rand()%4;

}



void scor_dudes(){
    for(int i=0;i<50;i++){
        sco=0;
        gameOver=0;
        x=8;
        y=1;
        int scor_nr_mutari=0;
        int scor_cat_de_aproape=99999;

        while(gameOver==0){
            for(int j=0;j<50;j++){
                cout<<"GEN : "<<gen<<"  BOT : "<<i<<"   POZ: "<<j<<'\n';
                //Sleep(200);
                poz=j;

                if(gagii[i][j]==0)
                    x--;
                else
                if(gagii[i][j]==1)
                    x++;
                else
                if(gagii[i][j]==2)
                    y--;
                else
                if(gagii[i][j]==3)
                    y++;

                draw_drum();

                ////////////////////////////////////////////////
                if(gameOver==1){
                    j=101;

                }
                else
                    scor_nr_mutari++;
                ///////////////////////////////////////////////



                //Sleep(200);
            }
        }
        int xaux =0;
        int yaux =0;

        if ( x > 4)
            xaux = x - 4;
        else
            xaux = 4 - x;


        if ( y > 8)
            yaux = y - 8;
        else
            yaux = 8 - y;


        scor_cat_de_aproape = xaux + yaux;
        sco=scor_cat_de_aproape;

        int poz1=0;

        cout<<endl<<" ->  "<<scor_cat_de_aproape<<"     "<<i<<endl;
        cout<<y << " " << x<<endl;

        if (scor_cat_de_aproape < distanta_maxima_parcursa ){

            distanta_maxima_parcursa = scor_cat_de_aproape;





            for(int t=0;t<50;t++)
                    ala_tank[t]=gagii[i][t];






            for(int t=0;t<50;t++){
                aia_tank[it_aia][t]=gagii[i][t];
            }

            it_aia++;






            care_e = i;

            poz1=poz;
            cout<<"###############"<<poz1<<"################";

        }


        else
        if (scor_cat_de_aproape == distanta_maxima_parcursa ){

            if(poz < poz1){

                poz1=poz;
                distanta_maxima_parcursa = scor_cat_de_aproape;





                for(int t=0;t<10;t++)
                    ala_tank[t]=gagii[i][t];




                for(int t=0;t<50;t++){
                    aia_tank[it_aia][t]=gagii[i][t];
                }
                it_aia++;




                cout<<"cica da   //////////////////////////"<<poz<<"////////////////"<<endl;
            }
        }










    }

//ala tank
        //Sleep(200);

        cout<<"Ala tank"<<endl;
            for(int t=0;t<50;t++)
                cout<<ala_tank[t];
        cout<<endl<<care_e;
        cout<<endl<<endl;




        cout<<"Aia tank"<<endl;
        for(int p=0;p<it_aia;p++){
            for(int t=0;t<50;t++)
                cout<<aia_tank[p][t];
        cout<<endl;
        }
        cout<<endl;

}




void next_gen(){

    for(int i=0;i<it_aia;i++)
        for(int j=0;j<50;j++)
            gagii[i][j]=aia_tank[i][j];
/////////////////////////////////////////////////////////////////////////////

    int itg=it_aia;
    for(int i=0;i<10;i++){

            int rand1 = rand()%it_aia;
            int rand2 = rand()%it_aia;
            //int rand_f_s =rand()%2;
            int randd=rand()%51;

            for(int it1=0;it1<50;it1++){
                if(it1<randd){
                    aia_tank[itg  ][it1]=aia_tank[rand1][it1];
                    //aia_tank[itg+1][it1]=aia_tank[rand2][it1];
                }
                else{
                    aia_tank[itg  ][it1]=aia_tank[rand2][it1];
                    //aia_tank[itg+1][it1]=aia_tank[rand1][it1];
                }
            }

            itg++;
    }

/////////////////////////////////////////////////////////////////////////////

    itg--;
    for(int i=0;i<10;i++){

            int rand1 = rand()%it_aia;
            int rand2 = rand()%it_aia;
            //int rand_f_s =rand()%2;
            int randd=rand()%51;

            for(int it1=0;it1<50;it1++){
                if(it1<randd){
                    //aia_tank[itg  ][it1]=aia_tank[rand1][it1];
                    aia_tank[itg+1][it1]=aia_tank[rand2][it1];
                }
                else{
                    //aia_tank[itg  ][it1]=aia_tank[rand2][it1];
                    aia_tank[itg+1][it1]=aia_tank[rand1][it1];
                }
            }

            itg++;
    }


/////////////////////////////////////////////////////////////////////////////

    for(int i=it_aia+20 ; i<40 ; i++){

            int rand1 = rand()%it_aia;
            int rand2 = rand()%it_aia;
            int randd=rand()%51;


            for(int j=0;j<50;j++)
                rand3[j] = rand()%4;



            for(int it1=0;it1<50;it1++){
                if(it1<randd){
                    aia_tank[itg][it1]=rand3[it1];
                    //aia_tank[itg+1][it1]=aia_tank[rand2][it1];
                }
                else
                    aia_tank[itg+1][it1]=aia_tank[rand2][it1];

            }
            itg++;

    }
//////////////////////////////////////////////////////////////////////////////
 for(int i=it_aia+40 ; i<50 ; i++){

            int rand1 = rand()%it_aia;
            int rand2 = rand()%it_aia;
            int randd=rand()%51;


            for(int j=0;j<50;j++)
                rand3[j] = rand()%4;



            for(int it1=0;it1<50;it1++){
                if(it1<randd){
                    aia_tank[itg][it1]=aia_tank[rand2][it1];

                }
                else
                    aia_tank[itg+1][it1]=rand3[it1];

            }
            itg++;

    }

///////////////////////////////////////////////////////////////////////////////
    for(int i=0;i<50;i++){
        for(int j=0 ; j<50 ; j++)
            cout<<aia_tank[i][j];
        cout<<"                   "<<i<<endl;
    }
    gen++;
}




void meniu(){
    while (gameOver!=1){
            draw_drum();
            Input();
            Logic();
            Sleep(2000);
        }
    if(ok==0)
            cout<<'\n'<<"Game Over";
        else
            cout<<'\n'<<"You Win !";
}



int main(){
    srand((unsigned)(time(0)));
    random_dudes();
        for (int i = 0; i < 50; i++)
        {
        for (int j = 0; j < 50; j++)
            cout<<gagii[i][j];
        cout<<"               "<<i<<'\n';
        }



    int chose;
    cout<<"Sa joci tu : 1\nSa joace el : 2\nSa inchid : 3\n";
    cin>>chose;
    while(chose != 3){

        if(chose==1){
            x=8;
            y=1;
            gameOver=0;
            meniu();
        }
        else
            if(chose==2){
                    //cout<<"\nGeneratie : "<<gen<<'\n';


                while(ok!=1){
                    scor_dudes();
                    next_gen();
                    for(int i=0;i<50;i++)
                        for(int j=0;j<50;j++)
                            gagii[i][j]=aia_tank[i][j];
                }
            }


        cout<<"Sa joci tu : 1\nSa joace el : 2\nSa inchid : 3\n";
        cin>>chose;
    }



    cout<<"Generatie : "<<gen;

}
