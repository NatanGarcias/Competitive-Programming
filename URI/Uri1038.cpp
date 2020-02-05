#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main ()
  {
	double a, b, x,c  ;
	
	cin >> a >> b ;
	
	if ( a==1 )
	    c = 4.00;
	else if ( a==2)
		c = 4.50;
	else if ( a==3)
	    c = 5.00;
    else if ( a==4)
		c = 2.00;
    else 
		c = 1.50;
	
	x = c*b;

    cout << fixed << setprecision(2) << "Total: R$ " << x << endl;
	
	return 0;
  }