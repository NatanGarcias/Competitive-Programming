#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ld long double 

#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff

int m,n,k;

struct Sensor{
    int x,y,d;
};

vector<Sensor> v;

//UnionFind by Rank
class UnionFind{
    private:
        vector<int> parent,rank;

    public:
        UnionFind(int n){
            //Inicia o vetor com o rank = 0 e todo mundo sendo seu pai
            
            rank.assign(n+1,0);
            parent.assign(n+1,0);

            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int i){
            while(i !=parent[i]) i = parent[i];
            return i;
        }

        bool sameSet(int i, int j){
            if(find(i) != find(j)) return false;
            return true;
        }

        void unir(int i, int j){
            int u = find(i);
            int v = find(j);

            if(u != v){
                if(rank[v] >= rank[u]){
                    if(rank[v] == rank[u])
                        rank[v]++;
                    parent[u] = v;
                }else 
                    parent[v] = u;
            }
        }
};

bool intercepta(int i, int j){

    ld dist = sqrt( (v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y) );

    if(dist <= (v[i].d + v[j].d)*1.0 )
        return true;
    return false;
}


int main(){

    cin >> m >> n >> k;

    for(int i=0;i<k;i++){
        Sensor s;

        cin >> s.x >> s.y >> s.d;

        v.push_back(s);
    }

    UnionFind UF(k);

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(intercepta(i,j)){
                UF.unir(i,j);
            }
        }
    }

    for(int i=0;i<k;i++){

        if(i == UF.find(i)){
            bool z[4] = {0};

            for(int j = 0; j < k; j++){
                
                if(UF.find(j) == i){
                    if(v[j].x - v[j].d <= 0)
                        z[0] = true;
                    if(v[j].y - v[j].d <= 0)
                        z[1] = true;
                    if(v[j].x + v[j].d >= m)
                        z[2] = true;
                    if(v[j].y + v[j].d >= n)
                        z[3] = true;
                }
            }

            if( (z[0] && z[1]) || (z[0] && z[2]) || (z[1] && z[3]) || (z[2] && z[3]) ){
                cout << 'N' << endl;
                return 0;
            }
        }
    }

    cout << 'S' << endl;

    return 0;
}