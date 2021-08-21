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
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

vector<vector<pair<int, string>>> adj;

struct compare{
  	bool operator()(const pair<pair<int, string>, pii > &l, const pair<pair<int, string>, pii > &r){
    	if(l.fi != r.fi) return l.fi > r.fi;
        return l.se > r.se;
  	}
};

auto dijkstra(int s, int t){

    vector<pair<pair<int, string>, int>> dist(N);
    vector<int> quem(N, -1);
    vector<bool> vis(N,  0);

    for(auto &i : dist){
        i.fi = {INF, ""};
        i.se = INF;
    }

    // Quantidade de caracteres, último caractere adicionado, tempo que foi adicionado e vértice que estou indo
    priority_queue<pair<pair<int, string>, pii >, vector<pair<pair<int, string>, pii > >, compare> pq;
    int tempo = 0;

    dist[s] = { {0, ""}, 0};
    pq.push({ {0, ""}, {0, s} });
    
    while(!pq.empty()){
        int d = pq.top().fi.fi + 1;
        int u = pq.top().se.se;
        
        pq.pop();

        tempo++;

        if(vis[u]) continue;
        vis[u] = true;
        
        for(auto [v, w] : adj[u]){
            bool ok = (d < dist[v].fi.fi || d == dist[v].fi.fi && w < dist[v].fi.se);
            
            if(ok){
                dist[v] = { {d, w}, tempo};
                quem[v] = u;

                pq.push({ { d, w}, {tempo, v} });
            }
        }
    }

    return quem;
}

void solve(){

    auto quem = dijkstra(N-1, 0);

    vector<int> ans;
    string str;

    int t = 0;
    ans.pb(t + 1);

    while(quem[t] != -1){
        
        for(auto [v, w] : adj[t]){
            if(v == quem[t]){
                str += w;
                break;
            }
        }

        t = quem[t];
        ans.pb(t + 1);
    }

    cout << ans.size() - 1 << endl;
    for(int i = 0; i < ans.size() ; i++){
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
    cout << str << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

    adj.resize(N);

    for(int i = 0, u, v; i < M; i++){
        string k;

        cin >> u >> v >> k;

        u--, v--;

        adj[u].pb({v, k});
        adj[v].pb({u, k});
    }	

	solve();
    
	return 0;
}