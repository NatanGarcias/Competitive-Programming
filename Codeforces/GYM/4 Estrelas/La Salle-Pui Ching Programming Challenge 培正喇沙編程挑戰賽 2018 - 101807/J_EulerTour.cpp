#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

// #define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

int T,N,M,K;

pii aresta[MAXN];
string ans;

vector<vector<pii>> adj;
int bit[MAXN], val[MAXN];

int in[MAXN], out[MAXN], cnt;

void update(int x, int valor){
    for(;x < MAXN; x += x&-x) bit[x] += valor;
}

int query(int x){

    int sum = 0;

    for(;x > 0; x -= x&-x)  sum += bit[x];

    return sum;
}

int queryI(int a, int b){
    return query(b) - query(a);
}

void dfs(int u, int p){

	in[u] = ++cnt;

	for(pii i : adj[u]){
        int v = i.fi;
        int w = i.se;

		if(v != p){
            val[v] = w;
			dfs(v,u);
		}
	}

	out[u] = cnt;
}

void solve(){

    cin >> M;

    string str = "WE NEED BLACK PANDA\n";
    string str2 = "JAKANDA FOREVER\n";
    
    dfs(1, 0);
    
    for(int i=1;i<=N;i++){
        update(in[i], val[i]);
        update(out[i] + 1, -val[i]);
    }

    for(int i=0;i<M;i++){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        if(a == 1){
            if(in[b] > in[c]) swap(b,c);

            int aux = queryI(in[b], in[c]);

            if( (aux & 1) ) ans += str;
            else            ans += str2;
        }
        else{
            b--;

            pii aux = aresta[b]; 

            if(in[aux.fi] < in[aux.se]) swap(aux.fi, aux.se);

            b = aux.fi;

            c = (c&1);

            if(val[b] != c){
                update(in[b],   1);
                update(out[b] + 1, -1);

                val[b] = c;
            }
            
        }
    }

    printf("%s", ans.c_str());
}

int main(){
    
    scanf("%d", &N);
    
    adj.resize(N + 1);

    for(int i=0;i<N-1;i++){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        c = (c&1);

        aresta[i] = pii(a,b);
        adj[a].pb(pii(b,c));
		adj[b].pb(pii(a,c));
    }

	solve();
    
	return 0;
}