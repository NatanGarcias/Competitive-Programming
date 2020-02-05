#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int b,c=0,d=0,e=0;
	for(;;)
	{
		cin >> b;
		if (b!=1 && b!=2 && b!=3 && b!=4)
			continue;
		if(b==4)
			break;
		if(b==1)
			c++;
		if(b==2)
			d++;
		if(b==3)
			e++;
	}
	cout << "MUITO OBRIGADO" << endl;
	cout << "Alcool: " << c << endl;
	cout << "Gasolina: " << d << endl;
	cout << "Diesel: " << e << endl;
	return 0;
}