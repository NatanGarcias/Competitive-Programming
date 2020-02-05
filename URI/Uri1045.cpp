#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	double a,b,c,maior;
	
	cin >> a >> b >> c ;
	
	maior = a>=b?a:b;
	if ( b>a)
	{
		b = a;
	    a = maior;
	}
	maior = a>=c?a:c;
	if (c>a)
	{
		c = a;
		a = maior;
	}
	maior = b>=c?b:c;
	if (c>b)
	{
		c = b;
		b = maior;
	}
	if (a>=b+c)
		cout << "NAO FORMA TRIANGULO" << endl;
	else
	{
		if (a*a == b*b+c*c)
		    cout << "TRIANGULO RETANGULO" << endl;
	    if (a*a > b*b+c*c)
		    cout << "TRIANGULO OBTUSANGULO" << endl;
	    if (a*a < b*b+c*c)
		    cout << "TRIANGULO ACUTANGULO" << endl;
	    if (a == b && a == c)
		    cout << "TRIANGULO EQUILATERO" << endl;
	    else if ( a==b || a==c || b==c)
		    cout << "TRIANGULO ISOSCELES" << endl;
	}
	return 0;	
}
	