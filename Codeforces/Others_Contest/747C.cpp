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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

struct Tar{
    int c,n,p;

    Tar() : c(0), n(0), p(0) {}
    Tar(int _c, int _n, int _p): c(_c), n(_n), p(_p) {}
};

Tar v[MAXN];
int vis[102];

ll sum(int q, int comeco, int tempo){
    
    ll aux = -1;
    vector<int> nums;
    
    FOR(i,0,N) if(vis[i] < comeco) nums.pb(i+1);

    if(sz(nums) >= q){
        aux = 0;
        FOR(i,0,q){
            vis[nums[i]-1] = comeco + tempo-1;
            aux += (nums[i]);
        }
    }

    return aux;
}

void solve(){

    FOR(i,0,M){
        int aux = sum(v[i].n, v[i].c, v[i].p);

        cout << aux << endl;
    }

}

int main(){

    cin >> N >> M;

    FOR(i,0,M){
        Tar aux;

        cin >> aux.c >> aux.n >> aux.p;

        v[i] = aux;
    }

    solve();

	return 0;
}