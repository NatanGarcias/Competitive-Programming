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
ll of = (1LL << 32) -1;
int i;

void ovfl(){
    cout << "OVERFLOW!!!\n";
    exit(0);
}

ll process(ll x){

    ll ans = 0;

    for(;i<N;i++){
        string s;

        cin >> s;

        if(s[0] == 'f'){
            int a;
            cin >> a;
            ans += process(a);
        }
        else if(s[0] == 'a'){
            ans++;
        }
        else{
            ans *= x;
            if(ans > of) ovfl();
            return ans;
        }
    }
    
}

void solve(){

    i = 0;

    cout << process(1) << endl;
}

int main(){

	optimize;
	
	cin >> N;

    solve();

	return 0;
}