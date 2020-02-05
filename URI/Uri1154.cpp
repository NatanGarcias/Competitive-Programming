#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double a,b=0,c,d=0.0;
	
	for(;;)
	{
		cin >> a;
		if(a<0)
			break;
		b+=a;
		d=d+1;
	}
	c= b/d;
	cout << fixed << setprecision(2) << c << endl;
	
	return 0;
}
