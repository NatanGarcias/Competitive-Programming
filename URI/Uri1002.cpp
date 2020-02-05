#include <iostream>
#include <iomanip>
using namespace std;
 
 int main ()
 {
   double area, raio, pi ;
   
   cin >> raio;
   
  pi = 3.14159;
  area= (raio*raio) * pi;    
  
  cout << "A=" << fixed << setprecision(4) << area << endl;
  
  return 0;
  }
  