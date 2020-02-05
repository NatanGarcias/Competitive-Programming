#include<bits/stdc++.h>
using namespace std;

int main(){
	int a;
	int i=0;
	int f = 0;
	cin >> a;
	cin.ignore();
	string k;
	getline(cin,k);
	x:
	set<string> str;
	unordered_multiset<string> str2;
	string s;
	double cont=0.0;
	while(getline(cin,s)){
		f=1;
		++cont;
		if(s!=""){
			str.insert(s);
			str2.insert(s);
		}
		else{
			cont--;
			f=0;
			for(auto y : str){
				k = y;
				cout << k << " "<< fixed << setprecision(4) << str2.count(k)*100/cont << endl;
			}
			if(i++!=a){
				cout << endl;
				goto x;
			}
		}
	}
	if(f){
		for(auto y : str){
				k = y;
				cout << k << " " << fixed << setprecision(4) << str2.count(k)*100/cont << endl;
		}
	}
	return 0;
}