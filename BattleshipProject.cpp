// BattleshipProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//By: Joycelyn Minor, Jessica Minor, and Alessandriel Harper
//28 June 2021

#include <iostream>
#include <string>
#include "Board.h"
#include "Battleship.h"

const int COL=10;
const int ROW=10;

using namespace std;

void Attack(string, int*, int*);
bool hitSuccess(Board, int, int);
void setShips(Battleship, Board,int, int, int, int, int);
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
        string player2;//player2 name
        int x1, x2, y1, y2;//ship placement coordinants
        int xCoordinate, yCoordinates;//attack coordinates
        int size = 3;//Ship size
        bool gameOver=false;
        bool hit = false;//attack verification
        
        Board p1BoardA;
        Board p2BoardA;
        p1BoardA();
        p2BoardA();
         
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
            p1Board();
            p1Board.createBoard();
            p1Board.displayBoard();

            //Place battleship for player1
            Battleship p1ShipA;
            cout << player1 << ", please place first battleship." << endl;
            setShips(p1ShipA,p1Board, size, x1, y1, x2, y2);
            //Place battleship for player1
            cout << player1 << ", please place second battleship." << endl;
            Battleship p1ShipB;
            setShips(p1ShipB, p1Board, size, x1, y1, x2, y2);
            //Place battleship for player1
            cout << player1 << ", please place third battleship." << endl;
            Battleship p1ShipC;
            setShips(p1ShipC, p1Board, size, x1, y1, x2, y2);
            //Place battleship for player1
            cout << player1 << ", please place fourth battleship." << endl;
            Battleship p1ShipD;
            setShips(p1ShipD, p1Board, size, x1, y1, x2, y2);

            // builds the gameboard for player2
            cout << "Creating board for " << player2 << endl;
            Board p2Board;
            p2Board();
            p2Board.createBoard();
            p2Board.displayBoard();

            //Place battleship for player2
            cout << player2 << ", please place first battleship." << endl;
            Battleship p2ShipA;
            setShips(p2ShipA, p2Board, size, x1, y1, x2, y2);
            //Place battleship for player2
            cout << player2 << ", please place second battleship." << endl;
            Battleship p2ShipB;
            setShips(p2ShipB, p2Board, size, x1, y1, x2, y2);
            //Place battleship for player2
            cout << player2 << ", please place third battleship." << endl;
            Battleship p2ShipC;
            setShips(p2ShipC, p2Board, size, x1, y1, x2, y2);
            //Place battleship for player2
            cout << player2 << ", please place fourth battleship." << endl;
            Battleship p2ShipD;
            setShips(p2ShipD, p2Board, size, x1, y1, x2, y2);
        
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
bool hitSuccess(Board b, int x, int y)
{
    if (b.confirmHit(x,y))=='X')
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

        if (tempX < 0 || tempX>COL || tempY < 0 || tempY>ROW)
        {
            cout << name << "Incorrect x or y coordinants." << endl;
            cout << "Coordinants must range from 0-"<<COL<<"." << endl;
        }
        else
        {
            *x = tempX;
            *y = tempY;
        }
    } while (*x==-1||*y==-1);
}

void setShips(Battleship ship,Board b,int size, int x1, int y1, int x2, int y2)
{
    bool error = true;
    do
    {
        cout << "Enter the x-coordinant for the front of battleship: ";
        cin >> x1;
        cout << "Enter the y-coordinant for the front of battleship: ";
        cin >> y1;
        cout << "Enter the x-coordinant for the back of battleship: ";
        cin >> x2;
        cout << "Enter the y-coordinant for the back of battleship: ";
        cin >> y2;

        if (x1<0 || x1>b.getsize() || x2<0 || x2>b.getsize() || y1<0 || y1>b.getsize() || y2<0 || y2>b.getsize())
        {
            error = true;
        }
        else
        {
            error = false;
        }
    } while (error ==true);


    ship.placeShip(b, size, x1, y1, x2, y2);
}

bool gameOver(Board attacker, Board victim)
{
    int size =COL;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
          if (attacker.confirmHit(i,j)!=victim.confirmHit(i,j))
          {
              return false;
          }
        }
    }
    return true;
}

