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
#define MAXN 100010
#define MAXM 10
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int m[MAXN][MAXM];

int f(int x, int y){

	int ans = 0, ans2 = 0;

	for(int i=0;i<5;i++){
		if(m[x][i] < m[y][i]) ans++;
		else if(m[x][i] > m[y][i]) ans2++;
	}

	if(ans >= 3) return 1;
	else if(ans2 >= 3) return -1;
	else return 0;
}

void solve(){

	vector<int> atl(N);
	iota(all(atl),0);

	while(atl.size() > 1){
		vector<int> aux;

		for(int i=0;i<atl.size()-1;i+=2){
			int res = f(atl[i], atl[i+1]);

			if(res == 1) aux.pb(atl[i]);
			else if(res == -1) aux.pb(atl[i+1]);
		}

		if( ( (int) atl.size() ) & 1) aux.pb(atl.back());
		atl = aux;
	}

	for(int i=0;i<N;i++) {
		if(atl.back() != i && f(atl.back(), i) != 1){
			atl.clear();
			break;
		}
	}

	if(atl.empty()) cout << -1 << endl;
	else cout << atl.back() + 1 << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<5;j++){
				cin >> m[i][j];
			}
		}

		solve();
    }

	return 0;
}