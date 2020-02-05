#include <iostream>
using namespace std;
  
  int main ()
{
  float A,B,C, Maior,Maiorab;
  
  cin >> A;
  cin >> B;
  cin >> C;
  
Maiorab = ( A+B+abs(A-B))/2;
Maior = (Maiorab+C+abs(Maiorab-C))/2;

cout << Maior <<" eh o maior" << endl;

return 0;
}