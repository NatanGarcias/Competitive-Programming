#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d,f,g,cont;
	cin >> a;
	for(int i=0;i<a;i++){
		cont =0;
		cin >> b >> d;
		multiset<int> aux;
		multiset<int> aux2;
		for(int j=0;j<b;j++){
			cin >> c;
			aux.insert(c);
		}
		for(int j=0;j<d;j++){
			cin >> c;
			aux2.insert(c);
		}
		multiset<int>::iterator it=aux.begin();
		multiset<int>::iterator it2=aux2.begin();
		while(it!=aux.end() && it2!=aux2.end()){
			f = *it;
			g = *it2;
			if(f==g){
				++it;
				++it2;
			}
			else if(f>g){
				cont++;
				++it2;
			}
			else{
				cont++;
				++it;
			}
		}
		for(;it!=aux.end();){
			++it;
			cont++;
		}
		for(;it2!=aux2.end();){
			++it2;
			cont++;
		}
		cout << cont << endl;
	}
	return 0;
}