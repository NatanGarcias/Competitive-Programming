#include<bits/stdc++.h>
using namespace std;
    int total=0;

// Struct utilizada na priority_queue para ordenar pelo menor peso
struct compare{
  bool operator()(const tuple<int,int,int>& l, const tuple<int,int,int>& r){
      int a = get<0>(l);
      int b = get<0>(r);
      return  a > b ;
  }
};

// Dist entre dois vertices 
int dist(string &e, string &f){

    int total = 0;

    for(int i=0;i<4;i++){
        
        int c = (int) abs((e[i]-'0') - (f[i]-'0'));
    
        if(c > 5)
            total+= 10 - c;
        else
            total+= c;
    }
    return total;

}

// Prenche a matriz de adjacencia
void dist( vector<vector<int>> &adj, vector<string> &chaves){

    int a = adj.size();

    for(int i=0;i<a;i++){
        for(int j=i;j<a;j++){
            int temp = dist(chaves[i],chaves[j]);
            adj[i][j] = adj[j][i] = temp;
        }
    }
}

//Prim
void prim( vector<vector<int>> &adj, vector<string> &chaves){

    int a = adj.size();
    int custoT=0;

    vector<int> vis(a,false);
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,compare> pq;

    int minimo = 10000000;

    string z = "0000";

    int quem = 0;

    for(int i=0;i<a;i++){
        int k = dist(z,chaves[i]);
        
        if( minimo > k){
            minimo = k;
            quem = i;
        }
    }

    vis[quem] = true;

    int cont = 0;

    while(cont++ != a-1){

        for(int i=0;i<a;i++)
            if(!vis[i] && quem != i)
                pq.push({adj[quem][i],quem,i});

        int vA,vB, custo;

        // Pega a aresta mais barata
        vA = get<1>(pq.top());
        vB = get<2>(pq.top());
        custo = get<0>(pq.top());
        pq.pop();

        while(vis[vB]){// Caso aquela aresta liga dois vertices que já estão na arvore
            vA = get<1>(pq.top());
            vB = get<2>(pq.top());
            custo = get<0>(pq.top());
            pq.pop();
        }

        //Add a aresta ao custo total da arvore
        custoT+= custo;
        quem = vB;
        vis[vB] = true;
    }
    //Imprimi o custo total
    cout << custoT+minimo << endl;
}

int main(){

	int casos;
    cin >> casos;

    while(casos--){
        
        int a,b;

        cin >> a;

        vector<string> chaves(a);

        for(int i=0;i<a;i++){
            cin >> chaves[i];
        }

        vector<vector<int>> adj(a,vector<int>(a));

        dist(adj,chaves);

        prim(adj,chaves);
    }
}	