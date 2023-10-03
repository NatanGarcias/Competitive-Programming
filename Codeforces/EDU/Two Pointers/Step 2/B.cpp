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

void solve(){

	ll ptr = 0, sum = 0, range = INF;

	for(ll i=0;i<N;){
		while(i != N && sum + A[i] < M){
			sum += A[i++];
		}

        if(i != N) sum += A[i++];

		while(ptr != N && sum - A[ptr] >= M){
			sum -= A[ptr++];
		}

		if(sum >= M)    range = min(range, i - ptr);
	}

	if(range == INF) range = -1;
	
	cout << range << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++) cin >> A[i];

	solve();

	return 0;
}