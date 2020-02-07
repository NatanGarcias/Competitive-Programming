#include<bits/stdc++.h>
using namespace std;

#define tam 101
int main (){
	int a;
	scanf("%d\n\n",&a);
	for(int i=0;i<a;i++){
		if(i)
			cout << endl;
		char m[tam][tam];
		for(int j=0;j<tam;j++){
			for(int k=0;k<tam;k++){
				m[j][k] = 'a';				
			}
		}
		string s;
		int k=0;
		while(getline(cin,s)){
			if(s[0]!='L' && s[0]!='W'){
				goto z;
			}
			k++;
			for(int j=1;j<=s.size();j++){
				m[k][j] = s[j-1];
			}
		}
		while(getline(cin,s)){
			if(s.empty())
				break;
			z:
			int cont=0;
			int x,y;
			sscanf(s.c_str(),"%d %d",&x,&y);
			if(m[x][y]=='L')
				cout << 0 << endl;
			else{
				int visit[tam][tam];
				for(int j=0;j<tam;j++){
					for(int k=0;k<tam;k++){
						visit[j][k] = 0;				
					}
				}	
				stack< pair<int,int> > pilha;
				pilha.push({x,y});
				visit[x][y] = 1;
				while(!pilha.empty()){
					x = pilha.top().first;
					y = pilha.top().second;
					pilha.pop();
					for(int j=-1;j<2;j++){
						for(int k=-1;k<2;k++){
							if(m[x+j][y+k]=='W'){
								if(visit[x+j][y+k]!=1){
									pilha.push({x+j,y+k});
									visit[x+j][y+k] = 1;
								}
							}
						}
					}
					++cont;
				}
			}
			cout << cont << endl;
		}
	}	
}