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
ll v[MAXN];

void solve(){

	ll ans, sum = 0;
	for(int i=0;i<N;i+=2) sum += v[i];
	
	//Começando de uma posição par
	ll maior = 0, aux = 0;
	bool ok = false;

	for(int i=0;i<N-1;i+=2){
		aux += (v[i+1] - v[i]);

		if(aux > maior) maior = aux;

		if(aux < 0) aux = 0;
	}

	ans = maior + sum;

	//Começando de uma posição impar
	maior = 0, aux = 0;
	ok = false;
	
	for(int i=1;i<N-1;i+=2){
		aux += (v[i] - v[i+1]);

		if(aux > maior) maior = aux;

		if(aux < 0) aux = 0;
	}

	ans = max(ans, maior + sum);

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

		for(int i=0;i<N;i++) {
			cin >> v[i];
		}
		
		solve();
    }

	return 0;
}