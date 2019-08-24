#pragma once

struct TTT
{
	// seperate inputs
	int playerPos;
	int opponentPos;

public:
	// game loop
	bool gameOver = false;
	bool gameRunning = false;

	char currentPos[10] = "         ";

	// functions
	void menuPrint();
	void PvA();
	void Display();
	void WinCheck();
	void TieCheck();
};
