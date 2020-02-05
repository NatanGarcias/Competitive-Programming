#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a;
	double b,c,d;
	
	cin >> a;
	
	for(int i=1;i<=a;i++)
	{
		cin >> b >> c >> d;
		cout << fixed << setprecision(1) <<((b*2)+(c*3)+(d*5))/10 << endl;
	}

	return 0;
}