#include<bits/stdc++.h>
using namespace std;

void f(int a,int b){
	for(int i = -1000;i<1000;i++){
		for(int j=0;j<abs(b);j++){
			if(a == b*i+j){
				cout << i << " " << j << endl;
				return;
			}
		}
	}
}
int main(){

	int a,b;
	cin >> a >> b;
	f(a,b);	
}