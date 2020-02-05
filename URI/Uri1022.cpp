#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a,n1,n2,d1,d2,b,c,d,e;
	char k, sinal, j;
	bool z=true;
	cin >> a;
	for(int i=0;i<a;i++)
	{
		cin >> n1 >> k >> d1 >> sinal >> n2 >> j >> d2;
		if(sinal =='+')
		{
			b= d1*d2;
			e = (n1*d2+n2*d1);
			cout << e << k << b << " = ";
			for(int l=b;l>1;l--)
				if(e%l==0 && b%l==0)
				{
					cout << e/l << k << b/l << endl;
					z=false;
					break;
				}
            if(z)
				cout << e << k << b << endl;
		}
		else if(sinal =='-')
		{
			b= d1*d2;
			e=(n1*d2-n2*d1);
			cout << e << k << b << " = ";
			for(int l=b;l>1;l--)
				if(e%l==0 && b%l==0)
				{
					cout << e/l << k << b/l << endl;
					z=false;
					break;
				}
			if(z)
				cout << e << k << b << endl;
		}
		else if(sinal =='/')
		{
			b= d1*n2;
			c= n1*d2;
			cout << c << k << b << " = ";
			for(int l=b;l>1;l--)
				if(c%l==0 && b%l==0)
				{
					cout << c/l << k << b/l << endl;
					z=false;
					break;
				}
			if(z)
				cout << c << k << b << endl;
		}
		else if(sinal =='*')
		{
			b= n1*n2;
			c= d1*d2;
			cout << b << k << c << " = ";
			for(int l=b;l>1;l--)
				if(b%l==0 && c%l==0)
				{
					cout << b/l << k << c/l << endl;
					z=false;
					break;
				}
			if(z)
				cout << b << k << c << endl;
		}
		z=true;
	}
	return 0;
}