#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main () 
{
  double x1,x2,y1,y2,c1,c2,hip;
  
  cin >> x1;
  cin >> y1;
  cin >> x2;
  cin >> y2;
  
c1 = x2-x1;
c2 = y2-y1;
hip = sqrt((c1*c1)+(c2*c2));
   
   cout << fixed << setprecision(4) << hip << endl;
   
return 0 ;
}