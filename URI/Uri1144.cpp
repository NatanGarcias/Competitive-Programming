#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a,j=0;
	cin >> a;
	for(int i=1;i<=a;i++)
	{
		cout << i << " ";
		cout << i*i << " ";
		cout << i*i*i;
		cout << endl;
		
		cout << i << " ";
		cout << i*i+1 << " ";
		cout << i*i*i+1;
		cout << endl;
	}
	
	return 0;
}