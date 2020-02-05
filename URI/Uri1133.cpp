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
	for(int i=a+1;i<b;i++)
		if(i%5==2 || i%5==3)
			cout << i << endl;
	return 0;
}