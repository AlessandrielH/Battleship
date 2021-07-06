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
void Board::displayBoard(const char battleboard[][boardsize], const int s)
{
    //prints board
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << battleboard[i][j];
        }
        cout << endl;
    }
}

void Board::displayBoard()
{
    int s = boardsize;
    //prints board
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void Board:: createBoard(char battleboard[][boardsize], const int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            battleboard[i][j] = '~';//inputs ''~ into every position
        }
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

