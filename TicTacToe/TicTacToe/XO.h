#pragma once

struct TTT
{
	int playerPos;
	int opponentPos;

public:
	bool gameOver = false;
	bool gameRunning = false;
	char currentPos[10] = "123456789";
	void menuPrint();
	void PvA();

	void Display();
};
