#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a;
	bool errado;
	while(cin>>a){
		if(a==0)
			break;
		int b[a];
		int c[a];
		int d[a];
		
		errado = false;
		for(int i=0;i<a;i++)
			b[i] = -1;
		
		for(int i=0;i<a;i++)
				cin >> c[i] >> d[i];
			
		for(int i=0;i<a;i++){
			if(i+d[i]>=a || i+d[i]<0){
				errado = true;
				break;
			}
			else if(b[d[i]+i] !=-1){
				errado = true;
				break;
			}
			else{
				b[d[i]+i] = c[i];
			}
		}
		if(errado)
			cout << "-1" << endl;
		else{
			for(int i=0;i<a-1;i++)
				cout << b[i] << " ";
			cout << b[a-1] << endl;
		}
	}
	return 0;
}