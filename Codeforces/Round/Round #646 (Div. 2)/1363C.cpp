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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<set<int>> adj;

void solve(){

    M--;

    if(adj[M].size() == 1 || N ==1) cout << "Ayush\n";
    else if( !((N-1) & 1) )    cout << "Ashish\n";
    else                   cout << "Ayush\n";

    return;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        adj.resize(N);

        for(int i=0;i<N-1;i++){
            int a,b;

            cin >> a >> b;

            a--, b--;

            adj[a].insert(b);
            adj[b].insert(a);
        }

		solve();

        for(int i=0;i<N;i++) adj[i].clear();
    }

	return 0;
}