#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main ()
  {
	  int valor ,h ,m ,s ;
	  
	  cin >> valor;
	  
	  h= valor/3600;
	  m= (valor%3600)/60;
	  s= ((valor%3600)%60);
	  
	  cout << h << ":" << m << ":" << s << endl ;
	  
	 
	  return 0;
  }