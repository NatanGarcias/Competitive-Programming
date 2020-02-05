#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main ()
  {
    int a, b, c, d ,e , f;
	
	cin >> a >> b >> c >> d;
	
	e = c+d ;
	f = a+b;
	if ( b>c && d>a && e>f && c>=0 && d>+0 && a%2 ==0 )
		cout << "Valores aceitos" << endl;
	else 
		cout << "Valores nao aceitos" << endl;

	return 0;
  }