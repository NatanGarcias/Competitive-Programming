#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<int,int>
#define fi first 
#define se second 

#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007

#define MAXN 1010
#define MAXM 2050

struct Show{
	int i, f, o, b;
	Show(int _i, int _f, int _o, int _b) : i{_i}, f{_f}, o{_o} , b{_b} {}
	bool operator<(const Show &a){
		if(i < a.i) return true;
		else return false;
	} 
};

int T,N,M,bitOn;
int dp[MAXM][MAXN];
bool ok[MAXM][MAXN];
vector<Show> shows;
vector<int> prox;

// i = shows que eu já fui / j = id do show atual
int solve(int i, int j){

	//Se cheguei no tempo limite e fui em todos os shows minha resposta é valida, casos contrário, não
	if(i == bitOn && j == N){
		return dp[i][j];
	}else if(j == N){
		return -INF;
	}else{
		if(!ok[i][j]){
			dp[i][j] = max( solve(i,j+1) , solve( i | (1 << shows[j].b), prox[j] ) + shows[j].o );
			ok[i][j] = true;
		}
	}

	return dp[i][j];
}

void solve(){
		
	sort(all(shows));

	N = sz(shows);

	prox.resize(N);

	FOR(i,0,N){
		int j = 0;
		
		while( j < N && shows[j].i < shows[i].f) j++;
		
		prox[i] = j;	
	}

	bitOn = (1 << M) -1;

	int ans = solve(0,0);

	if(ans > 0) cout << ans << endl;
	else cout << -1 << endl;
}

int main(){

	cin >> M;

	int a,b,c,d;

    FOR(i,0,M){
    	cin >> N;
    	FOR(j,0,N){
	    	cin >> a >> b >> c;
	    	shows.emplace_back(a,b,c,i);
    	}
    }

    solve();

	return 0;
}