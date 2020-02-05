#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a,k;
	k=0;
	cin >> a;
	
	for(int i=0;i<1000;i++)
	{
		cout << "N[" << i << "] = " << k << endl;
		k++;
		if(k==a)
			k=0;
	}
	return 0;
	
}

		