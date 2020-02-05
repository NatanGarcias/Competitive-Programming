#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll soma=0;
ll somaAntiga=0;
ll somaSuperAntiga=0;
ll numero =0;
ll cont=0;
ll primo = 1000000007;

ll substrings(string s){
	string s1(s.begin(),s.begin()+1);
	numero = stoi(s1);
	cont+=1;
	soma +=(cont)*numero;
	somaSuperAntiga = soma;
	if(s.size()<2) return soma;

	soma*=10;
	string s2(s.begin()+1,s.begin()+2);
	numero = stoi(s2);
	cont+=1;
	soma +=(cont)*numero;
	soma+=somaSuperAntiga;
	if(s.size()<3) return soma;

	for(int i=2;i<s.size();i++){
		somaAntiga = soma;
		soma= (((soma%primo)-(somaSuperAntiga%primo)) %primo);
		while(soma<0) 	soma+=primo;
		soma = ((soma%primo)*(10%primo))%primo;
		string s2(s.begin()+i,s.begin()+i+1);
		numero = stoi(s2);
		cont+=1;
		soma=  (((soma%primo) + ((cont*numero)%primo)) %primo );
		soma=  (((soma%primo) + (somaAntiga%primo)) %primo);
		somaSuperAntiga = somaAntiga;
	}
	return soma;
}
int main (){
	string a;
	cin >> a;
	substrings(a);
	cout << soma << endl;

}