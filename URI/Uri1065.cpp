#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a,cont=0;
	
	for (int i=1;i<=5;i++)
	{
		cin >> a;
		if(a%2==0)
			cont++;
	}
	cout << cont << " valores pares" << endl;
	
	return 0;	
}
	