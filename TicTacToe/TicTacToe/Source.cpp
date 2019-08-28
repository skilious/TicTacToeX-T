#include <iostream>
#include<time.h> 
#include "XO.h"
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
using namespace std;

ofstream outputFile;
ifstream inputFile;
string name = "";
int PvAScore, PvPScore, AvAScore;

void TTT::PvP()
{
	string player2 = "";
	cout << "\nPass the keyboard for Player 2's username\n";
	cout << "\nEnter your username for Player 2\n";
	cin >> player2;
	while (gameRunning == true)
	{
		// X's turn
		cout << name << "'s turn!\n";
		do // doWhile loop for avaliability
		{
			do // doWhile loop for validity
			{
				cin >> playerPos;
				if ((playerPos) <= 0 || (playerPos) >= 10)
				{
					cout << "Invalid selection!\nChoose a number!\n";

				}

			} while ((playerPos) <= 0 || (playerPos) >= 10);

			if (currentPos[playerPos - 1] == 'X' || currentPos[playerPos - 1] == 'O')
			{
				cout << "This position already exists with either X or O!\n";
			}

		} while (currentPos[playerPos - 1] == 'X' || currentPos[playerPos - 1] == 'O');

		currentPos[playerPos - 1] = 'X';	// the player sees the squares as 1-9 but the array is listed as 0-8
											// so for coding sake we hardcode one off

		// show the screen
		Display();

		// check winnings
		WinCheck();
		TieCheck();

		if (gameRunning == false)
		{
			PvPScore++;
			system("pause");
			break;
		}

		// O's turn
		cout << player2 << "'s turn!\n";
		do // doWhile loop for avaliability
		{
			do // doWhile loop for validity
			{
				cin >> playerPos;
				if ((playerPos) <= 0 || (playerPos) >= 10)
				{
					cout << "Invalid selection!\nChoose a number!\n";

				}

			} while ((playerPos) <= 0 || (playerPos) >= 10);

			if (currentPos[playerPos - 1] == 'X' || currentPos[playerPos - 1] == 'O')
			{
				cout << "This position already exists with either X or O!\n";
			}

		} while (currentPos[playerPos - 1] == 'X' || currentPos[playerPos - 1] == 'O');

		currentPos[playerPos - 1] = 'O';	// the player sees the squares as 1-9 but the array is listed as 0-8
											// so for coding sake we hardcode one off

		// show the screen
		Display();

		// check winnings
		WinCheck();
		TieCheck();

		if (gameRunning == false)
		{
			system("pause");
		}
	}
}

void TTT::PvA()
{
	while (gameRunning == true)
	{
		srand(time(0));

		// player's turn
		cout << "Your turn!\n";
		do // doWhile loop for avaliability
		{
			do // doWhile loop for validity
			{
				cin >> playerPos;
				if ((playerPos) <= 0 || (playerPos) >= 10)
				{
					cout << "Invalid selection!\nChoose a number!\n";

				}

			} while ((playerPos) <= 0 || (playerPos) >= 10);

			if (currentPos[playerPos - 1] == 'X' || currentPos[playerPos - 1] == 'O')
			{
				cout << "This position already exists with either X or O!\n";
			}

		} while (currentPos[playerPos - 1] == 'X' || currentPos[playerPos - 1] == 'O');

		currentPos[playerPos - 1] = 'X';	// the player sees the squares as 1-9 but the array is listed as 0-8
											// so for coding sake we hardcode one off

		// show the screen
		Display();

		// check winnings
		WinCheck();
		TieCheck();

		if (gameRunning == false)
		{
			PvAScore++;
			cout << name << " wins\n\n";
			system("pause");
			break;
		}


		// AI's turn
		cout << "AI's turn!\n";

		do // doWhile loop for avaliability -- if the rand cant find a spot it infinitly loops FIX
		{
			opponentPos = rand() % 9 + 1; // rn we're just selecting a random number

		} while (currentPos[opponentPos - 1] == 'X' || currentPos[opponentPos - 1] == 'O');
		this_thread::sleep_for(chrono::seconds(1));
		cout << opponentPos << endl;
		currentPos[opponentPos - 1] = 'O';

		// show the screen
		Display();

		// check winnings
		WinCheck();
		TieCheck();

		if (gameRunning == false)
		{
			system("pause");
		}
	}
}

void TTT::AvA()
{
	while (gameRunning == true)
	{
		srand(time(0));

		// AI's turn
		cout << "AI X's turn!\n";

		do // doWhile loop for avaliability -- if the rand cant find a spot it infinitly loops FIX
		{
			opponentPos = rand() % 9 + 1; // rn we're just selecting a random number

		} while (currentPos[opponentPos - 1] == 'X' || currentPos[opponentPos - 1] == 'O');
		this_thread::sleep_for(chrono::seconds(1));
		cout << opponentPos << endl;
		currentPos[opponentPos - 1] = 'X';

		// show the screen
		Display();

		// check winnings
		WinCheck();
		TieCheck();

		if (gameRunning == false)
		{
			cout << "X wins";
			system("pause");
			break;
		}

		// AI's turn
		cout << "AI O's turn!\n";

		do // doWhile loop for avaliability -- if the rand cant find a spot it infinitly loops FIX
		{
			opponentPos = rand() % 9 + 1; // rn we're just selecting a random number

		} while (currentPos[opponentPos - 1] == 'X' || currentPos[opponentPos - 1] == 'O');
		this_thread::sleep_for(chrono::seconds(1));
		cout << opponentPos << endl;
		currentPos[opponentPos - 1] = 'O';

		// show the screen
		Display();

		// check winnings
		WinCheck();
		TieCheck();

		if (gameRunning == false)
		{
			system("pause");
		}
	}
}



// ------------------------------------------------------------------------------------------ \\
// ------------------------------------------------------------------------------------------ \\


void TTT::TieCheck()
{
	if (currentPos[0] != ' ' && currentPos[1] != ' ' && currentPos[2] != ' ' &&
		currentPos[3] != ' ' && currentPos[4] != ' ' && currentPos[5] != ' ' &&
		currentPos[6] != ' ' && currentPos[7] != ' ' && currentPos[8] != ' ')	// checking if every space is used
	{
		cout << "Game is a tie!" << endl << endl;
		gameRunning = false;
	}
}

void TTT::WinCheck() // need another check for X and O
{
	if (currentPos[0] == currentPos[1] && currentPos[1] == currentPos[2] && (currentPos[1] == 'X' || currentPos[1] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[1] << " wins!" << endl << endl;
		if (currentPos[1] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}
	else if (currentPos[3] == currentPos[4] && currentPos[4] == currentPos[5] && (currentPos[4] == 'X' || currentPos[4] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[4] << " wins!" << endl << endl;
		if (currentPos[4] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}
	else if (currentPos[6] == currentPos[7] && currentPos[7] == currentPos[8] && (currentPos[7] == 'X' || currentPos[7] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[7] << " wins!" << endl << endl;
		if (currentPos[7] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}
	else if (currentPos[0] == currentPos[3] && currentPos[3] == currentPos[6] && (currentPos[3] == 'X' || currentPos[3] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[3] << " wins!" << endl << endl;
		if (currentPos[3] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}
	else if (currentPos[1] == currentPos[4] && currentPos[4] == currentPos[7] && (currentPos[4] == 'X' || currentPos[4] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[4] << " wins!" << endl << endl;
		if (currentPos[4] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}
	else if (currentPos[2] == currentPos[5] && currentPos[5] == currentPos[8] && (currentPos[5] == 'X' || currentPos[5] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[5] << " wins!" << endl << endl;
		if (currentPos[5] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}
	else if (currentPos[0] == currentPos[4] && currentPos[4] == currentPos[8] && (currentPos[4] == 'X' || currentPos[4] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[4] << " wins!" << endl << endl;
		if (currentPos[4] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}
	else if (currentPos[2] == currentPos[4] && currentPos[4] == currentPos[6] && (currentPos[4] == 'X' || currentPos[4] == 'O'))
	{
		gameRunning = false;
		cout << currentPos[4] << " wins!" << endl << endl;
		if (currentPos[4] == 'X')
		{
			cout << "You've gained one win!\n";
		}
	}

}

void TTT::Display()
{
	system("cls");
	cout << "\n" << currentPos[0] << "|" << currentPos[1] << "|" << currentPos[2] << endl;
	cout << "-+-+-" << endl;
	cout << currentPos[3] << "|" << currentPos[4] << "|" << currentPos[5] << endl;
	cout << "-+-+-" << endl;
	cout << currentPos[6] << "|" << currentPos[7] << "|" << currentPos[8] << "\n\n";
}

void TTT::Clear()
{
	for (int i = 0; i < 10; i++)
	{
		currentPos[i] = ' ';
	}
}

void TTT::Protecc()
{
	if (cin.fail())		// If cin fails (as in overflows), do:
	{
		cin.clear();			// clear input buffer to restore cin to a usable state
		cin.ignore();			// ignore last input
		cout << "Please dont do that." << endl << endl;

		// Ryan Hallberg - Oct 23 2016 
		// https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable
	}
}

void Saves()
{
	cout << "Type in your username.\n(Case Sensitive)\n";

	cin >> name;
	cout << "\nName: " + name << endl;
	inputFile.open(name + ".txt");

	if (inputFile)
	{
		cout << "\n\nIt exists!\n";
		cout << "Welcome " + name + "!\n";

		inputFile >> PvAScore >> PvPScore;
		cout << "Your current win is: " << PvAScore << " - Against CPU\n";
		cout << "Your current win is: " << PvPScore << " - Against Player 2\n\n";
		outputFile.open(name + ".txt");
		system("pause");
	}
	else
		if (!inputFile)
		{
			cout << "Your username is: " + name << endl;
			outputFile.open(name + ".txt");
			outputFile << PvAScore << PvPScore;
			system("pause");
		}
}

void TTT::menuPrint()
{
	int options;
	//When gameOver is false, this goes on until gameOver is true and then quits.
	while (gameOver == false)
	{
		system("cls");
		inputFile >> PvAScore >> PvPScore;
		cout << "Main Menu\n1) Player vs Player \n2) Player vs CPU\n3) CPU vs CPU\n4) Player Stats\n5) Quit\n\n";
		cin >> options;
		switch (options)
		{
		case 1:
			cout << "Player vs Player Selection!\n";
			gameRunning = true;
			Display();
			PvP();
			Clear();
			break;
		case 2:
			cout << "Player vs CPU Selected!\n";
			gameRunning = true;
			Display();
			PvA();
			Clear();

			//Have the file read to check history of wins/losses against CPU.
			//if doesn't exist, create a file & make the history from there.
			//Function to start the gamemode.
			break;
		case 3:
			cout << "CPU vs CPU Selected!\n";
			gameRunning = true;
			Display();
			AvA();
			Clear();

			break;
		case 4:
			system("cls");
			cout << "Current wins: " << PvAScore << " - Against CPU\n\n";
			cout << "Current wins: " << PvPScore << " - Against Player 2\n\n";
			system("pause");
			break;

		case 5:
			cout << "Quitting game\n";
			gameOver = true;
			break;
		default:
			//This prevents the user from messing around during the input selection.
			cout << endl << "Invalid selection\n" << endl;
			Protecc();
			break;
		}
	}
	//Quits here.
	outputFile << PvAScore;
	outputFile << PvPScore;
	inputFile.close();
	outputFile.close();
	system("pause");
	exit(1);
}

int main()
{
	TTT XO;
	Saves();
	XO.menuPrint();
}
