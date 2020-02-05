#include<bits/stdc++.h>
using namespace std;

int main(){

	int a;
	while(cin >> a){
		int b[a][a];
		memset(b,0,sizeof(b));
		for(int i=0;i<a;i++){
			b[i][i] = 2;
			b[a-i-1][i] = 3;
		}
		int k = (2*a)/3 ;;

		//cout << k << endl;
		k+= a%3==0?-1:0;

		//cout << k << endl;
		for(int i=a/3;i<=k;i++){
			for(int j=a/3;j<=k;j++){
				b[i][j] = 1; 
			}
		}
		b[a/2][a/2] =4;

		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				cout << b[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	
}