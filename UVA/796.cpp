#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

#define UNVISITED -1

int vertices,arestas;
int root, children;
int cont;

void tarjan(int u,vector<pair<int,int>>&pontes, vector<vector<int>> &adj,int low[], 
	int disc[], int parent[], bool articulacao[]){

	low[u] = disc[u] = cont++;
	
	for(int i=0;i<adj[u].size();i++){

		int v = adj[u][i];

		if(disc[v] == UNVISITED){
			parent[v] = u;

			if(u == root) children++;
			
			tarjan(v,pontes,adj,low,disc,parent,articulacao);

			if(low[v]>=disc[u]) articulacao[u] = true;

			if(low[v]>disc[u]) pontes.push_back({u,v});

			low[u] = min(low[u],low[v]); 
		}
		else if(v != parent[u]){
			low[u] = min(low[u],disc[v]);
		}
	}
}

void dfs(vector<pair<int,int>> &pontes, vector<vector<int>> &adj, int low[], 
	int disc[], int parent[], bool articulacao[]){

	f(i,vertices){
		
		if(disc[i] == UNVISITED){
			root = i;
			children = 0;
			tarjan(i,pontes,adj,low,disc,parent,articulacao);
			articulacao[root] = children>1; 
		}
	}	
}

int main(){
	int count=0;

	while(cin >> vertices){
		cont =0;
		int a,b,c;
		char k;

		int low[vertices];
		int disc[vertices];
		int parent[vertices];
		bool articulacao[vertices];

		memset(low,UNVISITED,sizeof low);
		memset(articulacao,0,sizeof articulacao);
		memset(disc,UNVISITED,sizeof disc);
		memset(parent,UNVISITED,sizeof parent);
		
		vector<vector<int>> adj(vertices);
		vector<pair<int,int>> pontes;

		f(j,vertices){
			cin >> a >> k >> arestas >> k;
			f(i,arestas){
				cin >> c;
				adj[a].push_back(c);
			}
		}

		dfs(pontes,adj,low,disc,parent,articulacao);

		cout << pontes.size() << " critical links" << endl;

		for(auto &i : pontes) {
			if(i.first > i.second)
				swap(i.first,i.second);
		}
		sort(pontes.begin(),pontes.end());
		for(auto i:pontes) cout << i.first << " - " << i.second << endl;
		cout << endl;
	}
}