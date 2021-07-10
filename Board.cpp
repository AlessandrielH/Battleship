#include "Board.h"
#include<iostream>

using namespace std;

Board::Board()
{
    createBoard();
}

int Board::getSize()
{
    return boardsize;
}

char Board::confirmHit(int x, int y)
{
    return board[x][y];
}

void Board::displayBoard()
{
    int s = boardsize;
    cout << "   ";
    for (int a = 0; a < s; a++)
    {
        cout << a << "|";
    }
    cout << endl;
    for (int i = 0; i < s; i++)
    {
        cout << "|" << i << "|";
        for (int j = 0; j < s; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}

void Board::createBoard()
{
    int s = boardsize;
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
    board[x][ y] = '1';
}
