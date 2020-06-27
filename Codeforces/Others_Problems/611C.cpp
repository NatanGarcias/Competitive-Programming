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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 510

ll T,N,M,K;
char v[MAXN][MAXN];
int ver[MAXN][MAXN];
int hor[MAXN][MAXN];

void solve(){

    FOR(i,0,N){
        FOR(j,1,M){
            if(v[i][j-1] == '.' && v[i][j] == '.'){
                hor[i][j] = hor[i][j-1] + 1;
            }else{
                hor[i][j] = hor[i][j-1];
            }
        }
    }

    FOR(j,0,M){
        FOR(i,1,N){
            if(v[i-1][j] == '.' && v[i][j] == '.'){
                ver[i][j] = ver[i-1][j] + 1;
            }else{
                ver[i][j] = ver[i-1][j];
            }
        }
    }

    cin >> K;

    FOR(k,0,K){
        int a,b,c,d;

        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;

        ll ans = 0;

        FOR(j,b,d+1){
            ans += ver[c][j] - ver[a][j];
        }

        FOR(j,a,c+1){
            ans += hor[j][d] - hor[j][b];
        }

        cout << ans << endl;
    }

}

int main(){

    cin >> N >> M;

    FOR(i,0,N) FOR(j,0,M) cin >> v[i][j];

    solve();

	return 0;
}