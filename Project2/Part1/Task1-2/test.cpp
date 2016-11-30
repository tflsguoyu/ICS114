#include <iostream>
#include <random>
#include <cmath>
#include <omp.h>

double funcI()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    double sigma = dis(gen);
    double lambda = 10;
    double x = 1 - log(sigma)/lambda;
    double I = exp(-0.5*pow(x,2)) / (lambda*exp(-lambda*(x-1)));
    
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
