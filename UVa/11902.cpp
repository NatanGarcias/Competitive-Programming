#include<bits/stdc++.h>
using namespace std;

void BEP(const vector<vector<int>>& matriz, vector<bool> &visitei, int deOnde){
	visitei[deOnde] = true;
	for(int i=0;i<matriz[deOnde].size();i++){
		if(matriz[deOnde][i]){
			if(!visitei[i])
				BEP(matriz,visitei,i);	
		}
	}
}
int main (){
	int a;
	int cont=0;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		int b;
		scanf("%d",&b);
		vector< vector<int> > matriz(b,vector<int>(b,0));
		for(int j=0;j<b;j++)
			for(int k=0;k<b;k++)
				cin >> matriz[j][k];

		vector< vector<bool> > v(b,vector<bool>(b,0));
		vector<bool> visited(b,0);
		BEP(matriz,visited,0);
		for(int j=0;j<b;j++){
			vector<bool> aux(b,0);
			vector<bool> aux1(b,0);
		
			vector<bool> visited2(b,0);

			for(int k=0;k<b;k++){
				aux[k] = matriz[j][k];
				aux1[k] = matriz[k][j];
				matriz[j][k] = 0;
				matriz[k][j] = 0;
			} 
			BEP(matriz,visited2,0);
			for(int k=0;k<b;k++){
				if(visited[k] && !visited2[k])
					v[j][k] = true;
				matriz[j][k] = aux[k];
				matriz[k][j] = aux1[k];
			}
		}
		v[0][0] = true;
		cout << "Case " << ++cont << ":" << endl;
		printf("%c",'+');
			for(int k=0;k<2*b-1;k++)
				printf("%c",'-');
		printf("%c\n",'+');
		for(int j=0;j<b;j++){
			cout << '|';
			for(int k=0;k<b;k++){
				if(v[j][k])
					cout << "Y|";
				else
					cout << "N|";
			}
			cout << endl;
			printf("%c",'+');
			for(int k=0;k<2*b-1;k++)
				printf("%c",'-');
			printf("%c\n",'+');
		}
	}
}
