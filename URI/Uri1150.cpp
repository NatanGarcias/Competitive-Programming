#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int x,z,i=0,k=0;
	
	cin >> x;
	
	for(int j=0;j<x;j++)
	{
		cin >> z;
		if(x>=z)
			continue;
		for(int m=0;m<z;m++)
		{
			i++;
			k=x+m+k;
			if(k>z)
				break;
		}
		break;
	}
	cout << i << endl;
	
	return 0;
}