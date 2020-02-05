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
		cin >> b;
		if(b==0)
		    cout << "NULL" << endl;
		else if (b%2==0 && b>0)
			cout << "EVEN" << " " << "POSITIVE" << endl;
		else if (b%2==1 && b>0)
			cout << "ODD" << " " << "POSITIVE" << endl;
		else if (b%2==0 && b<0)
			cout << "EVEN" << " " << "NEGATIVE" << endl;
		else
			cout << "ODD" << " " << "NEGATIVE" << endl;
	}
	
	return 0;	
}