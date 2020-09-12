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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

vector<vector<int>> suc;
vector<vector<int>> sucInv;
vector<vector<int>> suc2;
vector<vector<int>> adj;

vector<pii> edge;
vector<int> tour;

int grau[MAXN], pos[MAXN];
bool vis[MAXN];
int raiz, cnt;

void montaSuc(int u){

    pos[u] = cnt++;
    
    for(auto i : adj[u]){
        tour.pb(i);
        montaSuc(i);
    }

    for(int i=pos[u];i<cnt-1;i++) suc2[u].pb(tour[i]);
}

bool sucIguais(){

    montaSuc(raiz);
    
    for(int i=0;i<N;i++){
        sort(all(suc[i]));
        sort(all(suc2[i]));

        if(suc[i] != suc2[i]) return false;
    }
  
    return true;
}

bool topoSort(){

    queue<int> fila;
    int cont = 0;

    FOR(i,0,N){
        if(!grau[i]){
            fila.push(i);
            cont++;
        }
    }

    if(N == 1) return !grau[0];
    if(cont == N) return false;

    while(!fila.empty()){
        int u = fila.front();
        raiz = u;
        fila.pop();

        int p = -1, menor = INF;

        for(auto i : sucInv[u]){
            if(grau[i] < menor){
                menor = grau[i];
                p = i;
            }
            grau[i]--;
        }

        if(p == -1) break;
        
        edge.pb(pii(p,u));
        adj[p].pb(u);

        if(!grau[p]) fila.push(p);
    }

    if(edge.size() != N-1 || !sucIguais() ) return false;
    else return true;
}

void print(bool x){
    if(x){ 
        cout << "YES\n";
        for(auto i : edge) cout << i.fi+1 << " " << i.se+1 << endl;
    }else{
        cout << "NO\n";
    }
}

void solve(){

    for(int i=0;i<N;i++) grau[i] = suc[i].size();

    for(int i=0;i<N;i++){
        for(int j : suc[i]){
            sucInv[j].pb(i);
        }
    }

    bool ans = topoSort();

    if(ans) print(1);
    else print(0);
}

int main(){

	optimize;
	
	cin >> N;

    suc.resize(N);
    sucInv.resize(N);
    suc2.resize(N);
    adj.resize(N);

    FOR(i,0,N){
        int a;
        cin >> a;

        suc[i].resize(a);

        FOR(j,0,a) {
            int b;
            cin >> b;
            b--;

            suc[i][j] = b;
        }
    }
    	
	solve();
    
	return 0;
}