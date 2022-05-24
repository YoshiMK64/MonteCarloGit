#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;									//intitialising standard namespace
int main()												//initialising main method	
{
	srand(time(NULL));									//Using computers internal clock to control the seed and prevent repetition between runs 
	
	double AvX = 0;										//declaring and initialising variables at 0
	double AvXSqrd = 0;
	double sumAllX = 0;
	double avAllXSqrd = 0;
	double sumAllXSqrd = 0;
	int i;
	double stdDev = 0;
	double stdErr = 0;
	double runs = 10000;								//declaring and initialisng run amount
	
	

	
	
	for (int i = 0; i < runs; i++)						//looping for 10000 runs
	{
			double currentDist = 0;						//initialising variables inside for loop
			double intDistance = 1;						//initialising step distance to 1 metre per millisecond
			double milliSeconds = 10000;
			double allX = 0;
			double allXSqrd = 0;
			
			
		for (int i = 0; i < milliSeconds; i++)			//looping for 10000 milliseconds (10 seconds)
		{
				
				double direction;									//declaring random variable
				if (double(rand())/RAND_MAX <= 0.9090909091 )		//initialising 10/11 probability in if loop
					{
					direction = 1; 									//   10/11 chance going right 
					}
				else 
					{
				direction = -1; 									//   1/11 chance of going left 
					}
				 
			currentDist = direction*intDistance;		//multiplying random variable by step/interval distance 
			allX += currentDist;						//summing current distance for total distance travelled

		}
		
		allXSqrd = allX*allX;							//sum of current distance for total distance travelled
		sumAllX += fabs(allX);							//sum of all absolute value for X to determine mean displacement 
		sumAllXSqrd += allXSqrd;						//Summing allXSqrd over all runs	
		
	}
	
		cout << sumAllX << " = Sum of Displacement over 10 000 runs" << endl; 			//testing total sum of displacement for 10000 runs
		
		AvX = sumAllX/double (runs);													//Determining average displacement for 10000 runs
		
		AvXSqrd = AvX*AvX; 																//Average displlacement squared										
		
		avAllXSqrd = sumAllXSqrd/double (runs);											//Average of sum of all x squared over 10000 runs
		
		stdDev = sqrt(avAllXSqrd - (AvXSqrd));											//Standard deviation calculation
		
		stdErr = stdDev / sqrt(double(runs));											//Standard error calculation
		
		cout << "Distance particle travels in 10s at 1 metre per millisecond = " << AvX << "+- " << stdDev << ", " << stdErr << endl;     //Output result
		
		return 0;
}

				