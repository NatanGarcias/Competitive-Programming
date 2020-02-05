#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring> 
using namespace std;

int main ()
{
	int a;
	int j=0,k[1000];
	
	cin >> a;
	
	for (int i=1;i<=12;i++)
	{
		if(a%2==1)
		{
            j++;
		    k[j]=a;
			if (j==6)
				break;
		}			
        a++;
	}
	for (int l=1;l<=j;l++)
	    cout << k[l] << endl;
	
	return 0;	
}