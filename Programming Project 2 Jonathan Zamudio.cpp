//--------------------------------------------------------------
//              Author: Jonathan Zamudio
//              Title:  John's Restaurant
//              This program will create a custom menu for the
//              customer based on their preferences. This will
//              be done with the use of if statements.
//--------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   //declare variables
   int meat, veg, pasta, potato, choc, fruit;
   float budget, cost, totalCost, tax;
   string mainCourse = "Must pay at least $10";
   string app = "Must pay at least $15";
   string dessert = "Must pay at least $20";

	//adds blank lines so the program starts at the bottom of the page, looking neater.
	cout << string(50,'\n');

   //welcome the user
   cout << "Welcome to John's Restaurant!\n\n" << "We will generate a menu for you "
	<< "based on your preferences.\n" << "Just answer the following questions!\n\n";

   //prompt user for preferences
   cout << endl << "How much do you like meat on a scale of 1..100?\t\t";
   cin >> meat;
   cout << endl << "How much do you like vegetables on a scale of 1..100?\t";
   cin >> veg;
   cout << endl << "How much do you like pasta on a scale of 1..100?\t";
   cin >> pasta;
   cout << endl << "How much do you like potatoes on a scale of 1..100?\t";
   cin >> potato;
   cout << endl << "How much do you like chocolate on a scale of 1..100?\t";
   cin >> choc;
   cout << endl << "How much do you like fruit on a scale of 1..100?\t";
   cin >> fruit;
   cout << endl << "What is your budget (before tax) for this meal?\t\t";
   cin >> budget;

   //check if user has >$10 for main, >$15 app, >$20 dessert and
   //compare values for their custom menu
   //if budget is less than $10, doesn't give user a menu
   if (budget < 10)
   {
      cout << "Sorry sir/ma'am, we can't feed you for that amount.\n";
      return 0;
   }

   //checks if user can get just the main course
   else if (10 <= budget)
   {
	cost = 10.00;
	if (meat < 10 && veg < 10)
	   mainCourse = "Cheese omelet";
	else if (meat >=  veg)//will take meat over vegetables if its a tie
	{
	   if (pasta >= potato)//goes to pasta in case of tie
	      mainCourse = "Spaghetti & meat sauce";
	   else if (potato > pasta)
	      mainCourse = "Steak & baked potato";
	}
	else if (veg > meat)
	   mainCourse = "Pasta primavera";

	//checks if user can get appetizer
	if (15 <=  budget)
	   cost = 15.00;
	   if (meat < 10 && veg < 10)
	      app = "Garlic bread";
	   else if (meat >=  veg)
	      app = "Chicken wings";
	   else if (veg > meat)
	      app = "Garden salad";

	//checks if user can get dessert
	if (20 <=  budget)
	   cost = 20.00;
	   if(choc < 10 && fruit < 10)
	      dessert = "Vanilla ice cream";
	   else if (choc >= fruit)
	      dessert = "Chocolate cake";
	   else if (fruit > choc)
	      dessert = "Apple pie";
   }

   //print out the menu. If not enough money, prints "n/a"
   cout << endl <<  "Your custom menu is...\n\tAppetizer:\t" << app << endl
	<< "\tMain course:\t" <<  mainCourse << endl << "\tDessert:\t"
	<< dessert << endl;

   //calculate cost with taxes
   tax = cost * .07;
   totalCost = cost + tax;
   cout.precision(2);//make amounts come to tenths place
   cout << endl <<  "Your bill is...\n\tMeal:\t$" << fixed << cost << endl << "\tTax:\t$"
        << fixed <<  tax << endl << "\tTotal:\t$" << fixed << totalCost << endl;

   return 0;
}
