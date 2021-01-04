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
#define MAXN 4020

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll A[MAXN];
vector<ll> resp;
int nums[MAXN], sum[MAXN];

void solve(){

    for(int i=0;i<N;i++) nums[A[i]]++;
    for(int i=1;i<MAXN;i++) sum[i] = sum[i-1] + nums[i];

    ll x = 0, y = 0;
    
    for(int i=0;i<N;i++){
        y = max(y, A[i]);
    }

    x = max(1LL ,y - N + 1);

    for(int i=x;i<y;i++){
        ll v = sum[i-1];
        ll ans = 1;

        bool ok = true;

        for(int j = i;j<i+N;j++){
            v += nums[j];

            if(!(v % M) ) ok = false;

            ans *= v;
            v--;
        }

        if(ok) resp.pb(i);
    }

    cout << resp.size() << endl;

    for(int i=0;i<resp.size();i++){
        if(!i)  cout << resp[i] ;
        else    cout << " " << resp[i] ;
    }   
    cout << endl;

}

int main(){

	optimize;
	
	cin >> N >> M;

    for(int i=0;i<N;i++) cin >> A[i];

	solve();
    
	return 0;
}