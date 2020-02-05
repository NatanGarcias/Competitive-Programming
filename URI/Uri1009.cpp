#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
 
  int main()
{

  double salariofixo, totaldevendas, salariototal;
  string vendedor;
  
  cin >> vendedor;
  cin >> salariofixo;
  cin >> totaldevendas;
  
salariototal = salariofixo + totaldevendas*15/100;

cout << fixed << setprecision(2)<< "TOTAL = R$ " << salariototal<< endl;

return 0;
}
