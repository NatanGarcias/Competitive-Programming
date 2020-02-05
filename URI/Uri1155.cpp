#include<bits/stdc++.h>
using namespace std;

double s (double a)
{
	double d=0;
	
	for(double i=1.0;i<=a;i++)
		d+= 1/i;
	return d;
}

int main ()
{
	double a;
	a= 100.0;
	
	cout << fixed << setprecision(2) << s(a)<< endl;
	
	return 0;
}
