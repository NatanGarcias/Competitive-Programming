#include<bits/stdc++.h>
using namespace std;

int b(const vector<vector< pair<int,int> > > &v, int bombas[], int visited[], int distancia[], int a, int chegada,priority_queue<pair<int,int>>&fila){
	while(!fila.empty()){
		a = fila.top().second;
		visited[a] = 2;
		fila.pop();
		
		for(int i=0;i<v[a].size();i++){
			if(visited[ v[a][i].first ] != 2){
				int k =  distancia[ v[a][i].first ];
				int k1 = (distancia[a]+ v[a][i].second);
				distancia[ v[a][i].first ] = k<k1?k:k1;
				if( distancia[ v[a][i].first ] < bombas[ v[a][i].first])
					fila.push({ -distancia[ v[a][i].first ], v[a][i].first});
				if(v[a][i].first == chegada)
					return distancia[chegada];
			}
		}
	}
	return 0;
}

bool dijkstra(const vector<vector< pair<int,int> > > &v, int bombas[], int visited[], int distancia[], int inicio, int chegada){
	priority_queue< pair<int,int>> fila;
	fila.push({0,inicio});
	cout << b(v,bombas,visited,distancia,inicio,chegada,fila) << "\n";
}

int main(){
	int a,b,c,d;

	while(cin >> a >> b >> c >> d){
		if(a==0)
			break;
		
		int bombas[a+1];
		int visited[a+1]= {0};
		int distancia[a+1];
		for(int i=1;i<=a;i++){
			cin >>bombas[i];
			distancia[i] = 10E6;
			if(bombas[i] ==0)
				bombas[i] = 10E8; 
		}
		distancia[c] =0;

		vector<vector< pair<int,int> > > v(a+1);
		int saida,chegada,tempo;
		for(int i=0;i<b;i++){
			cin >> saida >> chegada >> tempo;
			v[saida].push_back({chegada,tempo});
			v[chegada].push_back({saida,tempo});
		}
		
		dijkstra(v,bombas,visited,distancia,c, d);

	}
}