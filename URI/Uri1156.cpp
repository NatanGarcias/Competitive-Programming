#include<bits/stdc++.h>
using namespace std;

double s (double a)
{
	double d=0,b=1;
	
	for(;;)
	{
		if(a==39)
			break;
		d+= a/b;
		a+=2;
		b*=2;
		
	}
	return d;
}

int main ()
{
	double a;
	a=1;
	
	cout << fixed << setprecision(2) << s(a)<< endl;
	
	return 0;
}
