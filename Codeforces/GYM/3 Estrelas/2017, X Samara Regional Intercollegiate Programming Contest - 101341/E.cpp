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
ll t[MAXN], b[MAXN];

ll caminho(vector<ll> &nums, ll x, ll x2){

    ll n = nums.size();
    vector<ll> vai(n+2), vem(n+2);
    vai[0] = 0, vem[0] = x2 - x;
    vai[n+1] = x2 - x, vem[n+1] = 0;

    for(int i=0;i<n;i++) {
        if(!i)  vai[i+1] = nums[i] - x;
        else    vai[i+1] = vai[i] + nums[i] - nums[i-1];
    }

    for(int i=n-1;i>=0;i--) {
        if(i == n-1)    vem[i+1] = x2 - nums[i];
        else            vem[i+1] = vem[i+2] + nums[i+1] - nums[i];
    }

    ll ans = x2 - x;

    for(int i=0;i<n+2;i++){
        if(!i) {
            ll aux = (vai[i] + vem[i+1]) * 2LL;
            if(aux < ans) ans = aux;
        }
        else if(i == n+1){
            ll aux = (vai[i-1] + vem[i]) * 2LL;
            if(aux < ans) ans = aux;
        }
        else{
            ll aux = (vai[i] + vem[i+1]) * 2LL;
            if(aux < ans) ans = aux;

            ll aux2 = (vai[i-1] + vem[i]) * 2LL;
            if(aux2 < ans) ans = aux2;
        }
    }

    return ans;
}

void solve(){

    int ptrb = 0, ptrb2 = M-1, ptrt = 0;
    ll ans = 0;

    //Valores que vem antes do primeiro teletransporte
    if(t[0] > b[ptrb])   ans += (t[0] - b[0]) * 2LL;

    while(ptrb < M && t[0] >= b[ptrb]) ptrb++;

    //Valores que vem depois do último teletransporte
    if(b[M-1] > t[N-1])     ans += (b[M-1] - t[N-1]) * 2LL;
    
    while(ptrb2 >= 0 && b[ptrb2] >= t[N-1]) ptrb2--;

    //Meio
    while(ptrb <= ptrb2){
        ll p = t[ptrt], p2 = t[ptrt +1];

        vector<ll> nums;

        while(ptrb <= ptrb2 && b[ptrb] <= p2){
            nums.push_back(b[ptrb++]);
        }

        if(!nums.empty()) ans += caminho(nums, p ,p2);

        ptrt++;
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

    for(int i=0;i<N;i++) cin >> t[i];
    for(int i=0;i<M;i++) cin >> b[i];
	
    solve();
    
	return 0;
}