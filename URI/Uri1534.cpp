#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a;
	while(cin >> a)
	{
		int b[a][a];

		for(int i=0;i<a;i++)
			for(int j=0;j<a;j++)
				b[i][j] = 3;
				
		for(int i=0,j=0;i<a;i++,j++)
				b[i][j] = 1;
				
		for(int i=0;i<a;i++)
			for(int j=0;j<a;j++)
				if(i+j == a-1)
					b[i][j] = 2;
				
		for(int i=0;i<a;i++)
			for(int j=0;j<a;j++)
			{
				if(j==a-1)
					cout << b[i][j] << endl;
				else
					cout << b[i][j];
			}
	}
	return 0;
}