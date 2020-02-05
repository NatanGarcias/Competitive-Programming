#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double b,d=0,e,g;
	int c=0;
	bool k=true;
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
				cout << "novo calculo (1-sim 2-nao)" << endl;
				cin >> e;
				if(e==2)
					break;
				else if (e!=2 && e!=1)
					while (k)
					{
						cout << "novo calculo (1-sim 2-nao)" << endl;
						cin >> e;
						if(e==2)
							break;
						if(e==1)
							break;
					}	
				if(e==2)
					break;
				c=0;
				d=0;
			}
		}
		else
			cout << "nota invalida" << endl;
		
	}
	return 0;
}