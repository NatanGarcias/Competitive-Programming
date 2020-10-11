#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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

struct Evento{
    ll l, r, c, id;
    
    Evento() {}
    Evento(ll _l,  ll _r, ll _c, ll _id) : l(_l), r(_r), c(_c), id(_id) {}

    bool operator<(const Evento &a) const{
        if(l != a.l) return l < a.l;
        if(r != a.r) return r < a.r;
        if(c != a.c) return c > a.c;
        return id < a.id;
    }
};

vector<Evento> evento;
pii dp[MAXN];
int prox[MAXN];
bool vis[MAXN];

pii solve(int i){

    if(i == N) return pii(0,0);
    else if(dp[i].fi == -1){
        ll t = evento[i].r - evento[i].l;
        
        pii aux = solve(prox[i]);
        pii aux2 = solve(i+1);

        aux.fi += evento[i].c;
        aux.se -= t;
        
        if(aux > aux2){
            dp[i] = aux;
            vis[i] = true;
        }
        else{
            dp[i] = aux2;
        }
    } 

    return dp[i];
}

void solve(){

	ms(dp, -1);

    sort( all(evento) );

    for(int i=0;i<N;i++){
        prox[i] = lower_bound( all(evento), Evento(evento[i].r, -INF, 0, 0) ) - evento.begin();
    }

    pii ans = solve(0);
    pii val = dp[0];
    vector<int> resp;

    for(int i=0;i<N;i++){
        if(vis[i]){
            resp.push_back(evento[i].id);
            i = prox[i]-1;
        }
    }

    cout << resp.size() << " " << dp[0].fi << " " << -dp[0].se << endl;
    for(int i=0;i<resp.size();i++) cout << resp[i] << " \n"[i==resp.size()-1];
}

int main(){

    optimize;
	
	cin >> N;

    evento.resize(N);

    for(int i=0;i<N;i++){
        ll a, b, c;

        cin >> a >> b >> c;

        evento[i] = Evento(a,b,c,i+1);
    }
		
	solve();

	return 0;
}