#include<bits/stdc++.h>
using namespace std;

// Template 3

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
#define MAXN 200010

ll T,N,M;
string s;

int periodic(){
    int n = s.size();
    int next[n+1];

    next[0] = -1;

    for(int i=1;i<=n;i++){
        int j = next[i-1];

        while(j>=0 && s[j] != s[i-1]) j = next[j];

        next[i] = j + 1;
    }
    int a = n - next[n];

    if( !(n % a) ) return a;
    else return n;
}

void solve(){
    cout << periodic() << endl;
}

int main(){

	cin >> T;

    FOR(i,0,T){

        if(i) cout << endl;
        
        cin >> s;
		
        solve();
    }

	return 0;
}