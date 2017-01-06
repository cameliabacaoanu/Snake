#include <iostream>
#include <windows.h>

using namespace std;


void playMenu(){

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
  cout<<"1.Joc nou"<<endl;
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

