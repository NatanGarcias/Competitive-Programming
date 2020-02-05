#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b,d,maior,cont;
	bool errado;
	while(cin >> a >> b){
		maior = 0;
		errado = false;
		if(a>b){
			errado = true;
			int c = a;
			a = b;
			b = c;
		}
		for(int i=a;i<=b;i++){
			cont = 1;
			d = i;
			while(d!=1){
				if(d%2 == 0)
					d/=2;
				else
					d = 3*d+1;
				cont++;
			}
			if(cont > maior)
				maior = cont;
		}
		if(!errado)
			cout << a << " " << b << " " << maior << endl;
		else
			cout << b << " " << a << " " << maior << endl;
	}
	return 0;
}