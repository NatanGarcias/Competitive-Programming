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
	
	for (int i=1;i<=a;i++)
	{
		if(i%2==1)
		{
            j++;
		    k[j]=i;
		}			
    }
	for (int l=1;l<=j;l++)
	cout << k[l] << endl;
	
	return 0;	
}