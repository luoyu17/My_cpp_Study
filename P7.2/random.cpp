#include <iostream>
#include <cstdlib>
#include <ctime>
#include "random.h"

using namespace std;

void Randomize(){
	srand( (int)time(NULL) );
}

int GenerateRandomNum(int low,int high){
	double d;
	if (low > high)
	{
		cout<<"Please make sure low <= high.\n";
		exit(1);
	}
	d = (double)rand() / ( (double)RAND_MAX+1.0);

	return (low + (int)(d*(high-low+1)));
}

double GenerateRandomRea(double low,double high){
	double d;
	if (low > high)
	{
		cout<<"Please make sure low <= high.\n";
		exit(2);
	}
	
	d = (double)rand() / (double)RAND_MAX;

	return ( low + d*(high-low) );
}