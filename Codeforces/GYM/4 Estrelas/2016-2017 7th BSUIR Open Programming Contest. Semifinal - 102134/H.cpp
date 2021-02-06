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
int A[MAXN];

void solve(){

    ll sum = 0;

    for(ll i=0;i<25;i++){
        ll on = 0, off = 0;

        for(ll j=0;j<N;j++){
            if(A[j] & (1LL << i)) on++;
            else                off++;
        }

        sum += on*on*on * (1LL << i);
        sum += 3LL * off*off*on * (1LL << i);
    }

    cout << sum << endl;
}

int main(){

	optimize;
	
	cin >> N;
    
    for(int i=0;i<N;i++) cin >> A[i];

	solve();

	return 0;
}