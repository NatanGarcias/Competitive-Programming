#include<bits/stdc++.h>
using namespace std;

int bl2(const vector<vector<int>> &v, int a, int ondeQueroIr, queue<int>&fila, int visited[]){
	while(!fila.empty()){
		for(int i=0;i<v[a].size();i++){
			if(visited[v[a][i]]==0){
				if(v[a][i] == ondeQueroIr)	return visited[a];
				else{
					fila.push(v[a][i]);
					visited[v[a][i]] = visited[a]+1;
				}
			}
		}
		fila.pop();
		a = fila.front();
	}
}

void bl(const vector<vector<int>> &v, int a, int ondeQueroIr, int visitados[]){
	queue<int> fila;
	fila.push(a);
	visitados[a] = 1;
	cout << bl2(v,a,ondeQueroIr,fila, visitados) << endl;
}

int difere(string a, string b){
	if(a.size()!= b.size())	return 5;
	int cont=0;
	for(int i=0;i<a.size();i++){
		if(a[i] != b[i])
			cont++;
	}
	return cont;
}

int main(){
	int a;
	scanf("%d",&a);
	cin.ignore();
	cin.ignore();
	for(int i=0;i<a;i++){
		if(i)
			cout << endl;
		string s;
		map<int,string> mapa;
		map<string,int> mapa2;
		int cont =0;
		while(cin >> s){
			if(s[0] =='*'){
				break;
			}
			mapa[cont] = s;
			mapa2[s] = cont;
			cont++;
		}
		vector<vector<int>> v(mapa.size());
		for(int j=0;j<mapa.size();j++){
			string s1 = mapa[i];
			for(int k=j+1;k<mapa.size();k++){
				if( difere(mapa[j], mapa[k]) <2){
					v[j].push_back(k);
					v[k].push_back(j);
				}	
			}
		}
		string s3;
		cin.ignore();
		while(getline(cin,s3)){
			if(s3.empty())
				break;
			stringstream s4;
			s4 << s3;
			string s5,s6;
			s4 >> s5 >> s6;
			cout << s5 << " " << s6 << " ";
			int visitados[mapa.size()] = {0};
			if(s5 == s6)
				cout << 0 << endl;
			else{	bl(v,mapa2[s5],mapa2[s6],visitados); }
		}
	}	
}