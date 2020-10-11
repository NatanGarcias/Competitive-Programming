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
    ll l,r,c,id;

    Evento () {}
    Evento (ll _l , ll _r, ll _c, ll _id = 0) : l(_l), r(_r), c(_c) {}

    bool operator<(const Evento &a) const{
        if(l != a.l) return l < a.l;
        return r < a.r;
    }

};

Evento v[MAXN];
ll sum[MAXN];

void pre(){
    
    sort(v, v+N+2);

    sum[0] = 0;

    for(int i=1;i<N+2;i++){
        sum[i] = sum[i-1] + (v[i].r - v[i].l + 1) * v[i].c ;
        v[i].id = i;
    }

}

void solve(){

    ll ans = 0, aux, aux2;
    
    for(int i=1;i<N+1;i++){

        ll l = v[i].l, r = v[i].r, c = v[i].c, id = v[i].id;

        aux = 0, aux2 = 0;

        //Indo
        if(r - l + 1 >= M){
            aux = M * c;
        }
        else{
            ll pos = l+M-1;

     		auto it = upper_bound( v, v+N+2 , Evento(pos,INF, 0));

			--it;

     		ll l2 = (*it).l, r2 = (*it).r, c2 = (*it).c, id2 = (*it).id;

            aux = sum[ id2 - 1 ] - sum[ id - 1 ];
      		aux +=  min( ( pos - l2 + 1 ) * c2 , ( r2 - l2 + 1 ) * c2 );
        }

      	ans = max( ans , aux );

        //Voltando        
        if(r - l + 1 >= M) continue;
        else{
            if(r-M+1 <= (v[1].l)){
                aux2 = sum[ i ];
            } 
            else{
                ll pos = r-M+1;

                auto it = upper_bound( v, v+N+2 , Evento(pos, INF, 0));

                --it;

                ll l2 = (*it).l, r2 = (*it).r, c2 = (*it).c, id2 = (*it).id;

                aux2 = sum[ i ] - sum[ id2 ];

                aux2 +=  min( ( r2 - pos + 1 ) * c2 , ( r2 - l2 + 1 ) * c2 );
            }   
        }
        ans = max( ans , aux2 );
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
    scanf("%lld", &T);

    while(T--){

        scanf("%lld %lld", &N, &M);

        v[0] = Evento(-INF,-INF, 0);
        v[1] = Evento( INF, INF, 0);

        for(int i=2;i<N+2;i++){
            ll a,b,c;
            scanf("%lld %lld %lld", &a, &b, &c);

            v[i].l = a;
            v[i].r = b;
            v[i].c = c;  
        }
        
        pre();
        solve();
    }

	return 0;
}