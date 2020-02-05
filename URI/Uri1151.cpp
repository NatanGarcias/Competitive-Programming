#include<bits/stdc++.h>
using namespace std;

void fibo(int a)
{
	int b=0,c=1,d;
	
	for(int i=1;i<a-1;i++)
	{
		if(i==a-2)
			cout << b+c << endl;
		else
		{
			d=b+c;
			b=c;
			c=d;
			cout << d << " ";
		}
	}
}

int main ()
{
	int a;
	cin >> a;
	
	cout << "0 1 ";
	
	fibo(a);
	
	return 0;
}