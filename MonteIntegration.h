#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>

//rejection method

using namespace std;									//intitialising standard namespace

int main()												//intitialising main method
{
		srand(time(NULL));								//intitialising seed		
		
		int Runs = 10000;								//points to be counted
		double Integral;								//declaring variables for calculation
		int hitsIn = 0;									//hit count
		double bigX = (2*M_PI);							//upper limit of neg int
		double minX = 0;								//lower limit of pos int
		double lilX = M_PI;								//midpoint of integration 
		double maxY = sin(0.0000000001)/0.0000000001;	// max y value for pos int (approx 1)	
		double minY = sin(3*M_PI/2)/(3*M_PI/2);								// min y value for neg int
		
		double x1, y1, x2, y2;							//declaring variable for calculations
		
		for (int i = 0; i < Runs; i++)					//looping for amount of points to count
		{
			x1 = lilX * double(rand())/RAND_MAX;		//initialising random points
			y1 = maxY * double (rand())/RAND_MAX;
			x2 = bigX*double(rand())/RAND_MAX;
			y2 = minY*double(rand())/RAND_MAX;
			
			if (y1 <= ((sin(x1))/x1) && (y1 >= 0)){		//setting bounds for positive integration 	
				hitsIn++;								//counting as positive sum
				}
				
				else if ((y2 <= 0) && (y2 >= (sin(x2))/x2)){	//setting bounds for negative integration
					hitsIn--;									//counting as negative sum
				}
				Integral =((bigX-minX)/2) *(double)hitsIn; //both intervals of x * y (hitsIn)
		
		}
		
		cout << "Integral of sin(theta)/theta d(theta) = " << Integral/Runs << endl; 				//outputting result of simulation
}