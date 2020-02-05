#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main ()
  {
	  int nota100,nota50,nota20,nota10,nota5,nota2,dinheiro,m100,m50,m25,m10,m5,m1,centavos;
	  char a;
	  cin >> dinheiro >> a >> centavos;
	  
	  nota100= dinheiro/100;
	  nota50= (dinheiro%100)/50;
	  nota20= ((dinheiro%100)%50)/20;
	  nota10= (((dinheiro%100)%50)%20)/10;
	  nota5= ((((dinheiro%100)%50)%20)%10)/5;
	  nota2=(((((dinheiro%100)%50)%20)%10)%5)/2;
	  m100=((((((dinheiro%100)%50)%20)%10)%5)%2)/1;
	  m50= centavos/50;
	  m25=(centavos%50)/25;
	  m10=((centavos%50)%25)/10;
	  m5=(((centavos%50)%25)%10)/5;
	  m1=((((centavos%50)%25)%10)%5)/1;
	  
	  cout << "NOTAS:" << endl ;
	  cout << fixed << setprecision(2) << nota100 << " nota(s) de R$ 100.00" << endl;
	  cout << fixed << setprecision(2) << nota50 << " nota(s) de R$ 50.00" <<  endl;
	  cout << fixed << setprecision(2) << nota20 << " nota(s) de R$ 20.00" << endl;
      cout << fixed << setprecision(2) << nota10 << " nota(s) de R$ 10.00" << endl;
	  cout << fixed << setprecision(2) << nota5 << " nota(s) de R$ 5.00" << endl;
	  cout << fixed << setprecision(2) << nota2 << " nota(s) de R$ 2.00" <<  endl;
	  cout << "MOEDAS:" << endl;
	  cout << fixed << setprecision(2) << m100 << " moeda(s) de R$ 1.00" <<  endl;
	  cout << fixed << setprecision(2) << m50 << " moeda(s) de R$ 0.50" <<  endl;
	  cout << fixed << setprecision(2) << m25 << " moeda(s) de R$ 0.25" <<  endl;
	  cout << fixed << setprecision(2) << m10 << " moeda(s) de R$ 0.10" <<  endl;
	  cout << fixed << setprecision(2) << m5 << " moeda(s) de R$ 0.05" <<  endl;
	  cout << fixed << setprecision(2) << m1 << " moeda(s) de R$ 0.01" <<  endl;
	  
	  return 0;
  }