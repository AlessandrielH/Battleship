#pragma once
#include <iostream>
#include<string>
using namespace std;
#include "Board.h"

class ShipPlacement
{
	private:
		char orientation='o'; // orientation refers to ship's position vertical or horizontal
		int xCoord; // x coordinate
		int yCoord; // y coordinate

		static const int shipNames = 4;
		string names[shipNames] = { "Conqueror", "Captain", "Victory", "Talent" }; //names of ships to be placed by players

		static const int ordinalNo = 4;
		string oNos[ordinalNo] = { "1st", "2nd", "3rd", "4th" }; //ships are numbered, respectively

		static const int unitsLong = 4;
		int units[unitsLong] = { 3, 4, 5, 6 }; // the length of the respective ships are 3 units, 4 units, 5 units, & 6th units


	public:
		void placeShips(char o, int x, int y);
		/* this function accepts: 3 variables to store char orientation, int x coordinate, int y coordinate.
			   No values returned.
			   Stores orientation (v for vertical, h for horizontal) that user inputs.
			   Stores x and y coordinates from user.
		*/

		void setShipPlacement(Board b);
		//  Board b refers to Board file

		void setShip(Board b);

		char getOrientation();
	};
