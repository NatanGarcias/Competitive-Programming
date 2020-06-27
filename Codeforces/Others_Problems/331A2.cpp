#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
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

#define mod 1000000007LL
#define MAXN 300010

ll T,N,M,K;
ll v[MAXN];
int v2[MAXN];

void solve(){

    map<int,pii> mapa;

    ll sum = 0;    

    FOR(i,0,N){
        cin >> v2[i];

        if(mapa.find(v2[i]) == mapa.end()){
            mapa[ v2[i] ] = pii(i,-1);
        }else{
            auto it = mapa[ v2[i] ];
            mapa[ v2[i] ] = pii( it.first , i);
        }

        if(v2[i] > 0LL) sum += v2[i];

        v[i] = sum;
    }

    ll ans = -INFLL;
    int ptr = 0, ptr2 = 0;
    
    for(auto i : mapa){
        if( i.se.se != -1){
            ll aux = 2*i.fi + ( v[i.se.se -1] - v[i.se.fi] );
            if(ans < aux){
                ptr = i.se.fi;
                ptr2 = i.se.se;
                ans = aux;
            }
        }
    }
    
    vector<int> resp;
    
    FOR(i,0,ptr) resp.push_back(i);
    FOR(i,ptr+1,ptr2) if(v2[i] < 0) resp.pb(i);
    FOR(i,ptr2+1,N) resp.push_back(i);

    cout << ans << " " << sz(resp) << endl;

    FOR(i,0,sz(resp)) cout << resp[i]+1 << " \n"[i== sz(resp)-1];

}

int main(){

    cin >> N;

    
    solve();

	return 0;
}