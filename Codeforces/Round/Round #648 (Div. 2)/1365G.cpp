#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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

ll query(vector<ll> &aux){
    cout << '?';
    
    cout << " " << aux.size();
    for(auto i : aux) cout << " " << i+1;
    cout << endl;
    
    ll ans;
    cin >> ans;

    return ans;
}

void resp(vector<ll> &ans){
    cout << '!';
    for(auto i : ans) cout << " " << i;
    cout << endl;
}

int main(){

	cin >> N;

    vector<ll> nums;
    vector<ll> q;

    //Para cada possivel mascara
    for(ll i=0;i<(1 << 13);i++){
        ll cnt = 0, aux = 0;

        //Para cada mascara com 6 bits ligados
        for(ll j=0;j<13;j++) {
            if( i & (1 << j) ) {
                cnt++;
                aux = aux | (1 << j);
            }
        }
       
        if(cnt == 6) nums.pb(aux);

        if(nums.size() == N) break;
    }

    //Para cada mascara faço uma querie dos i-simos bits ligados
    for(ll i=0;i<13;i++){
        vector<ll> aux;

        for(ll j=0;j<N;j++) if(nums[j] & (1 << i)) aux.pb(j);
        
        if(aux.empty())     q.pb(0);
        else                q.pb( query(aux) );
    }

    //Aproveito da propriedade do OR
    //Então para cada posição, se aquele bit estiver desligado eu olho a querie responsável
    vector<ll> ans;
    for(ll i=0;i<N;i++){
        ll aux = 0;

        for(ll j=0;j<13;j++) if(! (nums[i] & (1 << j)) ) aux = aux | q[j];

        ans.pb(aux);
    }

    resp(ans);

	return 0;
}