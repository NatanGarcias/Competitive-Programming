#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double b,d=0;
	int c=0;
	for(;;)
	{
		
		cin >> b;
		if(b>=0 && b<=10)
		{
			d+=b;
			c++;
			if(c==2)
			{
				cout << "media = " << fixed << setprecision(2) << d/2 << endl;
				break;
			}
		}
		else
			cout << "nota invalida" << endl;
		
	}
	return 0;
}