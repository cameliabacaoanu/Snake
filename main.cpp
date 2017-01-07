#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

bool gameOver;
int x, y, fruitX, fruitY, score,wall,speed, width = 20, height = 20, nTail;
char p1_name[100];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
int tailX[100], tailY[100];

void playMenu(){

    cout<<"Introdu numele jucatorului"<<endl;
    cin>>p1_name;
    }
    cout<<"FINAL JOC LA IMPACT CU MARGINILE? (1/0)"<<endl;
    cin>>wall;
    cout<<"DIFICULTATE: 1=USOR  2=MEDIU  3=GREU "<<endl;
    cin>>speed;

	gameOver = false;

	dir = STOP;
	x = width / 2;
	y = height / 2;
	nTail=0;

	fruitX = rand() % width;
	fruitY = rand() % height;

	for(int i=0;i<=100;i++)
	{
		tailX[i]=0;
		tailY[i]=0;
		
	}
	score = 0;

}

void scoreMenu(){


}

void Draw()
{


}
void Input()
{

}
void Logic()
{

}
void startGame()
{


}

void Setup()
{
  int menu;
  cout<<"Selectati una din optiuni:"<<endl;
  cout<<"1. Joc nou"<<endl;
  cout<<"2. Tabela de scoruri"<<endl;
  cout<<"0. Exit"<<endl;
  cin>>menu;

  switch (menu)
	{
	case 1:
	   playMenu();
	   startGame();
	   break;

	case 2:
           scoreMenu();
           break;

	case 0:
            exit(0);
	    break;

        default:
            break;
	}
}

int main ()
{
cout<<"BUN VENIT!!!"<<endl;

Setup();

}

