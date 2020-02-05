#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a,n,k=0;
	cin >> a;
	for(;;)
	{
		cin >> n;
		if(n<1)
			continue;
		for(int i=0;i<n;i++)
		{
			k=k+a+i;
		}
		break;
	}
	cout << k << endl;
	return 0;
}