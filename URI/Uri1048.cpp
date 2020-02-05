#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	double a;
	
	cin >> a;
	
	if ( a>=0 && a<=400.00)
	{
		cout << fixed << setprecision(2) << "Novo salario: " << a*(15/100.0)+a << endl;
	    cout << "Reajuste ganho: " << a*(15/100.0) << endl;
        cout << "Em percentual: " << "15 %" << endl;
	}	
	else if ( a>=400.01 && a<=800.00)
	{
		cout << fixed << setprecision(2) << "Novo salario: " << a*(12/100.0)+a << endl;
	    cout << "Reajuste ganho: " << a*(12/100.0) << endl;
        cout << "Em percentual: " << "12 %" << endl;
	}	
	else if ( a>=800.01 && a<=1200.00)
	{
		cout << fixed << setprecision(2) << "Novo salario: " << a*(10/100.0)+a << endl;
	    cout << "Reajuste ganho: " << a*(10/100.0) << endl;
        cout << "Em percentual: " << "10 %" << endl;
	}	
	else if ( a>=1200.01 && a<=2000.00)
	{
		cout << fixed << setprecision(2) << "Novo salario: " << a*(7/100.0)+a << endl;
	    cout << "Reajuste ganho: " << a*(7/100.0) << endl;
        cout << "Em percentual: " << "7 %" << endl;
	}	
	else if ( a>2000.00)
	{
		cout << fixed << setprecision(2) << "Novo salario: " << a*(4/100.0)+a << endl;
	    cout << "Reajuste ganho: " << a*(4/100.0) << endl;
        cout << "Em percentual: " << "4 %" << endl;
	}	
	return 0;	
}
	