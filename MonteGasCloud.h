#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>

using namespace std;
int main()
{
  srand(time(NULL));
  
  //==============================================================================================
    
	double 	sphR = 10;										//m
	double 	sphP = 1.01E6;									//p
	double 	sphV = (4/3)*M_PI*(sphR*sphR*sphR); 			//Volume of gas sphere
	double 	gasConst = 8.314462; 							//R = Gas constant
	double 	hydTemp = 300; 									//K
	double	NA=6.022E23;									//Avogadro's number
	double 	N1 =NA*((sphP*sphV)/(gasConst*hydTemp));		//numberof molecules PV*3/2*(2/mv^2)
	double	n1 = (sphP*sphV)/(gasConst*hydTemp);			//particles per mol
	double 	N2 = N1/sphV;									//particles per unit volume
	
	cout << endl;
	cout << "Particles per unit volume (Hydrogen) = " << N2 << endl;
	cout << endl;
 // =============================================================================================
 
  double currentEnergy = 2;									//Energy of neutron leaving source
  double lowBoundEnergy = 1E-7; 							//lower sigma boundary energy
  double elSig = 20E-28; 									//20 barns  elastic cross section
  double abSig = 0.2e-28; 									//0.2 barns
  double UpSig = 0;											//declaring updating sigma variable
  double n = N2; 											//number of hydrogen particles per unit volume
  double stepSize = 0; 										//mean free path 
  double energyTransf = 0;									//declaring particle energy loss variable
  double dead = 0;											//declaring variable for absorbed counter
  double absTot = 0;										//Counter for total absorbed particles 
  double scatTot = 0;										//declaring counter for total scattered particles
  double sumEnergy = 0;										//declaring variable for total energy counter
  double avgEnergy = 0;										//declaring variable for average energy calculation
  double neutrons = 10000;									//declaring and initialising amount of neutrons to test					
  double UpX = 0;											//declaring x component update variable
  double UpY = 0;											//declaring y component update variable
  double UpZ = 0; 											//declaring z component update variable
  double UpR = 0;											//declaring radius from origin variable component
//========================================================================================================

  for (int i = 0; i < neutrons; i++)						//initialising how many particles to test				
      { 

	currentEnergy = 2;										//re-initialising variables inside for loop
	dead = 0;
	UpSig = 0;
	energyTransf = 0;
	stepSize = 0;
	UpX = 0;
	UpY = 0;
	UpZ = 0; 
	UpR = 0;

		while ((UpR < sphR) && (currentEnergy > 0))								//Creating a while loop: while neutron inside sphere with non zero energy
		{
			energyTransf = currentEnergy * (double(rand())/RAND_MAX);			//Determining amount of energy lost in collision (between 0-Qmax but true max is it's own current energy)
			currentEnergy -= energyTransf;										//subtracting determined energy transfer from the current energy each loop particle alive but in sphere 
     
					if (currentEnergy < lowBoundEnergy)							//Determining behaviour if particle fits these conditions
					{
						UpSig = elSig * sqrt(lowBoundEnergy/currentEnergy);		//Update cross section to elasticCross*(lower energy bound divide by current Energy))
						
			//=======================================================		Nested if
							if (currentEnergy < (abSig/elSig))					//if current energy is below the 1/v and also less than absorption/elastic cross section 
							{
							dead++;												//if condition satisfy kill the particle
							}
			//=======================================================		End Nested if
					}
					else														//Else statement to larger if cond			
					{
						UpSig = elSig;											//if current energy > low bound, cross section remains 20 barns
					}
        
			if (dead <= 0)													//once above statements are checked new if, checking if particle is alive
			{																//if alive follow this procedure	
			stepSize = 1 / (UpSig * n);										//calculate mean free path = distance travelled between steps
			double theta = ((2*M_PI)*(double(rand())/ RAND_MAX));			// generate random theta
			double psi = ((2*M_PI)*(double(rand()) / RAND_MAX));			//generate random psi
			UpY += stepSize*sin(theta)*sin(psi);							//Updating X position
			UpX += stepSize*sin(theta)*cos(psi);							//updating y position
			UpZ += stepSize*cos(theta);										//updating z position
			UpR = sqrt((UpX*UpX)+(UpY*UpY)+(UpZ*UpZ));						//calculating displacement from source to update while loop
			}
																			//if neutron still inside hydrogen sphere and energy>0, repeat loop
		}																	//end of while loop

							if (dead <= 0)									//if condition while loop completed and particle alive		
								{
								scatTot++;									//count as scattered
								sumEnergy += currentEnergy;					//tally energy as sum with all escaped particles
								}
																		
												
								absTot = neutrons-scatTot;					//calculate absorbed
								

   }
//==========================================================================
	avgEnergy = sumEnergy / scatTot;										//divide energy sum by amount of energies summed
//===========================================================================
 cout << "Absorbed Neutrons = " << absTot << endl;									//ouput absorbed count
 cout << "Exit Neutrons = " << scatTot << endl;									//output scattered count
 cout << "Ratio of exiting neutrons to absorbed = " << scatTot/absTot << endl;		//output ratio or both
 cout << "Energy of exiting Neutron (Mean) " << avgEnergy << " Mev" << endl;	//output average energy of escaped particle
//============================================================================  
  
  return 0;
}
