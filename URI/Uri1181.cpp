#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double b[12][12];
	double a,d=0.0;
	char c;
	
	cin >> a;
	
	cin >> c;
	
	for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)
		{
			cin >> b[i][j];
			if(i==a)
				d+=b[i][j];
		}

	if(c == 'S')
		cout << fixed << setprecision(1) << d << endl;
	else
		cout << fixed << setprecision(1) << d/12 << endl;

	return 0;
	
}

		