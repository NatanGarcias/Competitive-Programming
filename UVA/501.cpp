#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,e;
	string k;
	cin >> a;
	for(int i=0;i<a;i++){
		cin.ignore();
		getline(cin,k);
		cin >> b >> c;
		multiset<int> aux;
		vector <int> aux2;
		vector<int> aux3;
		for(int j=0;j<b;j++){
			cin >> e;
			aux3.push_back(e);
		}
		for(int j=0;j<c;j++){
			cin >> e;
			aux2.push_back(e);
		}	
		multiset<int>::iterator it2;
		for(int k=0;k<c;k++){
			if(k==0){
				for(int j=0;j<aux2[k];j++){
					aux.insert(aux3[j]);
				}
				it2 = aux.end();
				for(int f=0;f<aux2[k]-k;f++)
					it2--;
				cout << *it2 << endl;
			}
			else{
				for(int j=aux2[k-1];j<aux2[k];j++){
					aux.insert(aux3[j]);
				}
				it2 = aux.end();
				for(int f=0;f<aux2[k]-k;f++)
					it2--;
				cout << *it2 << endl;
			}
		}
		if(i+1!=a)
			cout << endl;
	}
	return 0;
}