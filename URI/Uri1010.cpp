#include <iostream>
#include <iomanip>
using namespace std;

  int main ()
{

  float codigo1, numero1, valorunitario1, codigo2 , numero2, valorunitario2, total;
  
  cin >> codigo1 >> numero1 >> valorunitario1;
  cin >> codigo2 >> numero2 >> valorunitario2;

  total= numero1 * valorunitario1 + numero2 * valorunitario2;
  
  cout << fixed << setprecision(2) << "VALOR A PAGAR: R$ " << total << endl ;

  return 0;

}  