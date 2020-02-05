#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin >> a >>b;

	if(a>b)
		cout << "Eu odeio a professora!" << endl;
	else if(a+3<=b)
		cout << "Muito bem! Apresenta antes do Natal!" << endl;
	else{
		cout << "Parece o trabalho do meu filho!" << endl;
		if(a+2<24)
			cout << "TCC Apresentado!" << endl;
		else
			cout << "Fail! Entao eh nataaaaal!" << endl;
	}
}