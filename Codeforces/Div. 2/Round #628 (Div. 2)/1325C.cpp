#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007
#define MAXN 200010

int T,N,M;
string S;
vector<vector<int>> adj;
vector<int> altura;

set<int> folhas;

vector<pii> edges;

void solve(){

    FOR(i,T){
        if(adj[i].size() == 1){
           folhas.insert(i); 
        }
    }

    vector<int> sol(T-1,-1);

    int cont = 0;

    FOR(i,T-1){
        if(folhas.find(edges[i].fi) != folhas.end() ||  folhas.find(edges[i].se) != folhas.end()){
            sol[i] = cont++;
        }
    }

    FOR(i,T-1){
        if(sol[i] == -1){
            sol[i] = cont++;
        }
    }

    FOR(i,T-1){
        cout << sol[i] << endl;
    }

}

int main(){

	cin >> T;

    adj.resize(T);
    altura.resize(T);

    FOR(i,T-1){
		cin >> N >> M;

        edges.push_back({N-1 , M-1});

        adj[N-1].pb(M-1);
        adj[M-1].pb(N-1);
	}

    solve();

	return 0;
}