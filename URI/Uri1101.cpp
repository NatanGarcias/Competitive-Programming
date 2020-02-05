#include<bits/stdc++.h>
using namespace std;

int main ()
{
	for(;;)
	{
		int b,c,z=0;
		cin >> b >> c;
		if(b<1 || c<1)
			break;
		if (c==b)
			cout << c << " " << b << "Sum=" << '0' <<endl;
		else if (c>b)
		{
			for(int i=b;i<=c;i++)
			{
				cout << i << " ";
				z+=i;
			}
		cout << "Sum=" << z << endl;
		}
		else if (b>c)
		{
			for(int i=c;i<=b;i++)
			{
				cout << i << " ";
				z+=i;
			}
		cout << "Sum=" << z << endl;
		}		
		z=0;
	}
	return 0;
}