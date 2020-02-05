#include<bits/stdc++.h>
using namespace std;

int main ()
{
	double b,c,g,d=0,e=0,f=0;
	for(;;)
	{
		cin >> b >> c;
		if(b>c)
			d++;
		else if(b<c)
			e++;
		else if(b==c)
			f++;
		cout << "Novo grenal (1-sim 2-nao)" << endl;
		cin >> g;
		if(g==2)
			break;	
	}
	cout << d+e+f << " " << "grenais" << endl;
	cout << "Inter:" << d << endl;
	cout << "Gremio:" << e << endl;
	cout << "Empates:" << f << endl;
	if (d>e)
		cout << "Inter venceu mais" << endl;
	if (e>d)
		cout << "Gremio venceu mais" << endl;
	if (d==e)
		cout << "Nao houve vencedor" << endl;
		
	return 0;
}