#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int a;
	double d = 0.0;
	bool k = false;
	
	cin >> a;
	
	char b;
	cin >> b;
	
	if(b == 'S')
		k = true;

	double c[12][12];
	
	for(int i=0;i<12;i++)
		for( int j=0;j<12;j++)
			cin >> c[i][j];
		
	for(int i=0;i<12;i++)
		d+= c[i][a];

		
	if(k)
		cout << fixed << setprecision(1) << d << endl;
	else
		cout << fixed << setprecision(1) << d/12 << endl;

	return 0;
}