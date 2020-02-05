#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int x[20];
		
	for(int i=0;i<20;i++)
	{
		cin >> x[i];
	}
	
	for(int i=0,j=19;i<10;i++,j--)
	{
		int k;
		k = x[i];
		x[i] = x[j];
		x[j] = k;
	}
	
	for(int i=0;i<20;i++)
			cout << "N[" << i << "] = " << x[i] << endl;

	return 0;
	
}

		