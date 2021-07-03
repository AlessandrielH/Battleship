#pragma once
#ifndef BATTLESHIP
#define BATTLESHIP

class Battleship
{
private:
	static const int SIZE_A = 3;
	static const int SIZE_B = 4;
	static const int SIZE_C = 5;
	static const int SIZE_D = 6;
	int shipA[SIZE_A];
	int shipB[SIZE_B];
	int shipC[SIZE_C];
	int shipD[SIZE_D];
public:
	Battleship();

	void placeShip(Board b, int size, int x, int y, int x2, int y2);



};
#endif BATTLESHIP
