#include<bits/stdc++.h>
using namespace std;
    

int s,n;

struct Ponto{
    long double x,y;
};

// Struct utilizada no sort  para ordenar pelo menor peso
bool compare(const tuple<long double,int,int>& l, const tuple<long double,int,int>& r){
      long double a = get<0>(l);
      long double b = get<0>(r);
      return  a < b ;
}

//Classe Union Find
class UnionFind{
public:
    vector<int> parent,rank;

    UnionFind(int n){
        //Inicia o vetor de rank com 0 em todas as posições e parent[i] = i
        rank.assign(n+1,0);
        parent.assign(n+1,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int i){
        // retorna o representante do conjunto a qual i pertença
        while(i != parent[i]) i = parent[i];
        return i;
    }

    //Verifica se dois vertices estão no mesmo conjunto
    bool mesmoConjunto( int i, int j){
        if(find(i) == find(j)) return true;
        else return false;
    }

    void juntaVertices(int i, int j){
        int u = find(i);
        int v = find(j);

        // Se o dois vertices já estão no mesmo conjunto retorna 
        if(mesmoConjunto(u,v)) return;

        //Caso não esteja liga o vertice de menor conjunto no de maior conjunto
        if(rank[u] > rank[v]){
            parent[v] = u;
            rank[u]++;
        }else{
            parent[u] = v;
            rank[v]++;
        }
    }
};

// Dist entre dois vertices 
long double dist(Ponto &e, Ponto &f){
    return sqrt((e.x-f.x)*(e.x-f.x) + (e.y-f.y)*(e.y-f.y));
}

// Prenche a matriz de adjacencia
void dist( vector<vector<long double>> &adj, vector<Ponto> &posicoes){

    int n = adj.size();

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long double temp = dist(posicoes[i],posicoes[j]);
            adj[i][j] = adj[j][i] = temp;
        }
    }
}

//kruskral
void kruskral( vector<vector<long double>> &adj, vector<Ponto> &posicoes){

    int n = adj.size();
    int custoTotal =0;
    int cont=0;
    int k=0;
    
    vector<tuple<long double,int,int>> v;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v.push_back({adj[i][j],i,j});
        }
    }

    sort(v.begin(),v.end(),compare);

    UnionFind uf(n);

    while(cont != n-1){

        long double cost = get<0>(v[k]);
        int u = get<1>(v[k]);
        int t = get<2>(v[k++]);
        
        if(!uf.mesmoConjunto(u,t)){
            

            if(cont == n-s-1){
                cout << fixed << setprecision(2) << cost << endl;
                break;
            }   
            custoTotal+= cost;
            uf.juntaVertices(u,t);

            cont++;
        }
    }

}

int main(){

	int casos;
    cin >> casos;

    while(casos--){
        

        cin >> s >> n;

        vector<Ponto> posicoes(n);

        for(int i=0;i<n;i++){
            cin >> posicoes[i].x;
            cin >> posicoes[i].y;
        }

        vector<vector<long double>> adj(n,vector<long double>(n));

        dist(adj,posicoes);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        kruskral(adj,posicoes);
    }
}	