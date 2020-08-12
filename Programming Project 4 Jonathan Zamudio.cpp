//------------------------------------------------------------
// Purpose: To implement an interactive horoscope generator.  
//          The user will enter their birthdate and answer a few
//          questions, and the program will print some advice.
//
// Author:  John Gauch - Created skeleton program.
// Author:  Jonathan Zamudio - Finished implementation of program.
//------------------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

//------------------------------------------------------------
// Purpose: To prompt the user to enter their birthdate.
// Input:   None.
// Output:  The user's birth year, month, day.
//------------------------------------------------------------
void GetBirthDate(int & year, string & month, int & day)
{
   // Prompt user for birth year
   year = 0;
   while ((year < 1900) || (year > 2019))
   {
      cout << "Enter the year you were born [1900..2019]: ";
      cin >> year;
   }

   // Prompt user for birth month
   month = "";
   while (month != "Jan" && month != "Feb" && month != "Mar" && 
          month != "Apr" && month != "May" && month != "Jun" && 
          month != "Jul" && month != "Aug" && month != "Sep" && 
          month != "Oct" && month != "Nov" && month != "Dec")
   {
      cout << "Enter the month you were born [Jan..Dec]: ";
      cin >> month;
   }

   // Prompt user for birth day
   day = 0;
   while ((day < 1) || (day > 31))
   {
      cout << "Enter the day you were born [1..31]: ";
      cin >> day;
   }
}

//------------------------------------------------------------
// Purpose: To calculate the user's karma.
// Input:   None.
// Output:  The user's karma score.
//------------------------------------------------------------
int GetKarma()
{
   int answer = 0;
   cout << "How many people have you said hello to today? ";
   cin >> answer;
   
   // Silly karma calculation
   if (answer <= 0)
      return 0;
   else if (answer == 42)
      return 100;
   else 
      return (answer / 2) + (random() % 5);
}

//------------------------------------------------------------
// Purpose: Calculate the user's astrological sign.
// Input:   The user's birth month, day.
// Output:  The user's astrological sign.
//------------------------------------------------------------
string GetSign(const string month, const int day)
{
   if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20))
      return "Aries";
   if ((month == "Apr" && day >= 21) || (month == "May" && day <= 21))
      return "Taurus";
   if ((month == "May" && day >= 22) || (month == "Jun" && day <= 21))
      return "Gemini";
   if ((month == "Jun" && day >= 22) || (month == "Jul" && day <= 22))
      return "Cancer";
   if ((month == "Jul" && day >= 23) || (month == "Aug" && day <= 22))
      return "Leo";
   if ((month == "Aug" && day >= 23) || (month == "Sep" && day <= 23))
      return "Virgo";
   if ((month == "Sep" && day >= 24) || (month == "Oct" && day <= 23))
      return "Libra";
   if ((month == "Oct" && day >= 24) || (month == "Nov" && day <= 22))
      return "Scorpio";
   if ((month == "Nov" && day >= 23) || (month == "Dec" && day <= 21))
      return "Sagittarius";
   if ((month == "Dec" && day >= 22) || (month == "Jan" && day <= 20))
      return "Capricorn";
   if ((month == "Jan" && day >= 21) || (month == "Feb" && day <= 19))
      return "Aquarius";
   if ((month == "Feb" && day >= 20) || (month == "Mar" && day <= 20))
      return "Pisces";
   return "";
}

//------------------------------------------------------------
// Purpose: Romance prediction
// Input:   The user's karma score.
// Output:  Prediction message.
//------------------------------------------------------------
string Romance(const int karma)
{
   int choice = (karma * 17) % 5;
   string message = "";
   switch(choice)
   {
   case 0:
      message = "Maybe your date would like to see a romantic comedy?";
      break;
   case 1:
      message = "I think it is singles night at the local pub.";
      break;
   case 2:
      message = "You should sit by the fire and read a good romance novel.";
      break;
   case 3:
      message = "Searching online for the perfect date seldom works.";
      break;
   case 4:
      message = "Love is not in the air tonight, time to play video games.";
      break;
   default:
      message = "Romance prediction is impossible.";
      break;
   }
   return message;
}

//------------------------------------------------------------
// Purpose: Money prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
void Money(const int year, string & message)
{
   int choice = (2019 - year) / 10;
   switch(choice)
   {
   case 0:
      message = "Ask your parents for their spare change.";
      break;
   case 1:
      message = "This is a good time to your parents for a bigger allowance.";
      break;
   case 2:
      message = "You can save more money by buying less beer.";
      break;
   case 3:
      message = "Try to save a little extra for a down payment on a house.";
      break;
   case 4:
      message = "Yikes, your children's tuition bills are due soon.";
      break;
   default:
      message = "Money prediction is impossible.";
      break;
   }
}

//------------------------------------------------------------
// Purpose: Job prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
string Job(const int day, const int karma)
{
   string message = "";
   if ((day < 15) && (karma > 5))
      message = "Your boss looks generous today, time to ask for a raise.";
   else if ((day > 15) && (karma < 5))
      message = "Prepare for bad news, your company profits are down.";
   else if ((day == 15) && (karma == 5))
      message = "Bad news, your company is declaring bankruptcy.";
   else if (karma > day)
      message = "Great news, your company just went public!";
   else if (karma <= day)
      message = "It looks like a chance for some overtime.";
   else
      message = "Job prediction is impossible.";
   return message;
}

//------------------------------------------------------------
// Purpose: Family prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
// ADD FUNCTION HERE
string Family(const int day)
{
   int choice = day % 5;
   string message = "";
   switch(choice)
   {
      case 0:
	message = "Looks like there may be a new addition to the family!";
	break;
      case 1:
	message = "Maybe you should call your parents soon...";
	break;
      case 2:
	message = "Expect to hear from a distant relative soon.";
	break;
      case 3:
	message = "There will be a wedding in your life soon.";
	break;
      case 4:
	message = "A parent will give you good news this week.";
	break;
      default:
	message = "Family prediction is impossible.";
	break;
   }
   return message;
}
//------------------------------------------------------------
// Purpose: Health prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
// ADD FUNCTION HERE
string Health(const int day)
{
   string message = "";
   if(day>=5)
      message = "Maybe you should lay off the caffeine today.";
   else if(day>=10)
      message = "Yeah, that bump isn't normal, go to the doctor.";
   else if(day>=15)
      message = "Your alignment looks off, try to sit straighter today.";
   else if(day>=20)
      message = "Staring at that computer screen is taking a toll on your eyesight.";
   else if(day>=25)
      message = "The bags under your eyes are huge, try to get some more sleep.";
   else if(day>=31)
      message = "Ew, your pee is a horrid color, consider drinking more water.";
   else
      message = "Health prediction is impossible.";
   return message;
}

//------------------------------------------------------------
// Purpose: Silly prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
void Silly(string& message)
{
   int random = time(NULL) % 8;
   switch(random)
   {
      case 0:
	message = "You wouldn't have survived the snap...";
	break;
      case 1:
	message = "If sirens wail, you must heed their call.";
	break;
      case 2:
	message = "Oof, your GPA isn't looking too good...";
	break;
      case 3:
	message = "The ancient manuscripts hold the answer you seek.";
	break;
      case 4:
	message = "The three legged dog will bear a gift.";
	break;
      case 5:
	message = "Beware the clowns.";
	break;
      case 6:
	message = "There are seven dwarves waiting by the red submarine.";
	break;
      case 7:
	message = "You'll find your lost sock soon.";
	break;
      default:
	message = "Silly prediction is not silly enough...";
	break;
   }
}

//------------------------------------------------------------
// Purpose: Print user's horoscope.
// Input:   The user's birth year, month, day, karma.
// Output:  None.
//------------------------------------------------------------
void PrintHoroscope(const int year, const string month, 
   const int day, const int karma)
{
   // Print user's sign
   cout << endl << "Horoscope for " << GetSign(month, day) << endl;
   // Print romance prediction
   cout << Romance(karma) << endl;
   // Print money prediction
   string moneyMsg = "";
   Money(year, moneyMsg);
   cout << moneyMsg << endl;
   // Print job prediction
   cout << Job(day, karma) << endl;
   // Print family prediction
   cout << Family (day) << endl;
   // Print health prediction
   cout << Health(day) << endl;
   // Print silly prediction
   string sillyMsg = "";
   Silly(sillyMsg);
   cout << sillyMsg << endl;
}

//------------------------------------------------------------
// Purpose: The main program.
// Input:   None.
// Output:  None.
//------------------------------------------------------------
int main()
{
   // Initialize random number generator
   srandom(time(NULL));
   // Local variables
   int year = 0; string month = ""; int day = 0; int karma;
   // Get user's birthday
   GetBirthDate(year, month, day);
   // Get user's karma points 
   karma = GetKarma();
   // Print horoscope
   PrintHoroscope(year, month, day, karma);
}
