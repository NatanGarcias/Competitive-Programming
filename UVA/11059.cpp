#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll n;
ll soma;

void g(ll a[], ll pos,ll valor){
	for(ll i=pos;i<n;i++){
		valor*=a[i];
		if(valor >soma)
			soma = valor;		
	}
}

void f(ll a[],ll cont){
	for(ll i=0;i<n;i++){
		ll k=1;
		g(a,i,k);	
	}
	if(soma>=0)
		cout << "Case #" << cont << ": The maximum product is " << soma << '.' << endl;
	else
		cout << "Case #" << cont << ": The maximum product is " << 0 << '.' << endl;
	cout << endl;
}

int main(){
	ll cont =0;
	while(cin >> n){
		soma =0;
		soma -=10E15;
		ll a[n];
		cont++;
		for(ll i=0;i<n;i++){
			cin >> a[i];
		}
		f(a,cont);
	}
}