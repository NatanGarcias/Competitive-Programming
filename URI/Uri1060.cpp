#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	int cont=0;
	double a;
	for( int i=1;i<=6;i++)
	{
		cin >> a;
		if (a>0)
			cont++;
	}
	cout << cont << " valores positivos" << endl;
	
	return 0;	
}
	