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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

#define mod 1000000007LL
#define MAXN 30010
#define MAXM 200010
#define MAXL 1000100
const int t = 175;
int sum;

struct Query{
	int l, r, id;

    Query() {}
    Query(int _l, int _r, int _id) : l{_l}, r{_r}, id{_id} {}

    bool operator<(const Query &a) const{
	    if (l/t != a.l/t){
	    	if(l != a.l) return l < a.l; 
	        return r < a.r;
	    }

	    // Otimização dos ponteiros
	    return ( (l/t) & 1) ? (r < a.r) : (r > a.r);
	}
};

int v[MAXN], vis[MAXL], ans[MAXM];
Query Q[MAXM];

void add(int pos) {
    if(vis[ v[pos] ] == 0) sum++;
    vis[ v[pos] ]++;
}

void remove(int pos) {
    if(vis[ v[pos] ] == 1) sum--;
    vis[ v[pos] ]--;
}

void MO(){
	sort(Q, Q+M);

	int lMO=0, rMO=-1, l, r;
	
	// [lMO, rMO]
	for(int i=0; i<M; i++) {
		l = Q[i].l;
		r = Q[i].r;

		while(rMO < r) add(++rMO);
		while(lMO > l) add(--lMO);
		while(rMO > r) remove(rMO--);
		while(lMO < l) remove(lMO++);

		//(lMO == l) e (rMO == r)
		ans[Q[i].id] = sum;
	}
}

int main(){

    optimize;

	cin >> N;
    
    FOR(i,0,N) cin >> v[i];

    cin >> M;
    
    FOR(i,0,M){
        int a,b;

        cin >> a >> b;

        a--, b--;

        Q[i].l = a;
        Q[i].r = b;
        Q[i].id = i;
    }

	MO();

    FOR(i,0,M){
        cout << ans[i] << "\n";
    }

	return 0;
}