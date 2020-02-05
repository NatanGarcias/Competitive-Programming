#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main ()
  {
	  int x ,a ,m ,d ;
	  
	  cin >> x;
	  
	  a= x/365;
	  m= (x%365)/30;
	  d= (x%365)%30;
	  
	  cout << a << " ano(s)" << endl ;
      cout << m << " mes(es)" << endl;
	  cout << d << " dia(s)" << endl;
	  
	 
	  return 0;
  }