#pragma once

#include <array>
struct TTT
{
	// seperate inputs
	int playerPos;
	int opponentPos;

public:

	// game loop
	bool gameOver = false;
	bool gameRunning = false;
	bool quitGame = false;

	char currentPos[10] = "        ";
	// functions
	void menuPrint();
	
	void PvP();
	void PvA();
	void AvA();

	void Display();
	void WinCheck();
	void TieCheck();
	void Clear();
	void Protecc();
};
