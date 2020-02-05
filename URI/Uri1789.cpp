#include<bits/stdc++.h>
using namespace std;

int main(){

	int a,d;
	while(cin >> a){
		int b;
		int resposta=1;
		for(int i=0;i<a;i++){
			cin >> d;
			if(resposta==1 and d>=10 and d< 20)
				resposta =2;
			else if(d>=20)
				resposta =3;
		}
		cout << resposta << endl;
	}
}