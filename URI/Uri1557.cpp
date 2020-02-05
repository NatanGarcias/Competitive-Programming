#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a;
	double c;
	for(;;)
	{
		cin >> a;
		if(a==0)
			break;
		else
		{
			int b[a][a];
			if(a==1)
				cout << "1" << endl;
			else{
				int b[a][a];
				for(int i=0;i<a;i++)
					for(int j=0;j<a;j++){
						b[i][j] = c = pow(2,i+j);
						
					}
				for(int i=0;i<a;i++)
					for(int j=0;j<a;j++)
						{
								if(j==a-1)
									cout << setw(log10(c)+1) << b[i][j] << endl;
								else
									cout << setw(log10(c)+1) << b[i][j] << " ";
						}
			}
			cout << endl;
		}
	}
	return 0;
}