#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int e,f,g;
	cin >> e;
	for(int i=0;i<e;i++)
	{
		cin >> g;
		f=0;
		for(int i=1;i<g;i++)
			if(g%i==0)
				f+=i;
		if(f==g)
			cout << g << " eh perfeito" << endl;
		else
			cout << g << " nao eh perfeito" << endl;
	}
	return 0;
}