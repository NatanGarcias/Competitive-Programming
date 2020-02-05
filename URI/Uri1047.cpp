#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
	int  a,b,c,d,minutos,horas;
	
	cin >> a >> b >> c >> d;
	
	if (b==d)
	    minutos = 0;
    if (b<d)
	    minutos = d-b;
	if (d<b)
		minutos = (60-b)+d;
	
	if (a==c && b>d)
		horas = 24;
    if (a==c && b<d)
		horas = 0;
	if (a<c && b>d)
	    horas = c-a-1;
	if (a<c && d>b)
	    horas = c-a;
	if (c<a && d>b)
	    horas = (24-a)+c;
	if (c<a && b>d)
	    horas = (24-a)+c-1;
	
	
	cout << "O JOGO DUROU " << horas << " HORA(S) E " << minutos << " MINUTO(S)" << endl;
	
	return 0;	
}
	