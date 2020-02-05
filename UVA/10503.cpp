#include<bits/stdc++.h>
using namespace std;

int espaco, quantidade;
int comeco,comeco2,fim;
bool deu;

void possible(const vector<int> &v, const vector<int>&v2, bool solucoes[], int ultimo, int qual){
	if(qual == espaco){
		if(ultimo == fim)
			deu = true;
		return;
	}
	if(deu)
		return;
	for(int i=0;i<quantidade;i++){
		if(solucoes[i] ==0){
			if(ultimo == v[i]){
				solucoes[i] = true;
				possible(v,v2,solucoes,v2[i],qual+1);
				solucoes[i] = false;
			}
			if(ultimo == v2[i]){
				solucoes[i] = true;
				possible(v,v2,solucoes,v[i],qual+1);
				solucoes[i] = false;
			}
		}
	}
}
int main(){

	int c,d;
	int temp;
	while(cin >> espaco){
		if(espaco==0)
			break;
		cin >> quantidade;

		cin >> temp >> comeco;
		cin >> fim >> temp;
		vector<int> v;
		vector<int> v2;
		for(int i=0;i<quantidade;i++){
			cin >> c >> d;
			v.push_back(c);
			v2.push_back(d);
		}
		deu = false;
		bool solucoes[quantidade] = {0};
		possible(v,v2,solucoes,comeco,0);
		if(deu)
			cout <<"YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}