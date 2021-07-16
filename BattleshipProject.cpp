// BattleshipProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//By: Joycelyn Minor, Jessica Minor, and Alessandriel Harper
//28 June 2021

#include <iostream>
#include <string>
#include "Board.h"
#include "ShipPlacement.h"

const int COL = 10;
const int ROW = 10;

using namespace std;

void Attack(string, int*, int*, Board);
bool hitSuccess(Board, int, int);
bool GAMEOVER( Board,Board);
bool compareBoard(Board, Board);

void displayMenu()
{
    cout << "****************************************" << endl;
    cout << "*            BattleShip Game           *" << endl;
    cout << "*                  By                  *" << endl;
    cout << "*   A. Harper, J. Minor, & J. Minor    *" << endl;
    cout << "****************************************" << endl;
    cout << "* 1. Play game. Enter players' names.  *" << endl;
    cout << "* 2. Exit game.                        *" << endl;
    cout << "****************************************" << endl;
}

int main()
{
    string response;
    bool playAgain = true;
    while (playAgain == true)
    {
        string player1;//player1 name
        string player2;//player2 name

        int xCoordinate ,yCoordinates;//attack coordinates
        bool gameOver = false;
        bool hit = false;//attack verification

        Board p1BoardA;
        Board p2BoardA;
        p1BoardA.createBoard();
        p2BoardA.createBoard();

        displayMenu();
        int choice;
        cout << "Select an option from the menu above. ";
        cin >> choice;
        while(choice < 1 || choice > 2)
            {
                cout << "Please select an integer from 1 or 2" << endl;
                cin.clear();
                cin.ignore(10000, '\n'); // this line eliminated the infinite loop issue
                cin >> choice;
            }
        if (choice == 1)
            {
                string player1, player2;
                cout << "Enter player 1's name: ";
                cin >> player1;
                cout << "Hello " << player1 << ". " << endl;
                cout << "Enter player 2's name: ";
                cin >> player2;
                cout << "Hello " << player2 << ". " << endl;
             
            // builds the gameboard for player1
            cout << "Creating board for " << player1 << endl;
            Board p1Board;
            p1Board.createBoard();
            p1Board.displayBoard();

            //Place battleship for player1
            ShipPlacement p1Ships;
            p1Ships.placeShips(p1Board);
        

            // builds the gameboard for player2
            cout << "Creating board for " << player2 << endl;
            Board p2Board;
            p2Board.createBoard();
            p2Board.displayBoard();

            //Place battleship for player2
            ShipPlacement p2Ships;
            p2Ships.placeShips(p2Board);
           

            do
            {
                //display player1 attack board
                p1BoardA.displayBoard();
                Attack(player1, &xCoordinate, &yCoordinates,p1BoardA);

                //updateboard
                cout << player1 << "'s attack board is updated!" << endl;
                //check player2 board[xCoordinate][yCoordinate]for hit
                hit = hitSuccess(p2Board, xCoordinate, yCoordinates);
                if (hit == true)
                {
                    //Check gameOver
                    gameOver = GAMEOVER(p1BoardA, p2Board);
                    hit = false;
                }

                //Player2's turn

                //display player2 attack board
                p2BoardA.displayBoard();
                Attack(player2, &xCoordinate, &yCoordinates,p1BoardA);

                //updateboard
                cout << player2 << "'s attack board is updated!" << endl;

                //check player1 board[xCoordinate][yCoordinate]for hit
                hit = hitSuccess(p1Board, xCoordinate, yCoordinates);

                if (hit == true)
                {
                    //Update gameOver
                    gameOver = GAMEOVER(p2BoardA, p1Board);
                    hit = false;
                }

            } while (gameOver != true);
        }
        else if (choice == 2)
        {
            cout << "Goodbye for now." << endl;
            playAgain = false;
        }
    }
    return 0;
};
bool hitSuccess(Board b, int x, int y)
{
    if (b.confirmHit(x, y) == 'X')
    {
        return true;
    }
    else {return false;}
}

void Attack(string name, int *x, int* y, Board b)
{
    *x = -1;
    *y = -1;
    int tempX, tempY;
    do {
        cout << name << " will now attack!!!" << endl;
        cout << name << ", enter the x-coordinates: ";
        cin >> tempX;
        cout << name << ", enter the y-coordinates: ";
        cin >> tempY;

        if (tempX < 0 || tempX>COL || tempY < 0 || tempY>ROW)
        {

            cout << name << "Incorrect x or y coordinants." << endl;
            cout << "Coordinants must range from 0-" << COL << "." << endl;
        }
        
        else
        {
            if  (b.confirmHit (tempX,tempY) == 'H' || b.confirmHit (tempX,tempY) == 'M')
            {
                cout << name << "You have entered those x and y coordinates already!"<< endl;
                 *x = -1;
                 *y = -1;
            }
            
            else
            {
                *x = tempX;
                *y = tempY;
            }
        }

    } while (*x == -1 || *y == -1);
}

bool GAMEOVER(Board attacker, Board victim)
{
    if (compareBoard(attacker, victim)==false)
    {        
        return false;
    }
    else
    {
        return true;
    }
}

bool compareBoard(Board attacker, Board victim)
{
    bool gameOver = false;
    int count = 0;
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (attacker.confirmHit(i, j) == 'H' && victim.confirmHit(i, j) == 'X')
            {
                count++;
                if (count == 18)
                {
                    gameOver = true;
                }
            }
        }
    }
    return gameOver;
}
