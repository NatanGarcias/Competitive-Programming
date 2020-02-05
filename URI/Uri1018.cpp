#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main ()
  {
	  int nota100,nota50,nota20,nota10,nota5,nota2,nota1,dinheiro;
	  
	  cin >> dinheiro;
	  
	  nota100= dinheiro/100;
	  nota50= (dinheiro%100)/50;
	  nota20= ((dinheiro%100)%50)/20;
	  nota10= (((dinheiro%100)%50)%20)/10;
	  nota5= ((((dinheiro%100)%50)%20)%10)/5;
	  nota2=(((((dinheiro%100)%50)%20)%10)%5)/2;
	  nota1=((((((dinheiro%100)%50)%20)%10)%5)%2)/1;
		  
	  
	  cout << dinheiro << endl ;
	  cout << fixed << setprecision(2) << nota100 << " nota(s) de R$ 100,00" << endl;
	  cout << fixed << setprecision(2) << nota50 << " nota(s) de R$ 50,00" <<  endl;
	  cout << fixed << setprecision(2) << nota20 << " nota(s) de R$ 20,00" << endl;
      cout << fixed << setprecision(2) << nota10 << " nota(s) de R$ 10,00" << endl;
	  cout << fixed << setprecision(2) << nota5 << " nota(s) de R$ 5,00" << endl;
	  cout << fixed << setprecision(2) << nota2 << " nota(s) de R$ 2,00" <<  endl;
	  cout << fixed << setprecision(2) << nota1 << " nota(s) de R$ 1,00" << endl;
	  
	  return 0;
  }