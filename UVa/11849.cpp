#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,d,e,cont;
	while(cin >> a >> b){
		if(a==0 && b ==0)
			break;
		cont =0;
		
		set<int> aux;
		set<int> aux2;
		
		for(int i=0;i<a;i++){
			cin >>d;
			aux.insert(d);
		}
		for(int i=0;i<b;i++){
			cin >>d;
			aux2.insert(d);
		}
		
		set<int>::iterator it;
		set<int>::iterator it2;

		it = aux.begin();
		it2 = aux2.begin();
		while(it!= aux.end() && it2 != aux2.end()){
			d = *it;
			e = *it2;
			if(d == e){
				cont++;
				++it;
				++it2;
			}
			else if(d>e){
				++it2;
			}
			else{
				++it;
			}
		}
		cout << cont << endl;
	}
	return 0;
}