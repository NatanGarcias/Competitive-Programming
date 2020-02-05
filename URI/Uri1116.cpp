#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a;
	cin >> a;
	for(int i=0;i<a;i++)
	{
		double b,c;
		cin >> b >> c;
		if(c==0)
			cout << "divisao impossivel" << endl;
		else
			cout << fixed << setprecision(1) << b/c << endl;
		
	}
	return 0;
}