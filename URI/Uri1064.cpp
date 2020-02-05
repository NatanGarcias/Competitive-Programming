#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	double a,cont=0,media=0;
	
	for (int i=1;i<=6;i++)
	{
		cin >> a;
		if(a>0)
		{	cont++;
		    media += a;
		}
	}
	cout << cont << " valores positivos" << endl;
	cout << fixed << setprecision(1) << media/cont << endl; 
    
	return 0;	
}
	