#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int g=0,j=0;
	int x[15],y[5],k[5];
	
	for(int i=0;i<15;i++)
	{
		cin >> x[i];
		if(x[i]%2==0)
		{
			y[j]=x[i];
			j++;
		}
		if (x[i]%2==1 || x[i]%2==-1)
		{
			k[g]=x[i];
			g++;
		}
		if(j==5)
		{
			for(int l=0;l<5;l++)
			{
				cout << "par[" << l << "] = " << y[l] << endl;
				j=0;
			}
		}
		if(g==5)
		{
			for(int l=0;l<5;l++)
			{
				cout << "impar[" << l << "] = " << k[l] << endl;
				g=0;
			}
		}
	}
	if(g!=0)
	{
		for(int l=0;l<g;l++)	
			cout << "impar[" << l << "] = " << k[l] << endl;
	}
	if(j!=0)
	{
		for(int l=0;l<j;l++)
			cout << "par[" << l << "] = " << y[l] << endl;
	}
	
	return 0;
	
}

		