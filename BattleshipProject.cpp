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
//bool hitSuccess(Board, int, int);
bool GAMEOVER( Board, Board, string name);

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
        bool hit = true;//attack verification

        Board p1AttackBoard;
        Board p2AttackBoard;
        p1AttackBoard.createBoard();
        p2AttackBoard.createBoard();

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
                cout << "****************************************************************" << endl;
                cout << "Enter player 2's name: ";
                cin >> player2;
                cout << "Hello " << player2 << ". " << endl;
                cout <<"****************************************************************" << endl;
            // builds the gameboard for player1
            cout << "Creating board for " << player1 << endl;
            Board p1DefenseBoard;
            p1DefenseBoard.createBoard();
            p1DefenseBoard.displayBoard();

            //Place battleship for player1
            ShipPlacement p1Ships;
            p1Ships.placeShips(p1DefenseBoard);
        

            // builds the gameboard for player2
            cout << "****************************************************************" << endl;
            cout << "Creating board for " << player2 << endl;
            Board p2DefenseBoard;
            p2DefenseBoard.createBoard();
            p2DefenseBoard.displayBoard();

            //Place battleship for player2
            ShipPlacement p2Ships;
            p2Ships.placeShips(p2DefenseBoard);
           

            do
            {
                //display player1 attack board
                p1AttackBoard.displayBoard();
                Attack(player1, &xCoordinate, &yCoordinates,p1AttackBoard);

                cout << "****************************************************************" << endl;
                cout << player1 << "'s attack board is updated!" << endl;
                //check player2 board[xCoordinate][yCoordinate]for hit
                if (p2DefenseBoard.confirmHit(xCoordinate, yCoordinates) == 'X')
                {
                    hit= true;
                }
                else if (p2DefenseBoard.confirmHit(xCoordinate, yCoordinates) == '~')
                {
                    hit=false;
                }
                else { cout << "ERROR" << endl; }

                if (hit == true)
                {}
                else 
                {
                    cout <<" hit is false" << endl; 
                }
                //updateboard
                p1AttackBoard.updateBoard(hit, xCoordinate, yCoordinates);
                //Check gameOver
                gameOver = GAMEOVER(p1AttackBoard, p2DefenseBoard, player1);
                p1AttackBoard.displayBoard();
                cout << "****************************************************************" << endl;
                cout << "****************************************************************" << endl;
                if (gameOver == true)
                {
                    break;
                }

                //Player2's turn

                //display player2 attack board
                p2AttackBoard.displayBoard();
                Attack(player2, &xCoordinate, &yCoordinates,p2AttackBoard);

                cout << "****************************************************************" << endl;
                cout << player2 << "'s attack board is updated!" << endl;

                //check player1 board[xCoordinate][yCoordinate]for hit
                
                if (p1DefenseBoard.confirmHit(xCoordinate, yCoordinates) == 'X')
                {
                    hit = true;
                }
                else if (p1DefenseBoard.confirmHit(xCoordinate, yCoordinates) == '~')
                {
                    hit = false;
                }
                else { cout << "ERROR" << endl; }

                if (hit == true)
                {}
                else 
                { 
                    cout << " hit is false" << endl; 
                }
                //updateboard
                p2AttackBoard.updateBoard(hit, xCoordinate, yCoordinates);
                //Update gameOver
                gameOver = GAMEOVER(p2AttackBoard, p1DefenseBoard, player2);
                p2AttackBoard.displayBoard();
                cout << "****************************************************************" << endl;
                cout << "****************************************************************" << endl;

            } while (gameOver != true);
        }
        else if (choice == 2)
        {
            cout << "****************************************************************" << endl;
            cout << "Goodbye for now." << endl;
            playAgain = false;
        }
    }
    return 0;
};


void Attack(string name, int *x, int* y, Board b)
{
    *x = -1;
    *y = -1;
    int tempX, tempY;
    do {
        cout << "****************************************************************" << endl;
        cout << name << " will now attack!!!" << endl;
        cout << name << ", enter the x-coordinates: ";
        cin >> tempX;
        cout << name << ", enter the y-coordinates: ";
        cin >> tempY;

        if (tempX < 0 || tempX>COL || tempY < 0 || tempY>ROW)
        {      
            cout << "****************************************************************" << endl;
            cout << name << "Incorrect x or y coordinates." << endl;
            cout << "Coordinants must range from 0-"<< COL <<"." << endl;
        }
        
        else
        {
            if  (b.confirmHit (tempX,tempY) == 'H' || b.confirmHit (tempX,tempY) == 'M')
            {
                cout << "****************************************************************" << endl;
                cout << name << "You have entered those x and y coordinates already!"<< endl;
                 *x = -1;
                 *y = -1;
            }
            else
            {
                cout << "Your attack has been confirmed" << endl;
                *x = tempX;
                *y = tempY;
            }
        }

    } while (*x == -1 || *y == -1);
}

bool GAMEOVER(Board attacker, Board victim, string name)
{
    bool g;
    bool gameOver=false;
    int countH = 0;
    int countM = 0; //for debug
    int countE = 0;//for debug
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (attacker.confirmHit(i, j) == 'H')
            {
                countH++;
                cout << "You have " << countH << " hits." << endl;
                if (countH == 18)
                {
                    gameOver = true;
                }
            }
            else if(attacker.confirmHit(i,j)=='M')
            {
                countM++;
               // cout << "You have " << countM << " misses." << endl;
            }
            else if(attacker.confirmHit(i,j)=='~')
            {
                countE++;
                //cout << "You have " << countE << " empty slots." << endl;for debug 
            }
        }
    }

    if (gameOver==false)
    {   
        cout << "The game is not over yet!!!" << endl;
        g= false;
    }
    else
    {
        cout << "***************************************" << endl;
        cout << "GAMEOVER!!!!!!!!!!!!" << endl;
        cout << name << " wins!!!!!!!!!!!!!" << endl;
        cout << "***************************************" << endl;
        g= true;
    }
    return g;
}
