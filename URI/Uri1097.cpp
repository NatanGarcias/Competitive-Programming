#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int i=-1,j=2;
	for(;i!=9;)
	{
		i+=2;
		j+=5;
		
		for(int k=0;k<3;k++)
		{
			cout << "I=" << i << " " << "J=" << j << endl;
			j--;
		}
	}		
	return 0;
}