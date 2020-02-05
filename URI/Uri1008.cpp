#include <iostream>
#include <iomanip>
using namespace std;
 
  int main ()
{
  float numero,horastrabalhadas,valorporhora,salario;
  
  cin >> numero;
  cin >> horastrabalhadas;
  cin >> valorporhora;

  salario = horastrabalhadas*valorporhora;

 cout << "NUMBER = " << numero << endl;
 cout << fixed << setprecision(2) << "SALARY = U$ " << salario << endl ;

return 0;
} 
  