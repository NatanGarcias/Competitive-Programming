#include <iostream>
#include <iomanip>
using namespace std;
  
  int main ()
{
  double tempo,velocidade,distancia,kml,litros;
  
  cin >> tempo;
  cin >> velocidade;
  
  distancia= tempo*velocidade ;
  litros = distancia/12;
  
  cout << fixed << setprecision(3) << litros << endl;
  
return 0;
}
  