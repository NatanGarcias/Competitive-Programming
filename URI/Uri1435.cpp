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
			int b[a+2][a+2];
			
			for(int i=0;i<a+2;i++)
				for(int j=0;j<a+2;j++)
						b[i][j] = 0;
					
			for(int k=0;k<a;k++)
				for(int i=1;i<=a;i++)
					for(int j=1;j<=a;j++)
					{
						int menor = 500;
						if( b[i-1][j-1]<menor)
							menor = b[i-1][j-1]; 
						if( b[i-1][j]<menor)
							menor = b[i-1][j]; 
						if( b[i-1][j+1]<menor)
							menor = b[i-1][j+1];
						if( b[i][j-1]<menor)
							menor = b[i][j-1];  					
						if( b[i][j+1]<menor)
							menor = b[i][j+1];  
						if( b[i+1][j-1]<menor)
							menor = b[i+1][j-1]; 
						if( b[i+1][j]<menor)
							menor = b[i+1][j]; 
						if( b[i+1][j+1]<menor)
							menor = b[i+1][j+1];
					
						b[i][j] = menor+1;
					
					}
		
			for(int i=1;i<=a;i++)
				for(int j=1;j<=a;j++)
					{
							if(j==a)
								cout << setw(3) << b[i][j] << endl;
							else
								cout << setw(3) << b[i][j] << " ";
					}
					
			cout << endl;
		}
	}
	return 0;
}