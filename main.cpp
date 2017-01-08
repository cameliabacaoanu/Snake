#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

bool gameOver;
int x, y, fruitX, fruitY, score,wall,speed, width = 20, height = 20, nTail,v=10;
char p1_name[100];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
int tailX[100], tailY[100];

void playMenu(){

    cout<<"Introdu numele jucatorului"<<endl;
    cin>>p1_name;
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
    system("cls");
	for (int i = 0; i < width+2; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "|";
			if (i == y && j == x)
				cout << '#';
			else if (i == fruitY && j == fruitX)
				cout << '*';
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "|";
		}
		cout << endl;
	}
	for (int i = 0; i < width+2; i++)
		cout << "-";
	cout << endl;
	cout << "Score:" << score << endl;
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
			gameOver = true;
			break;
		}
	}
}
void Logic()
{
        int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	if (speed == 1)
        v=50;
    else
        if(speed == 2)
          v=30;
        else
          if(speed == 3)
            v=10;
        for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
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
   if(wall == 1)
	{if (x > width || x < 0 || y > height || y < 0)
	  gameOver = true;}
	else
	 {if (x >= width)
	    x = 0;
      else
        if (x < 0)
          x = width - 1;
      if (y >= height)
        y = 0;
      else
        if (y < 0)
          y = height - 1;}
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
void startGame()
{
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(v);
	}
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

