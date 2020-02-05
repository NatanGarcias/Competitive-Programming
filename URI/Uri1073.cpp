#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a,b;
	
	cin >> a;
	
    for (int i=1;i<=a;i++)
	{
		if(i%2==0)
		{
			cout << i << "^" << '2' << " = " << i*i << endl;
		}
	}
	
	return 0;	
}