#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a,b;
	int j=0,k=0;
	
	cin >> a;
	
    for (int i=1;i<=a;i++)
	{
		cin >> b;
		if(b>=10 && b<=20)
			j++;
		else 
			k++;
	}
    cout << j << " in" << endl;
	cout << k << " out" << endl;
	
	return 0;	
}