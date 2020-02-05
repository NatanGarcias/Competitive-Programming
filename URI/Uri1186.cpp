#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double d = 0.0;
	bool k = false;
	char b;
	cin >> b;
	
	if(b == 'S')
		k = true;

	double c[12][12];
	
	for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)
			cin >> c[i][j];
		
	for(int i=0;i<12;i++)
		for( int j=0;j<12;j++)
			if(j+i>11)
				d+= c[i][j];

	if(k)
		cout << fixed << setprecision(1) << d << endl;
	else
		cout << fixed << setprecision(1) << d/66 << endl;

	return 0;
}