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

int u[MAXN], v[MAXN], w[MAXN], dist[MAXN], z;
int a[MAXN], A[MAXN], b[MAXN], B[MAXN];

void add(int i, int j, int k){
	u[z] = i, v[z] = j, w[z] = k;
	z++;
}

void solve(){

	bool ans = true;

	for(int i=0;i<= 2*N + 2*M ;i++){
		ans = true;

		for(int j=0;j<z;j++){
			if(dist[ u[j] ] + w[j] < dist[ v[j] ]){
				ans = false;
				dist[ v[j] ] = dist[ u[j] ] + w[j];
			}
			
		}
	}

	if(ans) cout << "Possible\n";
	else 	cout << "Impossible\n";

}

int main(){

	//optimize;
	
	while(cin >> N >> M >> K){
		if(!N && !M && !K) break;

		z = 0;
		memset(dist, 0, sizeof(int) * (2*N + 2*M) );

		for(int i=0;i<N;i++){
			a[i] = i;
			A[i] = i+N;
		}

		for(int i=0;i<M;i++){
			b[i] = i + N + N;
			B[i] = i + N + N + M;
		}

		for(int i=0;i<K;i++){
			int x,y,c;
			string s;

			cin >> x >> y >> s >> c;

			x--, y--;

			if(s[0] == '<'){
				add(a[x], B[y], c);
				add(b[y], A[x], c);
			}
			else{
				add(A[x], b[y], -c);
				add(B[y], a[x], -c);	
			}

		}

		solve();
	}


	return 0;
}