#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a;
	while(cin >>a){
		if(a==0)
			break;
		cout << ((a+1)*(2*a+1)*a)/6 << endl;
	}
	return 0;
}