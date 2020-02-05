#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long long int a,b,c,d,e;
	cin >> a;
	
	for(int i=0;i<a;i++)
	{
		cin >> b >> c;

		d=0;
		e=0;
		for(;;b++)
		{
			if(b%2==1 || b%2==-1)
			{
				if(d==c)
					break;
				else
				{
					e+=b;
					d++;
				}
			}
		}
		cout << e << endl;
	}
				
	return 0;
}