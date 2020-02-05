#include<bits/stdc++.h>
using namespace std;

int main() 
{ 
    long long int a,b,k=0;
	
	cin >> a;
	for(int j=0;j<a;j++)
	{	
		cin >> b;
		k=0;
		for(int i=2;i<b;i++)
		{
			if(b%i==0)
			{
				k++;
				break;
			}
		}
		if(k>0)
			cout << b << " nao eh primo" << endl;
		else
			cout << b << " eh primo" << endl;
	}
	return 0;	
}