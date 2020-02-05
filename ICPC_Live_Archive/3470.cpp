#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b;
	bool d,aluno;
	while(cin>>a>>b){
		if(a==0 && b ==0)
			break;
		int c[a][b];
		aluno = false;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				cin >> c[i][j];
			
		for(int i=0;i<a;i++){
			d = true;
			for(int j=0;j<b;j++){
				if(c[i][j]==0)
					d = false;
			}
			if(d==true)
				aluno = true;
		}
		if(aluno)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}