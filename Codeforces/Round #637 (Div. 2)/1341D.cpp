#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x33333333
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 2010

int T,N,M;
bool dp[MAXN][MAXN];
bool solved[MAXN][MAXN];
int v[MAXN][10];
string s[10];
string ans;

int cont(const string &s1, const string &s2){
    
    int ans = 0;

    FOR(i,0,7) {
    	if(s1[i] == '0' && s2[i] == '1') ans++;
    	else if(s1[i] == '1' && s2[i] == '0') return INF; 
    }

    return ans;
}

void pre(){
    s[0] = "1110111";
    s[1] = "0010010";
    s[2] = "1011101";
    s[3] = "1011011";
    s[4] = "0111010";
    s[5] = "1101011";
    s[6] = "1101111";
    s[7] = "1010010";
    s[8] = "1111111";
    s[9] = "1111011";
}

// I-esimo posição do vetor, tentando transforma-lo no j-esimo número de 9 a 0
bool solve(int x, int y){

	if(x == N) return (y == M);

	if(y > M) return false;

	if(!solved[x][y]){
		dp[x][y] = false;
		for(int i = 9; i >=0 && !dp[x][y] ; i-- ){
			dp[x][y] = solve( x+1 , y+v[x][i] );
			if(dp[x][y]) ans += (char) (i + '0');
		}
		solved[x][y] = true;
	}

	return dp[x][y];
}

int main(){
    
    optimize;

    cin >> N >> M;

    string aux;

	pre();

    FOR(i,0,N){
    	cin >> aux;
    	FOR(j,0,10){
    		v[i][j] = cont(aux,s[j]);
    	}
    }

    solve(0,0);

    if(!ans.empty()){
    	reverse(all(ans));
    	cout << ans << endl;
    }
    else cout << -1 << endl;

	return 0;
}