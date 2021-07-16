#include "ShipPlacement.h"
#include "Board.h"
#include <string>
#include <iostream>
using namespace std;

ShipPlacement::ShipPlacement()
{}

void ShipPlacement::placeShips(Board b)
{
	int x, y;
	string names[NUM_OF_SHIPS] = { "Conqueror", "Captain", "Victory", "Talent" }; //names of ships to be placed by players
	string oNos[NUM_OF_SHIPS] = { "1st", "2nd", "3rd", "4th" }; //ships are numbered, respectively
	orientation = 'o';

	for (int n = 0; n < NUM_OF_SHIPS; n++)
	{
		cout << "Your " << oNos[n] << " ship is named " << names[n] << endl; //oNos is ordinal number
		cout << "This ship is " << units[n] << " units long."; //units refers to the length of the ship
		do
		{
			cout << "Do you want it to be vertical or horizontal: v/h? "; // v and h refers to the orientation 
			cin >> orientation;
		} while (orientation != 'v' && orientation != 'h'); //Should line 25 include the not symbols (!) for v and h??
								    //The instructions appear to say that we will ask the user 
								    //to input x and y coordinates if they don't input a v or an h. 

		//jgminor7 added code below so user doesn't place a ship out-of-bounds of board area
		do
		{
			cout << "Set the x-coordinate for the beginninng of the ship:";
			cin >> x;
			cout << "Set the y-coordinate for the beginning of the ship:";
			cin >> y;

			if (x < 0 || x >9 || y < 0 || y > 9) //const int COL = 10 //const int ROW = 10;
			{
				cout << "Your coordinates are out of bounds.\n";
				cout << "Please enter valid x coordinate and y coordinate within 0 to 9." << endl;
			}
		} while (x < 0 || x >9 || y < 0 || y >9);
		xCoord = x;
		yCoord = y;
		cout << "orientation:" << orientation << "\nx:" << xCoord << "\ny:" << yCoord << endl;



		orientation = tolower(orientation);
		if (orientation == 'v') // v is vertical ship placement, size of ship increments by 1 unit
		{
			for (int i = 0; i < units[n]; i++)
			{
				b.setShip((xCoord + i), yCoord); // b refers to Board file
			}
		}
		else if (orientation == 'h') // h is horizontal ship placement, size of ship increments by 1 unit
		{
			for (int i = 0; i < units[n]; i++)
			{
				b.setShip(xCoord, (yCoord + i)); // b refers to Board file
			}
		}
		b.displayBoard();
		cout << "SetShipPLacement ended" << endl; //What does this line do?

	}
}
char ShipPlacement::getOrientation()
{
	return orientation;
}
