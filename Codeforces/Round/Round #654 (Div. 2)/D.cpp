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
#define MAXN 400

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int m[MAXN][MAXN];

ll calc(){
	
	ll minC = INF, maxC = -1, minR = INF, maxR = -1;
	
	vector<ll> R(N,0), C(N,0);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(m[i][j]) R[i]++;
			if(m[i][j]) C[j]++;
		}
	}

	for(int i=0;i<N;i++){
		if(R[i] > maxR) maxR = R[i];
		if(R[i] < minR) minR = R[i];

		if(C[i] > maxC) maxC = C[i];
		if(C[i] < minC) minC = C[i];
	}

	return (maxR-minR)*(maxR-minR) + (maxC-minC)*(maxC-minC);
}
void solve(){

	ms(m,0);
	
	for(int j=0;j<N && K;j++){
		for(int i=0;i<N && K;i++){
			m[i%N][(i+j)%N] = true;
			K--;
		}
	}

	cout << calc() << endl;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << m[i][j];
		}
		cout << endl;
	}
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> K;
		
		solve();
    }

	return 0;
}