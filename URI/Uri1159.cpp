#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long long int a,b,c,d,e;
	
	for(;;)
	{
		cin >> b;
		if(b==0)
			break;

		d=0;
		e=0;
		for(;;b++)
		{
			if(b%2==0)
			{
				if(d==5)
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