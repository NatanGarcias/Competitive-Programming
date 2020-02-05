#include<bits/stdc++.h>
using namespace std;

int cont;
bool ganhei;

unordered_map<string,string> mapa;

string mForString(int m[]){
	string s;
	for(int j=0;j<9;j++)
		s+= m[j]+'0';
	return s;
} 

void HD(string &s,int i){
	char aux = s[i*3+0];
	s[i*3+0] = s[i*3+1];
	s[i*3+1] = s[i*3+2];
	s[i*3+2] = aux;
}

void HE(string &s,int i){
	char aux = s[i*3+2];
	s[i*3+2] = s[i*3+1];
	s[i*3+1] = s[i*3+0];
	s[i*3+0] = aux; 
} 

void VD(string &s,int i){
	char aux = s[6+i];
	s[6+i] = s[3+i];
	s[3+i] = s[i];
	s[i] = aux;
}

void VE(string &s,int i){
	char aux = s[i];
	s[i] = s[3+i];
	s[3+i] = s[6+i];
	s[6+i] = aux;
} 

void BFS(queue< pair<string, string > > &fila){

	while(!fila.empty()){
		
		string s;
		string atual = fila.front().first; 
		string s2 = fila.front().second;
		fila.pop();

		HD(atual,0);

		if(mapa.find(atual) == mapa.end()){
			string s3 = s2;
			s3+="1H";
			mapa[atual] = s3;
			fila.push({atual,s3});
		}
		HE(atual,0);

		HD(atual,1);
		if(mapa.find(atual) == mapa.end()){
			string s3 = s2;
			s3+="2H";
			mapa[atual] = s3;
			fila.push({atual,s3});
		}
		HE(atual,1);

		HD(atual,2);
		if(mapa.find(atual) == mapa.end()){
			string s3 = s2;
			s3+="3H";
			mapa[atual] = s3;
			fila.push({atual,s3});
		}
		HE(atual,2);

		VD(atual,0);
		if(mapa.find(atual) == mapa.end()){
			string s3 = s2;
			s3+="1V";
			mapa[atual] = s3;
			fila.push({atual,s3});
		}
		VE(atual,0);

		VD(atual,1);
		if(mapa.find(atual) == mapa.end()){
			string s3 = s2;
			s3+="2V";
			mapa[atual] = s3;
			fila.push({atual,s3});
		}
		VE(atual,1);

		VD(atual,2);
		if(mapa.find(atual) == mapa.end()){
			string s3 = s2;
			s3+="3V";
			mapa[atual] = s3;
			fila.push({atual,s3});
		}
		VE(atual,2);	
	}
	return;
}

void resolve(int m[]){

	string s;
	s = "123456789";

	mapa[s]= "";

	queue< pair < string, string >> fila;
	string s2;

	fila.push({s,s2});

	BFS(fila);
}

int main(){

	int m[9];
	resolve(m);

	while(scanf("%d %d %d",&m[0],&m[1],&m[2])==3){
		
		cont=0;
		scanf("%d %d %d %d %d %d",&m[3],&m[4],&m[5],&m[6],&m[7],&m[8]);

		string s2,s3;
		if(mapa.find(mForString(m)) == mapa.end()){
			cout << "Not solvable" << endl;
		}else{
			s3 = mapa[mForString(m)];
			reverse(s3.begin(),s3.end());
			cout << s3.size()/2 << " " << s3 << endl; 
		}
	}
}	