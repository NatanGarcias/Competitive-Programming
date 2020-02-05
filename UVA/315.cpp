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

	while(cin >> vertices){
		if(!vertices)
			return 0;
		
		int low[vertices];
		int disc[vertices];
		int parent[vertices];
		bool articulacao[vertices];

		memset(low,UNVISITED,sizeof low);
		memset(disc,UNVISITED,sizeof disc);
		memset(parent,UNVISITED,sizeof parent);
		memset(articulacao,0,sizeof articulacao);
		
		vector<vector<int>> adj(vertices);
		vector<pair<int,int>> pontes;
		
		int c,d;
		string s;

		cin.ignore();
			
		while(getline(cin,s)){
			stringstream ss;
			ss << s;
			if(s[0]=='0')
				break;
			ss >> c;
			c--;
			while(ss >> d){
				d--;
				adj[c].push_back(d);
				adj[d].push_back(c);
			}
		}

		cont =0;
		dfs(pontes,adj,low,disc,parent,articulacao);

		int quantos=0;
		f(i,vertices) 
			if(articulacao[i])
				quantos++;
		cout << quantos << endl;
	}
}