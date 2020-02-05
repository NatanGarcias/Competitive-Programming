#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a,z=0,x,k;
	
	for(int i=1;i<=100;i++)
	{
		cin >> a;
		x=a;
		if(x>z)
		{
			z=x;
			k=i;
		}
	}
    cout << z << endl;
	cout << k << endl;
	
	return 0;
}