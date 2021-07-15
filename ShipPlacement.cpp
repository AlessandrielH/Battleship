#include"ShipPlacement.h"
#include "Board.h"
#include <string>
#include<iostream>
using namespace std;

ShipPlacement::ShipPlacement()
{}

	void ShipPlacement::placeShips(Board b)
	{
		int x, y;
		string names[NUM_OF_SHIPS] = { "Conqueror", "Captain", "Victory", "Talent" }; //names of ships to be placed by players
		string oNos[NUM_OF_SHIPS] = { "1st", "2nd", "3rd", "4th" }; //ships are numbered, respectively

		for (int n = 0; n < NUM_OF_SHIPS; n++)
		{
			cout << "Your " << oNos[n] << " ship is named " << names[n] << endl; //oNos is ordinal number
			cout << "This ship is " << units[n] << " long."; //units refers to the length of the ship
			cout << "Do you want it to be vertical or horizontal: v/h? "; // v and h refers to the orientation 
			cin >> orientation;
			cout << "Set the x-coordinate for the beginning of the ship:";
			cin >> x;
			cout << "Set the y-coordinate for the beginning of the ship:";
			cin >> y;
			setShipPlacement(b);
		}
		
		//jgminor7 added code below so user doesn't place a ship out-of-bounds of board area
		do 
		{
			if( x < 0 || x >9 || y < 0 || y > 9) //const int COL = 10 //const int ROW = 10;
			{
				/*Is there a separate statement for x coordinte and y coordinate?
				Should I refer to COL and ROW, instead of xCoord and yCoord? */
				cout << "Your coordinates are out of bounds.\n";
				cout << "Please enter valid x coordinate and y coordinate within 0 to 9." << endl;
				cout << "Set the x-coordinate for the beginninng of the ship:";
				cin >> xCoord;
				cout << "Set the y-coordinate for the beginning of the ship:";
				cin >> yCoord;
			}
		} while(x < 0 || x >9 || y < 0 || y >9  );
		xCoord = x;
		yCoord = y;
		cout << orientation << " " << xCoord << " " << yCoord;
		
	}
	char ShipPlacement::getOrientation()
	{
		return orientation;
	}

	void ShipPlacement::setShipPlacement(Board b) //  Board b refers to Board file
	{
		if (orientation == 'v') // v is vertical ship placement, size of ship increments by 1 unit
		{
			for (int i = 0; i < units[i]; i++)
			{
				b.setShip((xCoord + i), yCoord); // b refers to Board file
			}
		}
		else if (orientation == 'h') // h is horizontal ship placement, size of ship increments by 1 unit
		{
			for (int i = 0; i < units[i]; i++)
			{
				b.setShip(xCoord, (yCoord + i)); // b refers to Board file
			}
		}
	}
