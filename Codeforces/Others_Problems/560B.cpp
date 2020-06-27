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
int v[MAXN];

bool f(){
	if(max(v[0],v[2]) <= N && v[1]+v[3] <= M) return true;
	if(max(v[0],v[2]) <= M && v[1]+v[3] <= N) return true;
	if(v[0]+v[2] <= M && max(v[1],v[3]) <= N) return true;
	if(v[0]+v[2] <= N && max(v[1],v[3]) <= M) return true;

	if(max(v[0],v[3]) <= N && v[2]+v[1] <= M) return true;
	if(max(v[0],v[3]) <= M && v[2]+v[1] <= N) return true;
	if(v[0]+v[3] <= M && max(v[2],v[1]) <= N) return true;
	if(v[0]+v[3] <= N && max(v[2],v[1]) <= M) return true;

	return false;
}

void solve(){	

	bool ans = 0;
	ans = f();

	if(ans){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}

int main(){

	cin >> N >> M;

	FOR(i,0,4) cin >> v[i];

	solve();

	return 0;
}