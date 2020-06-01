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

#define mod 1000000007
#define MAXN 110
#define MAXM 1010

ll T,N,M,K,A,B;
char v[MAXN][MAXM];

void solve(){

    int contA = 0, contB = 0;

    FOR(i,0,N){
        FOR(j,0,M){
            if(j == M-1){
                if(v[i][j] == '.') contA++;
            }else{
                if(v[i][j] == '.' && v[i][j+1] == '.'){
                    contB++;
                    j++;
                }else if(v[i][j] == '.'){
                    contA++;
                }
            }
        }
    }

    int respA = contA*A + 2*contB*A;
    int respB = contA*A + contB*B;

    cout << min(respA,respB) << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M >> A >> B; 

        FOR(i,0,N) FOR(j,0,M) cin >> v[i][j];
		solve();
    }

	return 0;
}