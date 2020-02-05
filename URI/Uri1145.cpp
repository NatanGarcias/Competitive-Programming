#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a,b;
	cin >> a >> b;
	for(int i=1;i<=b;)
		for(int j=1;j<=a;j++,i++)
		{
			if (j==a)
				cout << i << endl;
			else
				cout << i << " ";
		}
	return 0;
}