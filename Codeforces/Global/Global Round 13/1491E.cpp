#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<vector<pii>> adj;
pii edge;
int fib[MAXN], sz[MAXN], rem[MAXN], F;
bool ok;

void no(){
    cout << "NO\n";
    exit(0);
}

void preCalc(){
    fib[0] = fib[1] = 1;
    F = 1;

    for(int i=2;;i++){
        fib[i] = fib[i-1] + fib[i-2];

        if(fib[i] > N) break;

        F = i;
    }

    if(fib[F] != N) no();
}

void dfs(int u = 0, int p = 0){

    sz[u] = 1;

    for(auto i : adj[u]){
        if(i.fi != p && !rem[i.se]){
            dfs(i.fi, u);
            sz[u] += sz[i.fi];
        }
    }
}

void dfs2(int u, int p, int f, int t){

    if(ok) return;

    for(auto i : adj[u]){
        if(ok) return;
        
        int v = i.fi;
        int id = i.se;

        if(v == p || rem[id]) continue;
        
        if( min(t - sz[v], sz[v]) == fib[f-2] && max(t - sz[v], sz[v]) == fib[f-1] ){
            rem[id] = true;
            ok = true;

            edge = pii(u,v);

            if(sz[v] != fib[f-1]) edge = pii(v,u);
            
            return;
        }
        else{
            dfs2(v, u, f, t);
        }
    }
}

bool solve(int u, int f){
    if(f <= 1) return true;

    //Calculo o tamanho de cada sub-arvore dada as arestas que foremr retiradas 
    dfs(u,u);

    //Se achei alguma aresta candidata a ser a removida
    ok = false;
    
    //Procurando aresta a ser removida 
    dfs2(u, u, f, sz[u]);

    //Se tenho alguma aresta para remover, remove ela e vejo se funciona para as subárvores que ficaram
    if(ok){
        int v = edge.fi;
        int w = edge.se;

        return solve(v, f-2) && solve(w, f-1);
    }
    else{
        return false;
    }
}

int main(){

	optimize;
	
	cin >> N;

    adj.resize(N);

    preCalc();

    for(int i=0;i<N-1;i++){
        int a,b;

        cin >> a >> b;

        a--, b--;

        adj[a].pb(pii(b,i));
        adj[b].pb(pii(a,i));
    }
     
	if(solve(0, F))     cout << "YES\n";
    else                cout << "NO\n";

	return 0;
}