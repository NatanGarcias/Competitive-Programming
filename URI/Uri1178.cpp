#include<bits/stdc++.h>
using namespace std;

int main ()
{
	long double a,k;
	
	cin >> a;
	
	for(int i=0;i<100;i++)
	{
		cout << fixed << setprecision(4) <<  "N[" << i << "] = " << a << endl;
		a=a/2;
	}
	return 0;
	
}

		