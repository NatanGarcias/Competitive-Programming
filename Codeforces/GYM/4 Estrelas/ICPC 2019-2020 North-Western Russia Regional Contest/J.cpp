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
#define MAXN 510

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int m[MAXN][MAXN], v[MAXN][MAXN], ans[MAXN][MAXN];

void solve(){

    for(int i = N-1;i>=0;i--){
        for(int j=i+1;j<N;j++){   
            if(m[i][j] != v[i][j]){
                
                ans[i][j] = 1;
                
                v[i][j]++;
                v[i][j] %= 10;

                for(int k=j+1;k<N;k++)
                    v[i][k] = (v[i][k] + v[j][k])% 10;
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main(){

	optimize;
	
    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)  {
            char k;

            cin >> k;

            m[i][j] = (int) k - '0';
        }
    }
    
    solve();
 
	return 0;
}