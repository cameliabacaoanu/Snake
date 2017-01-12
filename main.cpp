#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

bool gameOver;
bool intersectie=false;
bool twoPlayer=false;
int x, y, x2,y2, fruitX, fruitY, powerUpX, powerUpY;
int tailX[100], tailY[100],tailX2[100], tailY2[100];
int nTail,nTail2;
int score,wall,speed,v,n;
int width = 20, height = 20;
char p1_name[100];
char p2_name[100];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
eDirecton dir2;
bool powerUp = false;
int powerUpType = rand()% 5;
char filename[] = "scoreFile";
std::fstream myFile;


void playMenu(){

    cout<<"Introdu numele jucatorului"<<endl;
    cin>>p1_name;
     if(twoPlayer){
        cout<<"Introdu numele jucatorului 2"<<endl;
        cin>>p2_name;
    }
     if(twoPlayer)
    {
        int n;
        cout<<"Alegeti dintre:"<<endl;
        cout<<"1.La intersectia serpilor, jocul continua."<<endl;
        cout<<"2.La intersectia serpilor, jocul se termina."<<endl;
        cin>>n;
        if(n==2)
            intersectie=true;

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

        if(twoPlayer){
	dir2 = STOP;
	x2 = x/2;
	y2 = y/2;
	nTail2=0;
	}

	fruitX = rand() % width;
	fruitY = rand() % height;
    do
       {
       	powerUpX = rand() % width;
        powerUpY = rand() % height;
	}while(fruitX==powerUpX && fruitY==powerUpY);


	for(int i=0;i<=100;i++)
	{
		tailX[i]=0;
		tailY[i]=0;
                if(twoPlayer)
                 {
                    tailX2[i]=0;
                    tailY2[i]=0;
		 }

	}
	score = 0;

}

void scoreMenu()
{
    system("cls");
    std::string str;
    std::ifstream f(filename);
    f.clear();
    f.seekg(0, std::ios::beg);
    while (std::getline(f, str))
    {
        cout<<str<<"\n";
    }
        cout<<"\n";

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
				cout << '$';
				else
                  if (twoPlayer && i == y2 && j == x2)
				     cout << '@';
                  else
                    if (powerUp && i == powerUpY && j == powerUpX)
                      cout<< powerUpType;
                    else
                      if (i == fruitY && j == fruitX)
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
				if(twoPlayer)
				for (int k = 0; k < nTail2; k++)
				{
                    if (tailX2[k] == j && tailY2[k] == i)
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
        case 'j':
		    if(dir2 != RIGHT)
                dir2 = LEFT;
			break;
		case 'l':
		    if(dir2 != LEFT)
                dir2 = RIGHT;
			break;
		case 'i':
		    if(dir2 != DOWN)
                dir2 = UP;
			break;
		case 'k':
		    if(dir2 != UP)
                dir2 = DOWN;
			break;
		}
	}
}
void Logic()
{
	if (speed == 1)
        v=50;
    else
        if(speed == 2)
          v=30;
        else
          if(speed == 3)
            v=10;

    int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	int prevX2,prevY2;
	if(twoPlayer)
    {
       prevX2= tailX2[0];
       prevY2 = tailY2[0];
	}
	int prev2X2,prev2Y2;
	tailX[0] = x;
	tailY[0] = y;
	if(twoPlayer)
    {
        tailX2[0] = x2;
        tailY2[0] = y2;
	}
        for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	if(twoPlayer)
    {
        for (int i = 1; i < nTail2; i++)
        {
           	prev2X2 = tailX2[i];
            prev2Y2 = tailY2[i];
            tailX2[i] = prevX2;
            tailY2[i] = prevY2;
            prevX2 = prev2X2;
            prevY2 = prev2Y2;
		}
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

	switch (dir2)
	{
	case LEFT:
		x2--;
		break;
	case RIGHT:
		x2++;
		break;
	case UP:
		y2--;
		break;
	case DOWN:
		y2++;
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
      if(wall == 1){
       if(twoPlayer && (x2 > width || x2 < 0 || y2 > height || y2 < 0))
       {gameOver = true;}
	} else {
        if (x2 >= width) x2 = 0; else if (x2 < 0) x2 = width - 1;
        if (y2 >= height) y2 = 0; else if (y2 < 0) y2 = height - 1;
	}
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
         for (int i = 0; i < nTail2; i++)
		if (tailX2[i] == x2 && tailY2[i] == y2)
			gameOver = true;
	if(intersectie)
     {
      for(int i=0;i< nTail; i++)
        if( tailX[i]== x2 && tailY[i]== y2)
           gameOver=true;
      for(int i=0;i< nTail2; i++)
        if(tailX2[i]== x && tailY2[i]== y)
          gameOver=true;
     }
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
		if(score%50==0)
        {
            powerUp = true;
            powerUpType = rand()% 5;
		}
	}
        if (x2 == fruitX && y2 == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail2++;
		if(score%50==0){
            powerUp = true;
            powerUpType = rand()% 5;
		}
        }
	if(x== powerUpX && y == powerUpY){
        switch (powerUpType)
        {
        case 0:
            score = score * 2;
            break;
        case 1:
            v = v + 10;
            speed--;
            break;
        case 2:
            if(v>10)
                v = v - 10;
            speed++;
            break;
        case 3:
            nTail=nTail/2;
            break;
        case 4:
            score=score*5;
            gameOver=true;
            break;
        default:
            break;
        }

        powerUp=false;
	}
     if(x2== powerUpX && y2 == powerUpY){
        switch (powerUpType)
        {
        case 0:
            score = score * 2;
            break;
        case 1:
            v = v + 10;
            speed--;
            break;
        case 2:
            if(v>10)
                v = v - 10;
            speed++;
            break;
        case 3:
            nTail2=nTail2/2;
            break;
        case 4:
            score=score*5;
            gameOver=true;
            break;
        default:
            break;
        }

        powerUp=false;
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
  cout<<"1. Joc nou - 1 jucator"<<endl;
  cout<<"2. Joc nou - 2 jucatori"<<endl;
  cout<<"3. Tabela de scoruri"<<endl;
  cout<<"0. Exit"<<endl;
  cin>>menu;

  switch (menu)
	{
	case 1:
           twoPlayer = false;
	   playMenu();
	   startGame();
	   break;

       case 2:
           twoPlayer = true;
	   playMenu();
	   startGame();
	   break;

	case 3:
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
   int n;
    cout<<"BUN VENIT!!!"<<endl;
    while(1)
  {

	if(gameOver)
    {

        ofstream output(filename, std::ios_base::app | std::ios_base::out);
        output <<p1_name<<" - "<<score<<"\n";
        output.close();

        cout<<"JOC NOU? (1/0) "<<endl;
        cin>>n;

        gameOver = false;
        if(n==0)
        {
            Setup();
        }
        else{
            playMenu();
            startGame();
        }
    }
    else
        Setup();
    }

}

