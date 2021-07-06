# Battleship
Created by:
Jessica Minor,
Joycelyn Minor,
Alessandriel Harper

Overview:

The object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere on his/her board.  You try and hit them by calling out the coordinates of one of the squares on the board.  The other player also tries to hit your ships by calling out coordinates.  Neither you nor the other player can see the other's board so you must try to guess where they are.  Each board in the physical game has two grids:  the lower (horizontal) section for the player's ships and the upper part (vertical during play) for recording the player's guesses.

Battleship can typically be played on a 10x10 board using ships of various lengths. These ships can either go horizontally or vertically.

The winner of the game is the person who can take out each player's ships first. 


Objective
Work on a team project
Reinforce the concept of object-oriented programming
Gain experience working with function/classes

Requirements: 

Create a game board:
Create a game board that is at least 10x10 (Dimensions up to your team)
Draw board and make it visible to player 1 on their turn, and player 2 on theirs.
Each player will have their own board to target

Player Places ships:
Each player can place their ships either horizontally, or vertically on the board.
Each player is given their own turn to play their own ships

Toggle to the next player
Each player can take turns attacking/guessing where the other players ship are, then alternates to the next player

Game Loop / Is Game Finished
Have a loop of the game running while both players have their battleships alive
If one of the players battleships are all taken out, then they lose 

Player X attacks (Rows & Columns)
Player gets to put in a row/column for their attack / User Input
Check if valid hit and mark an X if it’s a hit, a 0 if it is a miss.
Update the board to represent how they performed

Game over check
Perform a game over check 
Exit loop/end program

Required Ship Amount
Have at least 2 different ship sizes (Length of 3, 4, 5, etc)
Have at least 4 ships.
