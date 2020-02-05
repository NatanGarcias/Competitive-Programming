#include<bits/stdc++.h>
using namespace std;

int tab[10000] = {0};
long contar(int moeda[],int nmoedas,int troco) {
	int i,j,valormoeda;
		tab[0] = 1;

	for(int i=1;i<=troco;i++)
		tab[i] = 0;

	for(i=0; i<nmoedas; i++) {
		valormoeda = moeda[i];
		for (j=valormoeda; j<=troco; j++)
			tab[j] += tab[j-valormoeda];
	}
	return tab[troco];
}

int main(){
	int moeda[5];
	moeda[0] = 1;
	moeda[1] = 5;
	moeda[2] = 10;
	moeda[3] = 25;
	moeda[4] = 50;
	int a;
	while(cin >> a)
		cout << contar(moeda,5,a) << endl;
}	