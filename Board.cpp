#include "Board.h"
#include<iostream>

using namespace std;

Board::Board()
{
    createBoard();
}

int Board::getSize()
{
    return SIZE;
}

char Board::confirmHit(int x, int y)
{
    //cout <<"at "<<x<<", "<<y<<" there is a "<< board[x][y] << endl;
    return board[x][y];
}

void Board::displayBoard()
{
    cout << "   ";
    for (int a = 0; a < SIZE; a++)
    {
        cout << a << "|";
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "|" << i << "|";
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}

void Board::createBoard()
{
    int s = SIZE;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            board[i][j] = '~';//inputs ''~ into every position
        }
    }
}

void Board::setShip(int x, int y)
{
    board[x][ y] = 'X';
}

void Board::updateBoard(bool hit, int x, int y) //This function updates the board after attack
{
    if (hit==true)
    {
       board[x][y]='H'; //the letter H shows that this ship has been hit
       cout << "You hit a battleship!!!" << endl;
    }
    else if(hit==false)
    {
       board[x][y]='M'; //the letter M shows that this spot is a miss because no ship was placed there
       cout << "You missed!!! Hahaha!!!" << endl;
    }
}
