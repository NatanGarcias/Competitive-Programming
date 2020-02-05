#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int cont=0;
	int som=0;
	int l=0;
	int v[3]={0};
	while(getline(cin,s)){
		if(s[0] =='c'){
			v[l++] = som;
			som=0;
			cont++;
			continue;
		}
		if(cont==3)
			break;
		int b=0;
		//cout << s.size() << endl;
		for(int i=0;i<s.size();i++){
			if(s[i]=='*')
				b = b|(1<<(s.size()-i-1));
		}
		//cout << "b: "<< b << endl;
		som+=b;
	}
	cout << v[0] << endl << v[1] << endl << v[2] << endl;

}