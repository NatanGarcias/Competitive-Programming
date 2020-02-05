#include<bits/stdc++.h>
using namespace std;

int main(){

	int a;
	cin >> a;
	for(int i=0;i<a;i++){
		string s,s1;
		int k,k1;
		cin >> s >> s1;
		int ven;

		if(s[0] == 't')
			k = 1;
		else if(s[0] == 'S')
			k=2;
		else if(s[0] == 'l')
			k=3;
		else if(s[1] == 'a')
			k=4;
		else 
			k=5;

		if(s1[0] == 't')
			k1 = 1;
		else if(s1[0] == 'S')
			k1=2;
		else if(s1[0] == 'l')
			k1=3;
		else if(s1[1] == 'a')
			k1=4;
		else 
			k1=5;

		if(k==1){
			if(k1 == 4 || k1 == 3)
				ven = 1;
			else if (k1 == 5 || k1 == 2)
				ven = -1;
			else
				ven =0;
		}
		else if(k==2){
			if(k1 == 1 || k1 == 5)
				ven = 1;
			else if (k1 == 3 || k1 == 4)
				ven = -1;
			else
				ven =0;
		}
		else if(k==3){
			if(k1 == 2 || k1 == 4)
				ven = 1;
			else if (k1 == 1 || k1 == 5)
				ven = -1;
			else
				ven =0;
		}
		else if(k==4){
			if(k1 == 2 || k1 == 5)
				ven = 1;
			else if (k1 == 3 || k1 == 1)
				ven = -1;
			else
				ven =0;
		}
		else if(k==5){
			if(k1 == 1 || k1 == 3)
				ven = 1;
			else if (k1 == 2 || k1 == 4)
				ven = -1;
			else
				ven =0;
		}
		cout << "Caso #" << i+1 << ": ";
		if(ven == 1)
			cout << "Bazinga!" << endl;
		else if (ven ==-1)
			cout << "Raj trapaceou!" << endl;
		else
			cout << "De novo!" << endl;
	}
}