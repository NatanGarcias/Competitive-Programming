#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a,b;
	int j=0;
	
	cin >> a >> b;
	if (a>b)
	{
		int c;
		c=a;
		a=b;
		b=c;
	}
	a++;
    for (int i=1;a<b;i++)
	{
		if(a%2==1 || a%2==-1)
		    j+= a;
	    a++;
	}
    cout << j << endl;
	
	return 0;	
}