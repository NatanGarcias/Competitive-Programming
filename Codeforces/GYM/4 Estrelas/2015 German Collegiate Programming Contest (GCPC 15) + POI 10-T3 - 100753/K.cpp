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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
string s;
int ans;

void f(){

    M = s.size();

    for(int i=0;i<M;i++){
        if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '5' || s[i] == '8') continue;
        else if(s[i] == '6') s[i] = '9';
        else if(s[i] == '9') s[i] = '6';
        else ans = -1;
    }

    reverse(all(s));
}

bool prime(){

    stringstream ss;
    ss << s;

    ss >> N;

    if(N == 1) return false;
    
    for(ll i = 2; i*i <= N;i++){
        if( (N % i) == 0) return false;
    }

    return true;
}

void solve(){

    if( !prime() ) ans = -1;

    f();

    if(ans == -1 || !prime() )cout << "no\n";
    else cout << "yes\n";
}

int main(){

	optimize;
	
	cin >> s;
		
	solve();
    
	return 0;
}