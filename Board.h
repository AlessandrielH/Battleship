#pragma once

#ifndef BOARD
#define BOARD

class Board
{
private:
	static const int boardsize = 10;
	char board[boardsize][boardsize];
public:

	Board();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~creates a playerboard object                                        ~
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	int getSize();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~returns an integer                                                  ~
	~Purpose:  returns  boardsize                                        ~
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void createBoard();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~No values Accepted                                                 ~
	~no values returned                                                 ~
	~Purpose:  creates the player board                                 ~
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void displayBoard();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~No values Accepted                                                 ~
	~no values returned                                                 ~
	~Purpose:  display the board                                        ~
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void updateBoard(bool hit, int x, int y);
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~Accepts: bool hit, int x, int y                                    ~
	~No values returned                                                 ~
	~Purpose:   adds an attack to the board. 'M' will be entered at     ~
	~          board[x][y] if the attack missed.  'H' will be entered   ~
	~          if attack hit a battleship.                              ~
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	char confirmHit(int xCoord, int yCoord);
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~Accepted: int xCoord, int yCoord                                   ~
	~Return: char                                                       ~
	~Purpose:   retrieves the value on the board                        ~
	~         at position(xCoord,yCoord)                                ~
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void setShip(int x, int y);
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~Accepted: int x, int y                                             ~
	~Return: nothing                                                    ~
	~Purpose:   places a ship on the board at the                       ~
	~            position(xCoord,yCoord), sets that position to '1'     ~
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
	bool compareBoard(Board b);

};

#endif
