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

#define mod 998244353LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];
bool vis[MAXN]; 	// Se eu sou o maior até aqui
bool vis2[MAXN]; 	// Se eu viro registro se tirar o maior antes de mim
int nums;
map<int,int> mapa;  // Quantidade de pessoas que viram registro se o i sair

int solve(int i){
	
	int ans = nums;
	if(vis[i]) ans--;
	if(vis[i]) ans += mapa[i];
	return ans; 
}

void solve(){

	int mai = -1;
	int mai2 = -1;

	FOR(i,0,N){
		if(v[i] > mai){
			mai2 = mai;
			mai = v[i];
			vis[i] = true;
		}
		else if(v[i] > mai2){
			vis2[i] = true;
			mai2 = v[i];
		}
	}

	ll sum = 0;
	FOR(i,0,N) sum += vis[i];
	
	nums = sum;

	sum = 0;
	mai = -1;

	FOR(i,0,N){
		if(vis[i]){
			if(mai != -1) mapa[mai] = sum;
			sum += vis2[i];
			mai = i;
			sum = 0;
		}
		if(vis2[i]){
			sum += vis2[i];
		}
	}
	mapa[mai] = sum;

	int ans = INF, val = -1;

	FOR(i,0,N){
		int aux = solve(i);
		if(aux >= val){
			if(aux > val){
				val = aux;
				ans = v[i];
			}else{
				ans = min(v[i],ans);
			}
			
		}
	}

	cout << ans << endl;
}

int main(){
    
    cin >> N;

    FOR(i,0,N) cin >> v[i];

    solve();

	return 0;
}