#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	float a,b,c,maior,maior2;
	
	cin >> a >> b >> c ;
	
	maior = a>b?a:b;
	maior2= maior>c?maior:c;
	
	if  ( maior2<(a+b+c-maior2))
        cout << fixed << setprecision(1) << "Perimetro = " << a+b+c << endl;
    else 
        cout << fixed << setprecision(1) << "Area = " << ((a+b)*c)/2 << endl; 	
	
	return 0;	
}
	