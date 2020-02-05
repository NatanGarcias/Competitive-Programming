#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long long int a,b,z,y;
	double c,d;
	int e,f=0;
	cin >> e;
	for(int i=0;i<e;i++)
	{
		cin >> a >> b >> c >> d;
		f=0;
		for(;;)
		{
			z=a+((a*c)/100);
			y=b+((b*d)/100);
			f++;
			if(f>100)
			{
				cout << "Mais de 1 seculo." << endl;
				break;
			}
			if(z>y)
			{
				cout << f << " anos." << endl;
				break;
			}
			a=z;
			b=y;
		}
	}
	return 0;
}