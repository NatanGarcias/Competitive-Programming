#include <iostream>
#include <iomanip>
using namespace std;
  
  int main()
{
  double A, B, C, triangulo, trapezio, circulo, quadrado, retangulo,pi;
  
  cin >> A >> B >> C ;
  
  pi= 3.14159;
  triangulo=  A*C /2;
  circulo= pi*(C*C);
  trapezio= ((A+B)*C)/2;
  quadrado= B*B;
  retangulo= A*B;
  
  cout << fixed << setprecision(3) << "TRIANGULO: " << triangulo << endl;
  cout << fixed << setprecision(3) << "CIRCULO: " << circulo << endl;
  cout << fixed << setprecision(3) << "TRAPEZIO: " << trapezio << endl;
  cout << fixed << setprecision(3) << "QUADRADO: " << quadrado << endl;
  cout << fixed << setprecision(3) << "RETANGULO: " << retangulo << endl;
  
  return 0;
}
  