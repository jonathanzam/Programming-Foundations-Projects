//--------------------------------------------------------------
//		Author: Jonathan Zamudio
//		Title:	Programing Project 1
//		This program will prompt the user for the size
//		of rebar and how much rebar will be in a bundle.
//		The program will then calculate how many bundles
//		will fit on the truck given a weight maximum.
//--------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
//declare variables
float rebarDia, rebarRadius, rebarLen, bundleAmnt, weightLimit, rebarWeight, rebarVol = 0.0;
int rebarBundles;//will only give the smallest whole number of bundles the truck can carry
const float steelDensity = 0.29;//approximately 0.29 lbs/cu in

//prompt user for values & store values.
cout << "Enter diameter of rebar(inches): \n";
cin >> rebarDia;
rebarRadius = rebarDia/2;
cout << "Enter length of rebar(feet): \n";
cin >> rebarLen;
rebarLen = rebarLen*12;//convert feet into inches
cout << "Enter amount of rebar pieces per bundle: \n";
cin >> bundleAmnt;
cout << "Enter the maximum weight limit of the truck(pounds): \n";
cin >> weightLimit;

//calculate the volume of the rebar
rebarVol = M_PI * (rebarRadius * rebarRadius) * rebarLen;
cout << "Volume is " << rebarVol << endl;

//calculate weight of the rebar in pounds
rebarWeight = rebarVol * steelDensity;
cout << "The weight of the rebar is: " << rebarWeight << " pounds.\n";

//calculate the amount of bundles the truck can carry and print the result
rebarBundles = weightLimit / (bundleAmnt * rebarWeight);
cout << "The truck can carry " << rebarBundles << " rebar bundles.\n";

return 0;
}
