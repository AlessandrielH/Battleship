#include "Board.h"
#include <string>
using namespace std;

	
	void ShipPlacement::placeShips(char o, int x, int y)
		/* this function accepts: 3 variables to store char orientation, int x coordinate, int y coordinate.
			   No values returned.
			   Stores orientation (v for vertical, h for horizontal) that user inputs.
			   Stores x and y coordinates from user.
			*/
	{
		orientation = o;
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
	
	void ShipPlacement::setShip(Board b)
	{
		for (int n = 0; n < 4; n++)
		{
			cout << "Your " << oNos[n] << " ship is named " << names[n] << endl; //oNos is ordinal number
			cout << "This ship is " << units[n] << " long."; //units refers to the length of the ship
			cout << "Do you want it to be vertical or horizontal: v/h? "; // v and h refers to the orientation 
			cin >> orientation;
			setShipPlacement(b);
		}
	}
