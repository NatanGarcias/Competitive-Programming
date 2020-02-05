#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a,cont=0,cont2=0,cont3=0,cont4=0;
	
	for (int i=1;i<=5;i++)
	{
		cin >> a;
		if(a%2==0)
			cont++;
		else
			cont2++;
		if (a>0)
			cont3++;
		else if (a<0)
			cont4++;
	}
	cout << cont << " valor(es) par(es)" << endl;
	cout << cont2 << " valor(es) impar(es)" << endl;
	cout << cont3 << " valor(es) positivo(s)" << endl;
	cout << cont4 << " valor(es) negativo(s)" << endl;
	
	return 0;	
}
	