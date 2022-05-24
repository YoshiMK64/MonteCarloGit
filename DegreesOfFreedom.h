#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>

//DISTANCE A PARTICLE WILL TRAVEL IN 10s 

using namespace std;
int main()
{
	srand(time(NULL));								//Using computers internal clock to control the seed and prevent repetition between runs 
	
	
	
	double sumAllR = 0;											//declaring and initialising variable to 0
	double sumAllRSqrd = 0;
	double avR = 0;
	double avRSqrd = 0;
	double avAllRSqrd = 0;
	double runs = 10000;
	double stdDev = 0;											
	double stdErr = 0;											//declaring and initialising variable to 0
	
	for (int i = 0; i < runs; i++)								//looping for 10000 runs
			{
			double allR = 0;											//declaring and initialising variable to 0
			double allRSqrd = 0;										//declaring and initialising variable to 0	
			double milliSeconds = 10000;								//declaring the amount of steps taken in 10 seconds		
			double R = 0;												//Declaring variable r distance and initalising at 0
			double X = 0.,Y = 0.;										//declaring interval step distance to 1 metre per millisecond
			int deegreesOfFreedom = 1000;								//initialising the designated degrees of freedom
	
	
	
	
				for (int i = 0; i < milliSeconds; i++) 								//looping for 10000 milliseconds (10 seconds)
					{
						double r = 1;
						int z = 2*(deegreesOfFreedom);								//calculating complete degrees of freedom for 360 degrees
						double theta = (((2*M_PI)/z)*((rand() % z) + 1));			//initialising randomly generated theta (representing the degreses of freedom) from 0 to 360 degrees
						Y += r*sin(theta), X += r*cos(theta);						//declaring and initialising 2d x and y components using trigonometric identities													
						R = sqrt((X*X)+(Y*Y));
				
					}
				
			allR += fabs(R);															//total displacement	
			sumAllRSqrd += allR*allR;													//sum of dispacement squared	
			
	}
			

		
		avR = allR/runs;										//Total sum divided by runs for average					
		avRSqrd = avR*avR;										//Average squared
		avAllRSqrd = sumAllRSqrd/runs;							//sum of all R squared divide by runs for average
		
		stdDev = sqrt((double)avAllRSqrd - (avRSqrd));			//calculating std deviation
		stdErr = stdDev / sqrt(runs);							//calculating std err
		
		cout << "Distance particle travels in 10s  with 1000 degrees of freedom = " << avR << "m +- " << stdDev << " stdDev << " <<  ", " << stdErr << " stdErr" << endl; 	//outputting a result
		
		return 0;
}