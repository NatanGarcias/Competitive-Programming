#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double a,b,c,d,e,f;
	bool oi;
	for(;;)
	{
		oi = false;
		cin >> a;
		if(a==0)
			return 0;
		cin >> b >> c;
		
		d = a*b;
		e = c/100;
		for(int i=0;;i++)
		{
			double j=i*i*1.0;
			if(j*e > d)
			{	
				cout << i-1 << endl;
				oi = true;
			}
			if(oi)
				break;
		}
	}
	
	return 0;
}