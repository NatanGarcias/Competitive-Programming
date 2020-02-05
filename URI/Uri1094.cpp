#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	double a,b,s=0,c=0,r=0,t=0;
	char d;
	cin >> a;
	
	for (int i=0;i<a;i++)
	{
		cin >> b >> d;
		if (d=='R')
			r+=b;
		else if (d=='S')
			s+=b;
		else
			c+=b;
		t+=b;
	}
	cout << "Total: " << t << " cobaias" << endl;
	cout << "Total de coelhos: " << c << endl;
	cout << "Total de ratos: " << r << endl;
	cout << "Total de sapos: " << s << endl;
	cout << fixed << setprecision(2) << "Percentual de coelhos: " << c/t*100.0 << " %" << endl;
	cout << fixed << setprecision(2) << "Percentual de ratos: " << r/t*100.0 <<  " %" << endl;
	cout << fixed << setprecision(2) << "Percentual de sapos: " << s/t*100.0 <<  " %" << endl;
	
	
	return 0;
}