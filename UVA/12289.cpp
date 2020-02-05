#include<bits/stdc++.h>
using namespace std;

void f(const string &b){
	if(b.size()>3){
		cout << '3' << endl;
		return;
	}
	else{
		int cont=0;
		if(b[0]=='o')
			cont++;
		if(b[1]=='n')
			cont++;
		if(b[2]=='e')
			cont++;

		if(cont>=2){
			cout << '1' << endl;
		}
		else{
			cout << '2' << endl;
		}
	}
	
}

int main(){
	int a;
	cin >> a;
	string b;
	for(int i=0;i<a;i++){
		cin >> b;
		f(b);	
	}
}