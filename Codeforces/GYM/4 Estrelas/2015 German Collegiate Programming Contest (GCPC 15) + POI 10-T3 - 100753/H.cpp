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
#define MAXN 2020

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<vector<int>> adj;
map<string,int> m;
int vis[MAXN], cnt;
string t = "::PROGRAM";

void bfs(){
    queue<int> fila;

    for(auto i : m){
        string s3;

        if(i.fi.find(t) != std::string::npos){
            
            bool ok = true;

            for(int j=i.fi.size()-9, k = 0; j < i.fi.size() ;j++, k++){
                if(i.fi[j] != t[k]) ok = false;
            }

            if(ok){
                fila.push(i.se);
                vis[i.se] = true;
            }
        }
    }

    while(!fila.empty()){
        int v = fila.front();

        fila.pop();

        for(int i : adj[v]){
            if(!vis[i]) {
                vis[i] = true;
                fila.push(i);
            }
        }
    }

}

void solve(){

    bfs();

    int aux = 0;

    for(int i=0;i<cnt;i++){
        if(!vis[i]) aux++;
    }

    cout << aux << endl;
}

int main(){

	optimize;

	cin >> N;

    adj.resize(2*N);

    for(int i=0;i<N;i++){
        string s;
        int a, u;

        cin >> s >> a;

        if(m.find(s) == m.end()) {
            u = cnt;
            m[s] = cnt++;
        }
        else {
            u = m[s];
        }

        for(int j=0;j<a;j++){
            string s2;
            int v;

            cin >> s2;

            if(m.find(s2) == m.end()) {
                v = cnt;
                m[s2] = cnt++;
            }
            else {
                v = m[s2];
            }

            adj[v].pb(u);
        }
    }

	solve();
    
	return 0;
}