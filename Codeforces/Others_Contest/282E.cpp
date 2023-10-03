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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN];

const int t = 2;
const int desl = 40;
int z;
const char desc = '0';

struct Node{
	vector<int> p;

	Node(){
		p.assign(t, -1);
	}
};

vector<Node> trie(1);

string base2(ll x){
	string aux;

	for(int i=desl;i>=0;i--) {
		if( (x & (1LL << i)) )  aux.pb('1');
		else 					aux.pb('0');	
	}

	return aux;
}

void add(ll x){

	string str = base2(x);

	int u = 0;

	for(int i=0;i<str.size();i++){
		int c = str[i] - desc;

		if(trie[u].p[c] == -1){
			trie[u].p[c] = ++z;
			trie.emplace_back();
		}

		u = trie[u].p[c];
	}
}

ll query(ll x){

	string str = base2(x);

	ll ans = 0;
	int u = 0;

	for(int i=0;i<str.size();i++){
		int c = str[i] - desc;

		if(!c){
			if(trie[u].p[1] != -1) {
				ans += (1LL << (desl - i));
				u = trie[u].p[1];
			}
			else u = trie[u].p[0];
		}
		else{
			if(trie[u].p[0] != -1) {
				ans += (1LL << (desl - i));
				u = trie[u].p[0];
			}
			else u = trie[u].p[1];
		}
	}

	return ans;
}

void solve(){

	vector<ll> vai(N+1,0), vem(N+1,0);

	for(int i=1;i<=N;i++) vai[i] = vai[i-1] ^ A[i-1];
	for(int i=N-1;i>=0;i--) vem[i] = vem[i+1] ^ A[i];

	ll ans = 0;

	add(0);

	for(int i=0;i<N;i++){
		ans = max(ans, query(vem[i]));

		add(vai[i]);
	}

	ans = max(ans, query(0LL));

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;

	for(int i=0;i<N;i++) cin >> A[i];

	solve();
    
	return 0;
}