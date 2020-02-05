#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a;
	for(;;)
	{
		cin >> a;
		if(a==0)
			break;
		for(int i=1;i<=a;i++)
		{
			if (i==a)
				cout << i << endl;
			else
				cout << i << " ";
		}
	}
	return 0;
}