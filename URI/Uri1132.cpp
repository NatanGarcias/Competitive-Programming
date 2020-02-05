#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a,b,c=0,d;
	cin >> a >> b;
	if(a>b)
	{
		d=a;
		a=b;
		b=d;
	}
	for(int i=a;i<=b;i++)
		if(i%13!=0)
			c+=i;
	cout << c << endl;
	return 0;
}