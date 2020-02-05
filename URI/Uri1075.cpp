#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a;
	
	cin >> a;
	
	for(int i=1;i<10000;i++)
	{
		if (i%a==2)
			cout << i << endl;
	}
	return 0;
}