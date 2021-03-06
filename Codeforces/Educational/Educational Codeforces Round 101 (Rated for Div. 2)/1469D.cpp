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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

bool pos[MAXN];

void pre(){
	pos[2] = true;
	pos[4] = true;
	pos[16] = true;
	pos[256] = true;
	pos[65536] = true;
	pos[200000] = true;
	pos[N] = true;
}

void solve(){

	vector<pii> resp;
	vector<int> nums;

	resp.reserve(N+5);

	for(int i=2;i<=N;i++){
		if(!pos[i]) resp.pb(pii(i,N));
		else{
			nums.pb(i);
		}
	}

	while(nums.size() > 1){
		int u = nums.back();
		nums.pop_back();

		resp.pb(pii(u,nums.back()));
		resp.pb(pii(u,nums.back()));
	}

	cout << resp.size() << endl;
	for(int i=0;i<resp.size();i++) cout << resp[i].fi << " " << resp[i].se << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;
		
		pre();
		
		solve();

		pos[N] = false;
    }

	return 0;
}