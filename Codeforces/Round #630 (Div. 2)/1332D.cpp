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
#define MAXN 200010

ll T,N,M,K;
int dp[4][4];
int a[4][4];

void solve(){

    if(T == 0){
        cout << "1 1\n" << 0 << endl;
    }else{
        int maior = (1 << 18);
        maior--;

        int diff = (1 << 17);

        a[0][0] = maior;
        a[0][1] = T;
        a[0][2] = 0;

        a[1][0] = diff;
        a[1][1] = diff + T;
        a[1][2] = T;

        a[2][0] = diff;
        a[2][1] = diff;
        a[2][2] = T;

        cout << "3 3\n";
        FOR(i,0,3){
            FOR(j,0,3){
                cout << a[i][j] << " \n"[j==2];
            }
        }
    }

}

int main(){

	cin >> T;
    solve();

	return 0;
}