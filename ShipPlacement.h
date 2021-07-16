#pragma once
#include <iostream>
#include <string>
#include "Board.h"

#ifndef SHIPPLACEMENT
#define SHIPPLACEMENT

class ShipPlacement
{
	private:
		static const int NUM_OF_SHIPS = 4;
		char orientation; // orientation refers to ship's position vertical or horizontal
		int xCoord; // x coordinate
		int yCoord; // y coordinate 

		/*string names[NUM_OF_SHIPS]; //names of ships to be placed by players
		string oNos [NUM_OF_SHIPS]; //ships are numbered, respectively*/
		int units [NUM_OF_SHIPS]={ 3, 4, 5, 6 }; // the length of the respective ships are 3 units, 4 units, 5 units, & 6th units

	public:
		ShipPlacement();
		void placeShips(Board &b);
		/* this function accepts: 3 variables to store char orientation, int x coordinate, int y coordinate.
			   No values returned.
			   Stores orientation (v for vertical, h for horizontal) that user inputs.
			   Stores x and y coordinates from user.
		*/

		char getOrientation();
	};
#endif 
