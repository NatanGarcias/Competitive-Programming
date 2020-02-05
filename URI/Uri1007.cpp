#include <iostream>
#include <iomanip>
using namespace std;
 
  int main ()
{
  int A,B,C,D, Diferenca;
  
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> D;
  
  Diferenca = A*B - C*D;
  
  cout <<"DIFERENCA = " << Diferenca << endl ;
  
  return 0;
  }