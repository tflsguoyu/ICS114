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
    double x1 = pi/2*genRand(0,1);
    double x2 = 2*pi*genRand(0,1);
    double I = pow(pi,2)*sin(x1);
	
	// double x1 = genRand(0,1);
 //    double x2 = genRand(0,1);
 //    double theta = asin(x1);
 //    double phi = 2*pi*x2;
 //    double I = 2*pi*sin(theta);


    return I;
}

int main()
{
	long int N = 100000;
	double I[100000];
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
