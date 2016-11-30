#include <iostream>
#include <random>
#include <cmath>
#include <omp.h>
#define pi 3.1415926535897932

double genRand(double a, double b)
{
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(a, b);
    return dis(gen);
}

double funcI()
{

	double theta, phi, I;
	switch (3)
	{

		case 1:
			// method 1:
    		theta = pi/2*genRand(0,1);
    		phi = 2*pi*genRand(0,1);
    		I = pow(pi,2)*pow(cos(theta)*sin(theta)*cos(phi),2)*sin(theta);
    		break;

		case 2:
    		// method 2:
			theta = pi/2*genRand(0,1);
    		// theta = acos(genRand(0,1));
    		// phi = 2*pi*genRand(0,1);
    		phi = 4*acos(genRand(0,1));
    		I = 2*pi*pow(cos(theta)*sin(theta)*cos(phi),2);
    		break;

    	case 3:
    		// method 3:
    		theta = asin(genRand(0,1));
    		phi = 2*pi*genRand(0,1);
    		I = 2*pi*pow(cos(theta)*sin(theta)*cos(phi),2);
    		break;
	}
    
    return I;
}

int main()
{
	long int N = 1000000;
	double I[1000000];
	double tot = 0.0;
	for (int i = 0; i < N; i++)
	{
		I[i] = funcI();
		tot = tot + I[i];
	}
	double meanI = tot/N;

	double sumDifI = 0.0;
	for (int i = 0; i < N; i++)
	{	
		double difI = pow((I[i] - meanI), 2);
		sumDifI = sumDifI + difI;
	}
	double s = 2*sqrt(sumDifI/(N-1)) / sqrt(N);

	std::cout << "Mean: " << meanI << std::endl;
	std::cout << "std: " << s << std::endl;
	
	return 0;
}
