#include<bits/stdc++.h>
using namespace std;

bool k[61] = {0};
long long int g[61] = {0};

long long int fibo(long long int a)
{
	if(k[a])
		return g[a];
	if(a==0)
		return 0;
	if(a==1)
		return 1;
	else
	{
		g[a] = fibo(a-1)+fibo(a-2);
		k[a] = true;	
		return g[a];
	}	
}
int main ()
{
	long long int a;
	
	cin >> a;
	
	long long int x[a];
	for(int i=0;i<a;i++)
	{
		cin >> x[i];
		cout << "Fib(" << x[i] << ") = " << fibo(x[i]) << endl;
	}
	return 0;
	
}

		