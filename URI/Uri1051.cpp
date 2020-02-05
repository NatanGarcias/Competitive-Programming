#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	double a;
	
	cin >> a;
	
	if (a<=2000.00)
		cout << "Isento" << endl;
	else if ( a>2000.00 && a<=3000.00)
		cout << fixed << setprecision(2) << "R$ " << (a-2000.00)*(8.0/100) << endl;
	else if (a>3000.00 && a<=4500.00)
	    cout << fixed << setprecision(2) << "R$ " << (1000*(8.0/100))+((a-3000.00)*(18.0/100)) << endl;
	else if (a>4500.00)
		cout << fixed << setprecision(2) << "R$ " << (1000.00*(8.0/100))+(1500.00)*(18.0/100)+((a-4500.00)*(28.0/100)) << endl;
	return 0;	
}
	