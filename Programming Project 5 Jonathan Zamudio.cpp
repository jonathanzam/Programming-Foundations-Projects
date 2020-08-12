//---------------------------------------------------------------------------
// Purpose:  To simulate the lives of rabbits and foxes in the forest.
//
// Author:   John Gauch - Created skeleton program.
// Author:   Jonathan Zamudio - Completed implementation.
//
// Change:   Fixed animal loss bug in move_board function -- 11/03 JMG
// Change:   Fixed infinite loop bug in choose_move function -- 11/03 JMG
// Change:   Removed second board from main function -- 11/03 JMG
// Change:   Printed animal counts in draw_board -- 11/03 JMG
//---------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

// Global Variables
const int SIZE = 20;

//---------------------------------------------------------------------------
// Purpose: To initialize the board with rabbits and foxes.
// Inputs:  The board, the number of rabbits, the number of foxes.
// Outputs: None
//---------------------------------------------------------------------------
void init_board(char board[SIZE][SIZE], 
   const int num_rabbits, const int num_foxes)
{
   // Init board
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         board[r][c] = ' ';

   // Add rabbits at random locations
   int count = 0;
   while (count < num_rabbits)
   {
      int r = random() % SIZE;
      int c = random() % SIZE;
      if (board[r][c] == ' ')
      {
         board[r][c] = 'R';
         count++;
      }
   }

   // Add foxes at random locations
   count = 0;
   while (count < num_foxes)
   {
      int r = random() % SIZE;
      int c = random() % SIZE;
      if (board[r][c] == ' ')
      {
         board[r][c] = 'F';
         count++;
      }
   }
}

//---------------------------------------------------------------------------
// Purpose: To draw the board with rabbits and foxes.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void draw_board(char board[SIZE][SIZE])
{
   system("sleep 1");
   system("clear");

   // Initialize animal counts
   int num_rabbits = 0; 
   int num_foxes = 0; 

   // Draw top of board
   cout << "+";
   for (int c = 0; c < SIZE; c++)
      cout << "--";
   cout << "+\n";

   // Draw board
   for (int r = 0; r < SIZE; r++)
   {
      cout << "|";
      for (int c = 0; c < SIZE; c++)
      {
         cout << board[r][c] << " ";

         // Increment animal counts
         if (board[r][c] == 'R')
            num_rabbits++;
         if (board[r][c] == 'F')
            num_foxes++;
      }
      cout << "|\n";
   }

   // Draw bottom of the board
   cout << "+";
   for (int c = 0; c < SIZE; c++)
      cout << "--";
   cout << "+\n";

   // Print animal counts
   cout << "Number of rabbits: " << num_rabbits << endl;
   cout << "Number of foxes:   " << num_foxes << endl;
}

//---------------------------------------------------------------------------
// Purpose: To choose a random direction to move.
// Inputs:  The board and the current row and column location.
// Outputs: The new row and column location on the board.
//---------------------------------------------------------------------------
void choose_move(char board[SIZE][SIZE],
   const int row, const int col, int & new_row, int & new_col)
{
   // Loop until a valid move is found
   for (int loop = 0; loop < 10; loop++)
   {
      // Take a random step to adjacent location
      new_row = row + (random() % 3) - 1;
      new_col = col + (random() % 3) - 1;

      // Check if location is in bounds and board is empty
      if ((new_row >= 0) && (new_row < SIZE) &&
          (new_col >= 0) && (new_col < SIZE) &&
          (board[new_row][new_col] == ' '))
         return;
   }

   // Use current location if other move is possible
   new_row = row;
   new_col = col;
}

//---------------------------------------------------------------------------
// Purpose: To move the rabbits and foxes on the board.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void move_animals(char board[SIZE][SIZE])
{
   // Loop over board to find and move animals
   int new_row = 0;
   int new_col = 0;
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         if (isupper(board[r][c]))
         {
            // Find empty location for move
            choose_move(board, r, c, new_row, new_col);

            // Move animal into empty location
            board[new_row][new_col] = tolower(board[r][c]);

            // Make old location empty
            if ((new_row != r) || (new_col != c))
               board[r][c] = ' ';
         }

   // Loop over board to change letters to upper case
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         board[r][c] = toupper(board[r][c]);
}

//Function to simulate the reproduction of foxes and rabbits
void reproduction(char board[SIZE][SIZE])
{
   // Loop over entire board
   for (int r = 0; r < SIZE; r++)
   {
      for (int c = 0; c < SIZE; c++)
      {
         if(board[r][c] == 'R')
	 {
	  // Check if location to the right is in bounds and board has rabbit
	  if ((c+1 < SIZE) && (board[r][c+1] == 'R'))
	  {
	     int new_row = 0; int new_col = 0;
	     //loops to create a new rabbit in an empty spot on the array
	     do{
		int new_row = random() % SIZE;
	        int new_col = random() % SIZE;
            	if (board[new_row][new_col] == ' ')
                    board[new_row][new_col] = 'R';
		}while(board[new_row][new_col]!=' ' && board[new_row][new_col]!='F');
	  }
	 }

	if(board[r][c] == 'F')
	 {
	   // Check if location below is in bounds and has fox
	   if ((r+1<SIZE) && (board[r+1][c] == 'F') && (random()%2 == 1))
	   {
	     int new_row = 0; int new_col = 0;
	     //loops to create a fox in an empty array slot
	     do{
	        int new_row = random() % SIZE;
	        int new_col = random() % SIZE;
		if(board[new_row][new_col] == ' ')
		   board[new_row][new_col] = 'F';
	       }while(board[new_row][new_col]!=' ' && board[new_row][new_col]!='R');
	   }
	 }
      }//end row for-loop
   }//end col for-loop
}

//function to simulate battles between fox and rabbit
void battle(char board[SIZE][SIZE])
{
   bool rab_kill = false;
   int kill = 0;
   //loop over board
   for(int r = 0; r<SIZE; r++)
   {
      for(int c = 0; c<SIZE; c++)
      {
	//if there is a fox, search boxes above, below, left, and right
	if(board[r][c] == 'F')
	{
	   if((r-1)>0 && board[r-1][c] == 'R')
	   {
	      kill = random() % 10;
	      if(kill==7)
	      {
		 board[r-1][c]=' ';
		 rab_kill = true;
	      }
	   }
           if((r+1)<SIZE && board[r+1][c] == 'R')
	   {
             kill = random() % 10;
             if(kill==7)
	     {
                board[r+1][c]=' ';
		rab_kill = true;
	      }
	   }
           if((c-1)>0 && board[r][c-1] == 'R')
	   {
             kill = random() % 10;
             if(kill==7)
	     {
                board[r][c-1]=' ';
		rab_kill = true;
	     }
	   }
           if((c+1)<SIZE && board[r][c+1] == 'R')
	   {
             kill = random() % 10;
             if(kill==7)
	     {
                board[r][c+1]=' ';
		rab_kill=true;
	     }
	   }
	}
      }//end col for loop
   }//end row for loop

   //if no rabbits killed this round, chance to kill off a fox
   if(rab_kill == false)
   {
	int row = 0; int col = 0;
	for(int loop = 0; loop<5; loop++)
	{
	   row = random() % SIZE;
	   col = random() % SIZE;
	   if(board[row][col] == 'F')
		board[row][col] = ' ';
	}
   }
}
//---------------------------------------------------------------------------
// Purpose: The main program.
// Inputs:  None.
// Outputs: None.
//---------------------------------------------------------------------------
int main()
{
   // Seed the random number generator 
   srandom(time(NULL));

   // Prompt user
   cout << "Welcome to the fox and rabbit simulation\n\n";
   int num_rabbits = 0;
   cout << "Enter the number of rabbits: ";
   cin >> num_rabbits;
   int num_foxes = 0;
   cout << "Enter the number of foxes: ";
   cin >> num_foxes;
   int num_steps = 0;
   cout << "Enter the number of simulation steps: ";
   cin >> num_steps;
   
   // Initialize board
   char board[SIZE][SIZE];
   init_board(board, num_rabbits, num_foxes);

   // Draw the board
   draw_board(board);
   cout << "Start " << endl;

   // Run the simulation
   for (int step = 1; step <= num_steps; step++)
   {
      // Move the animals
      reproduction(board);
      battle(board);
      move_animals(board);
      // Draw the board
      draw_board(board);
      cout << "Step " << step << endl;
   }
   return 0;
}
