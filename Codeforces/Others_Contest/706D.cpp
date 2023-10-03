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

const int t = 2;
int z;
const char desc = '0';

struct Node{
	vector<int> p,q;
	int f;

	Node(){
		p.assign(t, -1);
		q.assign(t, 0);
		f = 0;
	}
};

vector<Node> trie(1);

string base2(ll x){
	string aux;

	for(int i=60;i>=0;i--) {
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

		trie[u].q[c]++;
		u = trie[u].p[c];
	}

	trie[u].f++;
}

void remove(ll x){

	string str = base2(x);

	int u = 0;

	for(int i=0;i<str.size();i++){
		int c = str[i] - desc;

		trie[u].q[c]--;
		u = trie[u].p[c];
	}

	trie[u].f--;
}

ll query(ll x){

	string str = base2(x);

	ll ans = 0;
	int u = 0;

	for(int i=0;i<str.size();i++){
		int c = str[i] - desc;

		if(!c){
			if(trie[u].q[1]) {
				ans += (1LL << (60 - i) );
				u = trie[u].p[1];
			}
			else if(trie[u].q[0]) u = trie[u].p[0];
			else return -1;
		}
		else{
			if(trie[u].q[0]) {
				ans += (1LL << (60 - i) );
				u = trie[u].p[0];
			}

			else if(trie[u].q[1]) u = trie[u].p[1];
			else return -1;
		}
	}

	return ans;
}

void solve(){

	add(0);

	for(int i=0,u;i<N;i++){
		char k;
		
		cin >> k >> u;

		if(k == '+'){
			add(u);
		}
		if(k == '-'){
			remove(u);
		}
		if(k == '?'){
			cout << query(u) << endl;
		}
	}
}

int main(){

	optimize;
	
	cin >> N;
		
	solve();
    
	return 0;
}