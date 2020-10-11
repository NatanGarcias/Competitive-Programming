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

map<pii,set<pii> > mapa;

ll MDC(ll a, ll b) { return b ? MDC(b,a%b) : a; }

void solve(){

    ll ans = 0;

    for(auto &i : mapa){
        
        pii vet = i.fi;
        pii vetI = i.fi;

        swap(vetI.fi,vetI.se);
        vetI.fi *= -1;

        auto it = mapa.find(vetI);

        if(it != mapa.end())
            ans += (*it).se.size() * i.se.size();
    }

    cout << ans << endl;
}

pii vetD(int v[]){
    ll a = v[2] - v[0];
    ll b = v[3] - v[1];

    if( (a < 0 && b < 0) || (a > 0 && b < 0) ){
        a *= -1;
        b *= -1;
    }

    ll c = MDC(a,b);

    return pii(a/c,b/c);
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        mapa.clear();

        for(int i=0;i<N;i++){

            int v[4];

            for(int j=0;j<4;j++) cin >> v[j];

            pii aux = vetD(v);
            pii aux2;
            
            aux2.fi = v[1] * aux.fi - v[0] * aux.se;
            aux2.se = v[0] * aux.se - v[1] * aux.fi;
            
            mapa[ vetD(v) ].insert(aux2);
        }
        
		solve();
    }

	return 0;
}