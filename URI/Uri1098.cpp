#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double i=-0.2,j=0.8;
	int z=0;
	for(;;)
	{
		i+=0.2;
		j+=0.2;
		
		for(int k=0;k<3;k++)
		{
			cout << "I=" << i << " " << "J=" << j << endl;
			j=j+1;
		}
		j-=3;
		z=(i+0.2);
		if(z==2)
			break;
	}		
	return 0;
}