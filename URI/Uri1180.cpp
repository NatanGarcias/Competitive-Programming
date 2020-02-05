#include<bits/stdc++.h>
using namespace std;

int main ()
{
	long long int a,k,m;
	m=1000000;
	k=-1;
	cin >> a;
	
	int x[a];
	
	for(int i=0;i<a;i++)
	{
		cin >> x[i];
		if(x[i]<=m)
		{
			m=x[i];
			k=i;
		}
	}
	
	cout << "Menor valor: " << m << endl;	
	cout << "Posicao: " << k << endl;
	
	return 0;
	
}

		