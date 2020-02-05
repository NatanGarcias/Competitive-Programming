#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a,b,c,z=0;
	cin >> a;
	for(int i=0;i<a;i++)
	{
		cin >> b >> c;
		if (c==b)
			cout << "0" << endl;
		else if (c>b)
		{
			for(int k=b+1;k<c;k++)
				if(k%2==1)
					z+=k;
		cout << z << endl;
		}
		else if (b>c)
		{
			for(int k=c+1;k<b;k++)
				if(k%2==1)
					z+=k;
		cout << z << endl;
		}		
		
		z=0;
	}
	return 0;
}