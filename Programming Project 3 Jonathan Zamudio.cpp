//--------------------------------------------------------------
//              Author: Jonathan Zamudio
//              Title:  Flag
//              This program will create a flag of the user's
//              specified size. The user will also get to
//              choose the country of the flag. The output
//              will be in an image of the flag.
//--------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//functions for flags using special characters for testing
//function for rounding: %2=0, %3=0, col++/row++
void RoundWidth(int &width)
{
   while(width%3 != 0) width++;
}

void RoundLength(int &length)
{
   while(length%3 !=0) length++;
}

//Hungary
void Hungary(int width, int length)
{
   ofstream dout;
   dout.open("Hungary.ppm");
   dout <<  "P3" << endl << width << " " << length << endl << "255" << endl;

   for(int row = 0; row < length; row++)
   {
      for (int col = 0; col < width; col++)
      {
	    if(row < length/3) dout << "255 0 0 ";
	    else if (length/3 <= row && row < 2*length/3) dout << "255 255 255 ";
	    else dout << "0 128 0 ";
      }
	   dout << endl;
   }
	dout.close();
}
//Italy
void Italy(int width, int length)
{
   ofstream dout;
   dout.open("Italy.ppm");
   dout <<  "P3" << endl << width << " " << length << endl << "255" << endl;
   for(int row = 0; row < length; row++)
   {
      for(int col = 0; col < width; col++)
      {
	   if(col < width/3) dout << "0 128 0 ";
	   else if (width/3 <= col && col < 2*width/3) dout << "255 255 255 ";
	   else dout << "255 0 0 ";
      }
	   dout << endl;
   }
	dout.close();
}
//Germany
void Germany(int width, int length)
{
   ofstream dout;
   dout.open("Germany.ppm");
   dout <<  "P3" << endl << width << " " << length << endl << "255" << endl;
   for(int row = 0; row < length; row++)
   {
      for(int col = 0; col < width; col++)
      {
	   if(row < length/3) dout << "0 0 0 ";
           else if (length/3 <= row && row < 2*length/3) dout << "255 0 0 ";
           else dout << "255 255 0 ";
      }
           dout << endl;
   }
	dout.close();
}
//Bangladesh
void Bangladesh(int width, int length)
{
   ofstream dout;
   dout.open("Bangladesh.ppm");
   dout <<  "P3" << endl << width << " " << length << endl << "255" << endl;
   //calculate center for circle and radius to fill in
   int x_center = width/2;
   int y_center = length/2;
   int radius = (pow(x_center/4,2)) + (pow(y_center/4,2));
   for (int row = 0; row < length; row++)
   {
      for(int col = 0; col < width; col++)
      {
        if((pow((col-x_center),2) + pow((row-y_center),2)) <= radius) dout << "255 0 0 ";
        else dout << "0 51 0 ";
      }
        dout << endl;
   }
	dout.close();
}
//Japan
void Japan(int width, int length)
{
   ofstream dout;
   dout.open("Japan.ppm");
   dout <<  "P3" << endl << width << " " << length << endl << "255" << endl;
   //calculate center for circle and radius to fill in
   int x_center = width/2;
   int y_center = length/2;
   int radius = (pow(x_center/4,2)+pow(y_center/4,2));
   for (int row = 0; row < length; row++)
   {
      for(int col = 0; col < width; col++)
      {
        if((pow((col-x_center),2) + pow((row-y_center),2)) <= radius) dout << "255 0 0 ";
        else dout << "255 255 255 ";
      }
        dout << endl;
   }
	dout.close();
}


int main ()
{
   //declare variables
   int length = 0, width = 0, country = 0;
   bool input = false;

   //ask for input (width/length) & country of choice
   //also error check for wrong country chosen
   while (input == false)
   {
   cout << "Hello!!!\n\nPlease enter the amount of columns of your flag (100..1000): ";
   cin >> width;
   cout	<< "\nPlease enter the amount of rows of your flag (100..1000): ";
   cin >> length;
   cout << endl << "1)Hungary, 2)Italy, 3)Germany, 4)Bangladesh, 5)Japan"
      	<< endl << "Choose your country (1-5): ";//choose countries
   cin >> country;

   if ((1<=country && country<=5) && (100 <= length && length <= 1000) && (100 <= width && width <= 1000))
	input = true;
   else
	cout << "Sorry, your input is invalid" << endl << endl;
   }
   //round values for equal sizes and print header with rounded values
   RoundWidth(width);
   RoundLength(length);
   //switch statements to different countries
   //create and call to function for each contry

   switch (country)
   {
      case 1:
	Hungary(width,length);
      break;
      case 2:
	Italy(width,length);
      break;
      case 3:
	Germany(width,length);
      break;
      case 4:
	Bangladesh(width,length);
      break;
      case 5:
	Japan(width,length);
      break;
      default:
      cout << "Invalid flag selection. Please choose again." << endl;
	main();
      break;
   }

   return 0;
}
