#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>

//evaluation method

using namespace std;									//intitialising standard namespace

int main()												//initialising main method
{
		srand(time(NULL));								//Using computers internal clock to control the seed and prevent repetition between runs 
		
		int totalRuns = 1000;							//declaring and initialising number of runs for simulation
		
		double minX = 0.;								//declaring and initialising minimum X value (lower bound of integration) 
		double maxX = 2*(M_PI);							//declaring and initialising maximum X value (upper bound of integration)
		double sumOfY = 0.;								//initialising sumofY at 0.
		
		double x, y;									//declaring variables for for loop
		
		for (int i = 0; i < totalRuns; i++)				//looping for runs
		{ 
			x = minX + (maxX-minX) * double(rand())/RAND_MAX;	//intialising variable from min to max value with point counter rand 
			y = sin(x)/x;										//initialising function to be summed
		
			sumOfY += y;										//summing function
		}
		cout << "int of Sin(theta)/theta d(theta) = " << (maxX - minX)* double(sumOfY)/totalRuns << endl; 	//outputting results of sum over our interval averaged over runs 
}