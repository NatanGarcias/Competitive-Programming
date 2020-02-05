#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll _tam_crivo;

bool v[1000010] = {0};

set<int> primos;

void crivo(ll limite) { // cria lista de primos em [0..limite]
    _tam_crivo = limite + 1; // + 1 para incluir limite
    for (ll i = 2; i <= _tam_crivo; i++){
        if (!v[i]) {   //corta todos os multiplos de i comecando de i*i
            for (ll j = i*i; j < _tam_crivo;j+=i)   v[j] = true;
            primos.insert(i); // adiciona na lista de primos
        }
    }
}

int main(){
	crivo(1000009);
	int a;
	while(cin >>a){
		if(!a)	break;
		cout << a << ':' << endl;
		
		int b;

		for(set<int>::iterator it = primos.begin();it!=primos.end();it++){
			set<int>::iterator it2 = primos.find(a-(*it));
			if(it2 !=primos.end()){
				cout << (*it) << '+' << (*it2) << endl;
				goto x;
			}
		}
		cout << "NO WAY!" << endl;
		x:
		int narda;
	}
}