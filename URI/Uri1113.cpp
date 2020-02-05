#include<bits/stdc++.h>
using namespace std;

int main ()
{
	for(;;)
	{
		int b,c,z=0;
		cin >> b >> c;
		if(b==c)
			break;
		else if (c>b)
			cout << "Crescente" << endl;
		else if (b>c)
			cout << "Decrescente" << endl;
	}
	return 0;
}