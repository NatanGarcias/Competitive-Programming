#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll T,N,M,K;
vector<vector<int>> adj;
pii nums[MAXN];
int vis[MAXN];
map<int,int> mapa;

bool verifica(int u, int n){

    set<int> s;

    for(auto i : adj[u]){
        if(vis[i]){
            int aux = mapa[i];
            
            if(aux == n) {
                return false;
            }

            if(aux < n) s.insert(aux);
        }
    }

    if(s.size() != n-1){
        return false;
    }

    int cont = 1;
    for(auto i : s){
        
        if(i!= cont){
            return false;
        }
        cont++;
    }

    return true;
}

void solve(){

    sort(nums,nums+N);

    FOR(i,0,N) {
        vis[ nums[i].se ] = true;
        
        bool aux = verifica(nums[i].se,nums[i].fi);

        if(!aux){
            cout << -1 << endl;
            return;
        }
    }

    FOR(i,0,N){
        cout << nums[i].se+1 << " \n"[i==N-1];
    }
}

int main(){

    optimize;

    cin >> N >> M;

    adj.resize(N);

    FOR(i,0,M){
        int a,b;
        
        cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }    


    FOR(i,0,N){
        cin >> nums[i].fi;
        nums[i].se = i;

        mapa[i] = nums[i].fi;
    }

    solve();

	return 0;
}