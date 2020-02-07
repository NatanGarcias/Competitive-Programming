#include<bits/stdc++.h>
using namespace std;

int main (){
	int a;
	scanf("%d\n\n",&a);
	for(int i=0;i<a;i++){
		if(i)
			cout << endl;
		char tamanho;
		scanf("%c",&tamanho);
		cin.ignore();
		int vetor[tamanho-64] = {0};
		vector< vector<char> >matriz(tamanho-64);
		string s;
		while(getline(cin,s)){
			if(s.empty())
				break;
			char x = s[0];
			char y = s[1];
			matriz[x-65].push_back(y);
			matriz[y-65].push_back(x);
		}
		int cont =0;
		while(true){
			int j;
			bool sair=true;
			for(j=0;j<tamanho-64;j++){
				if(vetor[j]==0){
					sair=false;
					break;
				}
			}
			if(sair)
				goto x;
			char chama(j+65);
			queue<char> fila;
			fila.push(chama);
			vetor[chama-65]=1;
			while(!fila.empty()){
				for(int k=0;k<matriz[chama-65].size();k++){
					int onde = (matriz[chama-65][k]-65); 
					if(vetor[onde]!=1){
						fila.push(matriz[chama-65][k]);
						vetor[matriz[chama-65][k]-65]=1;
					}
				}
				fila.pop();
				chama = fila.front();
			}
			cont++;
		}
		x:
		cout << cont << endl;
		int faznada;
	}
}