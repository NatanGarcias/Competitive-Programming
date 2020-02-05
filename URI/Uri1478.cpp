#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a;
	for(;;)
	{
		cin >> a;
		if(a==0)
			break;
		else
		{
			int b[a][a] = {};

			for(int i=0;i<a;i++)
				for(int j=0;j<a;j++)
				{
					int k;
					
					if(j>i)
						b[i][j] = j-i+1;
					if(i>j)
						b[i][j] = i-j+1;
					if(i==j)
						b[i][j] = 1;
					
				}
				
			for(int i=0;i<a;i++)
				for(int j=0;j<a;j++)
					{
							if(j==a-1)
								cout << setw(3) << b[i][j] << endl;
							else
								cout << setw(3) << b[i][j] << " ";
					}
					
			cout << endl;
		}
	}
	return 0;
}