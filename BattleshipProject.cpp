// BattleshipProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//By: Joycelyn Minor, Jessica Minor, and Alessandriel Harper
//28 June 2021

#include <iostream>
#include <string>
#include "Board.h"
#include "Ship.h"

using namespace std;

void Attack(string, int*, int*);
bool hitSuccess(Board, int, int);
bool GameOver( Board, Board);

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
        string player2;//plater2 name
        int xCoordinate, yCoordinates;//attack coordinates
        bool gameOver=false;
        bool hit = false;//ataack verification
        
        Board p1BoardA();
        Board p2BoardA();
         
        displayMenu();
        int choice;  
        cout<< "Select an option from the menu above. ";  
        cin >> choice;    
        if (choice == 1)    
        {        
            string player1, player2;        
            cout << "Enter player 1's name: ";        
            cin >> player1; 
            cout<< "Hello "<<player1<< ". "<<endl;
            cout << "Enter player 2's name: ";        
            cin >> player2;  
            cout<< "Hello "<<player2<< ". "<<endl;   

            // builds the gameboard for player1
            cout << "Creating board for " << player1 << endl;
            Board p1Board;
            p1Board.createBoard();
            p1Board.displayBoard();

            //Place battleship for player1


            // builds the gameboard for player2
            cout << "Creating board for " << player2 << endl;
            Board p2Board;
            p2Board.createBoard();
            p2Board.displayBoard();

            //Place battleship for player2
           
        
            do
            {
                //display player1 attack board
                p1BoardA().displayBoard();
                Attack(player1, &xCoordinate, &yCoordinates);

                //updateboard
                cout << player1 << "'s attack board is updated!" << endl;
                //check player2 board[xCoordinate][yCoordinate]for hit
                hit=hitSuccess(p2Board, xCoordinate, yCoordinates);
                if (hit == true)
                {
                    //Check gameOver
                    gameOver=GameOver(p1BoardA, p2Board);
                    hit = false;
                }

                //Player2's turn

                //display player2 attack board
                p2BoardA().displayBoard();
                Attack(player2, &xCoordinate, &yCoordinates);

                //updateboard
                cout << player2 << "'s attack board is updated!" << endl;
        
                //check player1 board[xCoordinate][yCoordinate]for hit
                hit=hitSuccess(p1Board, xCoordinate,yCoordinates);
                
                if (hit == true)
                {
                    //Update gameOver
                    gameOver=GameOver(p2BoardA, p1Board);
                    hit = false;
                }
        
            } while (gameOver != true);
        }    
        else if (choice == 2)    
        {        
            cout << "Goodbye for now." << endl;
            playAgain=false;
        }  
    }
    return 0;
};
bool hitSuccess(Board b[][], int x, int y)
{
    if (b[x][y]=='X')
    {
     return true;   
    }
}

void Attack(string name, int* x, int* y)
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

        if (tempX < 0 || tempX>10 || tempY < 0 || tempY>10)
        {
            cout << name << "Incorrect x or y coordinants." << endl;
            cout << "Coordinants must range from 0-10." << endl;
        }
        else
        {
            *x = tempX;
            *y = tempY;
        }
    } while (*x==-1||*y==-1);
}

bool gameOver(Board attacker[][], Board victim[][])
{
    int size =10;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
          if (attacker[i][j]!=victim[i][j])
          {
              return false;
          }
        }
    }
    return true;
}
