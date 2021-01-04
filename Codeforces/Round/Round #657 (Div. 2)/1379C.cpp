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

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
pii A[MAXN], B[MAXN];
int A2[MAXN], B2[MAXN];

void solve(){

	vector<bool> vis(M,0);

	sort(A,A+M, greater<pii>());
	sort(B,B+M, greater<pii>());

	int ptr = 0, ptr2 = 0;
	ll maior = 0, aux = 0;

	while(ptr < M && ptr2 < M && N){
		if(A[ptr].fi >= B[ptr2].fi){
			N--;
			vis[ A[ptr].se ] = true;
			aux += A[ptr++].fi;
			maior = max(maior, aux);
		}
		else{
			if(vis[ B[ptr2].se ]){
				aux += B[ptr2].fi * N; 
				maior = max(maior, aux);
				N = 0;
				break;
			}
			else{
				ll aux2 = aux + A2[ B[ptr2].se ] + B[ptr2].fi * (N-1);
				ptr2++;
				maior = max(maior, aux2);
			}
		}
	}

	if(ptr2 < M && N && vis[ B[ptr2].se ]){
		aux += B[ptr2].fi * N; 
		maior = max(maior, aux);
	}
	
	cout << maior << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
		
		for(int i=0;i<M;i++){
			cin >> A[i].fi;
			A2[i] = A[i].fi;
			A[i].se = i;

			cin >> B[i].fi;
			B2[i] = B[i].fi;
			B[i].se = i;
		}

		solve();
    }

	return 0;
}