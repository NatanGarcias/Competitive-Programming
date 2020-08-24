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

#define mod 998244353LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

pii edge[MAXN];
int grau[MAXN];

struct UF{
    vector<int> parente, rank;
    
    UF(int n){
        parente.resize(n);
        iota(all(parente) , 0);

        rank.assign(n,0);
    }

    int find(int a){
        if(a != parente[a]) return parente[a] = find(parente[a]);
        return a;
    }

    bool sameSet(int a, int b){
        return find(a) == find(b);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(rank[a] < rank[b]) swap(a,b);
            if(rank[a] == rank[b]) rank[a]++;
            parente[a] = b;
        }
    }
};

void kruskral(){
    
    int c = 1;
    int i = 1;

    UF uf(N);

    grau[edge[0].fi]++;
    grau[edge[0].se]++;

    uf.merge(edge[0].fi,edge[0].se);

    while(c < N-1){
        if(!uf.sameSet(edge[i].fi,edge[i].se)){            
            grau[edge[i].fi]++;
            grau[edge[i].se]++;
            
            uf.merge(edge[i].fi,edge[i].se);
            c++;
        }
        i++;
    }

}

void solve(){

    sort(edge,edge+M);

    kruskral();
    
    int ans = 0;
    
    FOR(i,0,N) ans = max(ans , grau[i]);

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

    FOR(i,0,M){
        int a,b;
 
        cin >> a >> b;
        a--; b--;

        if(b > a) swap(a,b);

        edge[i].fi = a;
        edge[i].se = b;
    }

	solve();

	return 0;
}