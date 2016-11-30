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
	double x = genRand(-0.5, 0.5);
	double y = genRand(-0.5, 0.5);

    double theta = pi/2*(genRand(0,1));
    // double theta = acos(genRand(0,1));
    double phi = 2*pi*genRand(0,1);
 
 	// center of S: (1,1,5) radius: 1
 	// random point x: (x,y,0) 
 	// direction: (sin(theta)*cos(phi), sin(theta)*sin(phi), cos(theta))
 
    // distance from center of S to the ray
    double x0 = 1; double y0 = 1; double z0 = 5;
    double x1 = x; double y1 = y; double z1 = 0;
    double x2_x1 = sin(theta)*cos(phi);
    double y2_y1 = sin(theta)*sin(phi);
    double z2_z1 = cos(theta);

    double x2 = x1 + x2_x1; 
    double y2 = y1 + y2_y1;
    double z2 = z1 + z2_z1;

    double x0_x1 = x0-x1;
    double y0_y1 = y0-y1;
    double z0_z1 = z0-z1;

    double x0_x2 = x0-x2;
    double y0_y2 = y0-y2;
    double z0_z2 = z0-z2;

    double A = sqrt(pow(y0_y1*z0_z2-y0_y2*z0_z1,2) + pow(x0_x2*z0_z1-x0_x1*z0_z2,2) + pow(x0_x1*y0_y2-x0_x2*y0_y1,2));
    double B = sqrt(pow(x2_x1,2) + pow(y2_y1,2) + pow(z2_z1,2));

    double distance = A / B;

    double I;
    if (distance > 1)
    	I = 0;
	else
    	I = 100* 1* pow(pi,2)* cos(theta) *sin(theta);
    	// I = 100* 1* 2*pi* cos(theta);
    
    return I;
}

int main()
{
	int N = 1000000;
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
