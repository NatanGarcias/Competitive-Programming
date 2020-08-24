#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define sz(x) (int)(x.size())
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define MAXN 1010

int T,N,M;
int v[MAXN];

vector<vector<int>> inter;

bool verifica(){
    FOR(i,M){
        if(v[i]){
            return false;
        }
    }
    return true;
}

void atualiza(int x){
    FOR(i,sz(inter[x])){
        v[ inter[x][i] ] = !v[ inter[x][i] ];
    }
}

int main(){

    optimize;

	cin >> N >> M;

    cin >> T;

    int a;
    
    FOR(i,T){
        cin >> a;

        v[--a] = true;
    }

    inter.resize(N);

    FOR(i,N){
        cin >> a;

        inter[i].resize(a);

        FOR(j,a){
            cin >> inter[i][j];
            inter[i][j]--;
        }
    }

    int cont = 0;
    
    if(verifica()){
        cout << cont << endl;
        return 0;
    }

    while(cont++ < N*2+2){
        
        atualiza((cont-1)%N);

        if(verifica()){
            cout << cont << endl;
            return 0;
        }   
    }

    cout << -1 << endl;

	return 0;
}