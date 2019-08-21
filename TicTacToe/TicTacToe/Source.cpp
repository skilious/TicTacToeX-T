#include <iostream>
#include "XO.h"
using namespace std;

void TTT::PvA()
{
	while (gameRunning == true)
	{
		Display();
		cout << "Your turn!\n";
		cin >> playerPos;
		if (currentPos[playerPos - 1] == 'X' || currentPos[playerPos - 1] == 'O')
		{
			cout << "This position already exists with either X or O!\n";
		}
		else
		{
			currentPos[playerPos - 1] = 'X';
			
		}

		if ((playerPos) <= 0 || (playerPos) >= 10)
		{
			cout << "Invalid selection!\nChoose a number!\n";

		}
	}
}


void TTT::Display()
{
	cout << "\n" << currentPos[0] << "|" << currentPos[1] << "|" << currentPos[2] << endl;
	cout << currentPos[3] << "|" << currentPos[4] << "|" << currentPos[5] << endl;
	cout << currentPos[6] << "|" << currentPos[7] << "|" << currentPos[8] << "\n\n";
}

void TTT::menuPrint()
{
	int options;
	//When gameOver is false, this goes on until gameOver is true and then quits.
	while (gameOver == false)
	{

		cout << "Main Menu\n1) Player vs Player \n2) Player vs CPU\n3) CPU vs CPU\n4) Quit\n";
		cin >> options;
		switch (options)
		{
		case 1:
			cout << "Player vs Player Selection!\n";
				
			break;
		case 2:
			cout << "Player vs CPU Selected!\n";
			gameRunning = true;
			PvA();
				//Have the file read to check history of wins/losses against CPU.
				//if doesn't exist, create a file & make the history from there.
				//Function to start the gamemode.
			break;
		case 3:
			cout << "CPU vs CPU Selected!\n";
			break;
		case 4:
			cout << "Quitting game\n";
			gameOver = true;
			break;
		default:
			//This prevents the user from messing around during the input selection.
			cout << "Invalid selection\n";
			break;
		}
	}
	//Quits here.
	system("pause");
	exit(1);
}

int main()
{
	TTT XO;
	XO.menuPrint();
}
