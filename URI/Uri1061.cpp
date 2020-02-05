#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a,b,c,d,e,f,g,h;
	string z,x;
    char m;	
	
	
	cin >> z >> a >> b >> m >> c >> m >> d;
	cin >> x >> e >> f >> m >> g >> m >> h;
	
	
	if (a==e)
		cout << '0' << " dia(s)" << endl;
	else if (a<e & f<b)
		cout << e-a-1<< " dia(s)" << endl;
	else if (a<e)
		cout << e-a << " dia(s)" << endl;
	if (b==f)
		cout << '0' << " hora(s)" << endl;
	else if (b<f && g<c)
		cout << f-b-1 << " hora(s)" << endl;
	else if (b>f && g<c)
		cout << (24-b)+f-1 << " hora(s)" << endl;
	else if (b<f)
		cout << f-b << " hora(s)" << endl;
	else if (b>f)
		cout << (24-b)+f << " hora(s)" << endl;
    if (c==g)
		cout << '0' << " minuto(s)" << endl;
	else if (c<g && h<d)
		cout << g-c-1 << " minuto(s)" << endl;
	else if (c>g && h<d)
		cout << (60-c)+g-1 << " minuto(s)" << endl;
    else if (c<g)
		cout << g-c << " minuto(s)" << endl;
	else if (c>g)
	    cout << (60-c)+g << " minuto(s)" << endl;
	if (d==h)
		cout << '0' << " segundo(s)" << endl;
	else if (d<h)
		cout << h-d << " segundo(s)" << endl;
	else if (d>h)
	    cout << (60-d)+h << " segundo(s)" << endl;
    
	return 0;	
}
	