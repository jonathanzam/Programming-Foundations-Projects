//---------------------------------------------------
// Purpose:     Main program for the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              Jonathan Zamudio - Completed implementation.
//---------------------------------------------------

#include "tic4.h"
Tic4 tic;
//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------

//gets move from player
void move(char player, int &row, int &col)
{

   if(player == 'X')
   {
        cout << "Player X enter move: ";
        cin >> row >> col;
	//gets value from the board space and checks if it is empty
	tic.GetBoard(row,col,player);
	if(player!=' ')//if space is not empty, calls function again
	{
	   cout << "Space is occupied/invalid, try again\n";
	   move('X', row, col);
	}
        tic.SetBoard(row, col, 'X');//if space is empty, places X into it
   }

   if(player == 'O')
   {
	cout << "Player O enter move: ";
	cin >> row >> col;
	//gets value from the board space and checks if it is empty
	tic.GetBoard(row,col,player);
	if(player!= ' ')//if not empty, calls function again
	{
	   cout << "Space is occupied, try again\n";
	   move('O', row, col);
	}
        tic.SetBoard(row, col, 'O');//is empty, places O into it
   }
}

//alternates player
void change_player(int count, char &player)
{
   if (count%2==0)
	player = 'X';
   if (count%2==1)
	player = 'O';
}

int main()
{
   //declares variables, adds a clear screen at start of game
   //and clears board in case of new game start
   system("clear");
   tic.ClearBoard();
   int count = 0;
   int row = 0; int col = 0;
   char player = ' ';
   char play_again = ' ';

   //prints some instructions for the game
   cout << "Welcome to 4x4 tic tac toe!\n\n"
	<< "How to play: Enter your space using [row] [col] notation.\n"
	<< "X will go first, then O. Please do NOT enter words, it breaks "
	<< "the game! Enjoy, and goood luck player.\n\n";

   tic.PrintBoard();

   do
   {
      change_player(count, player);
      move(player, row, col);
      tic.PrintBoard();
   count++;

   //if board is full, gives option to start over or end
   if(tic.IsFull() == 1)
   {
      cout << "It's a tie!\nWould you like to try again? (Y/N)\n\n";
      cin >> play_again;
      if(play_again == 'Y' || play_again == 'y')
	main();
      else
	return 0;
   }
   }while(tic.CheckWin(player) == false);//runs game until a winner is found

   //prints out win message when winner is found
   if(tic.CheckWin(player) == true)
	cout << "Player " << player << " wins!! Congratulations!\n\n\n";

   return 0;
}
