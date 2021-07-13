#include "Board.h"
#include <string>
using namespace std;

	
	void ShipPlacement::placeShips(Board b)
		/* this function accepts: 3 variables to store char orientation, int x coordinate, int y coordinate.
		No values returned.
		Stores orientation (v for vertical, h for horizontal) that user inputs.
		Stores x and y coordinates from user.
		*/
	{
		for (int n = 0; n < 4; n++)
		{
			cout << "Your " << oNos[n] << " ship is named " << names[n] << endl; //oNos is ordinal number
			cout << "This ship is " << units[n] << " long."; //units refers to the length of the ship
			cout << "Do you want it to be vertical or horizontal: v/h? "; // v and h refers to the orientation 
			cin >> orientation;
			cout << "Set the x-coordinate for the beginninng of the ship:";
			cin >> xCoord;
			cout << "Set the y-coordinate for the beginning of the ship:";
			cin >> yCoord;
			setShipPlacement(b);
		}
		
		xCoord = x;
		yCoord = y;
		cout << orientation << " " << xCoord << " " << yCoord;
		
		//jgminor7 added code below so user doesn't place a ship out-of-bounds of board area
		do 
		    {

			(if board.xCoord < 1 || board.xCoord >9  ) //const int COL = 10
			(if board.yCoord < 1 || board.yCoord >9  )//const int ROW = 10;
			/*Is there a separate statement for x coordinte and y coordinate? 
			Should I refer to COL and ROW, instead of xCoord and yCoord? */

			cout<<"Your coordinates are out of bounds. Please enter valid x coordinate and y coordinate within 1 to 9.";
			//Is it 1- 9 or 1 -10?
		
			cout << "Set the x-coordinate for the beginninng of the ship:";
			cin >> xCoord;
			cout << "Set the y-coordinate for the beginning of the ship:";
			cin >> yCoord;
		    }
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
