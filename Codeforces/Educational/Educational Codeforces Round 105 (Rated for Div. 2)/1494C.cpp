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
vector<int> pos, pos2, esp, esp2;

int f(vector<int> &a, vector<int> &b){

	if(a.empty() || b.empty()) 	return 0;
	if(a[0] > b.back())			return 0;

	int ptr = 0, ptr2 = 0, ans = 0;
	vector<int> c;

	while(ptr < a.size() && ptr2 < b.size()){
		if(b[ptr2] < a[ptr])	ptr2++;
		else if(a[ptr] < b[ptr2]) 	ptr++;
		else if(a[ptr] == b[ptr2]){
			c.pb(a[ptr]);
			ptr++;
			ptr2++;
		}
	}

	ptr = 0;
	ans = c.size();

	int i = 0;
	if(i < b.size() && b[i] < a[0]) i++;

	for(;i<b.size();i++){
		while(ptr < a.size() && a[ptr] <= b[i]) 	ptr++;

		while(ptr < a.size() && b[i] + ptr >= a[ptr])	ptr++;

		int aux = 0;

		auto it = upper_bound(all(b), b[i] + ptr - 1);
		it--;

		aux = it - b.begin();
		aux = aux - i + 1;

		int aux2 = upper_bound(all(c), b[i] + ptr) - c.begin();
		aux2 = c.size() - aux2;

		ans = max(ans, aux + aux2);
	}

	return ans;
}	

void solve(){

	reverse(all(pos2));
	reverse(all(esp2));

	int ans = f(pos, esp);
	ans += f(pos2, esp2);

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

		pos.clear();
		pos2.clear();
		esp.clear();
		esp2.clear();

		for(int i=0;i<N;i++) {
			int a;

			cin >> a;

			if(a < 0) 	pos2.pb(-a);
			else 		pos.pb(a);
		}

		for(int i=0;i<M;i++) {
			int a;

			cin >> a;

			if(a < 0) 	esp2.pb(-a);
			else 		esp.pb(a);
		}
		
		solve();
    }

	return 0;
}