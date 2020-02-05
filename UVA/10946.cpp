#include<bits/stdc++.h>
using namespace std;

int a;
int b;

char m[53][53];
char vis[53][53];

void g(vector<pair<int,char> > &v, int posX, int posY, char &l, int &cont){
	
	if(!vis[posX][posY]){
		vis[posX][posY] = true;
		cont++;
		if(!vis[posX-1][posY] && m[posX-1][posY] == l) {g(v,posX-1,posY,l,cont);} 
		if(!vis[posX+1][posY] && m[posX+1][posY] == l) {g(v,posX+1,posY,l,cont);} 
		if(!vis[posX][posY-1] && m[posX][posY-1] == l) {g(v,posX,posY-1,l,cont);} 
		if(!vis[posX][posY+1] && m[posX][posY+1] == l) {g(v,posX,posY+1,l,cont);} 
	}
}
void f(vector<pair<int,char> > &v){
	
	for(int i=1;i<a+1;i++){
		char letra;		
		for(int j=1;j<b+1;j++){
			int cont=0;
			if(m[i][j] == '.') {vis[i][j] == true; continue;}

			if(vis[i][j] == false){
				letra = m[i][j];
		
				g(v,i,j,letra,cont);
				v.push_back({cont,letra});
			}
		}
	}	
}

bool cmp(const pair<int,char> &a , const pair<int,char> &b){
	if(a.first>b.first)
		return true;
	else if (a.first<b.first)
		return false;
	else
		return a.second<b.second;
}
int main(){
	int c=0;
	
	while(cin >> a >> b){
		c++;
		
		if(a==0)
			break;
		
		for(int i=0;i<a+2;i++){
			for(int j=0;j<b+2;j++){
				vis[i][j] = 0;	
			}
		}
		int i=0;

		for(int k=0;k<a+2;k++)
			m[k][i] = '#';

		i=b+1;
		for(int k=0;k<a+2;k++)
			m[k][i] = '#';

		i=0;
		for(int k=0;k<b+2;k++)
			m[i][k] = '#';
	
		i = a+1;
		for(int k=0;k<b+2;k++)
			m[i][k] = '#';

		vector<pair<int,char> > v;		
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				cin >> m[i][j];	
			}
		}

		f(v);

		sort(v.begin(),v.end(),cmp);
		cout << "Problem " << c <<  ":" << endl;
		for(int i=0;i<v.size();i++){
			cout <<	v[i].second << " " << v[i].first << endl;

		}

	}
}