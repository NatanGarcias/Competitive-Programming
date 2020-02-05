#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int x[10];
	int a;
	
	cin >> a;
	
	for(int i=0;i<10;i++)
	{
		x[i]= a;
		a=a*2;
	}
	for(int i=0;i<10;i++)
		cout << "N[" << i << "] = " << x[i] << endl;

	return 0;
	
}

		