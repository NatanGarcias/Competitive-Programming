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
ll A[MAXN];
set<ll> s;
map<ll,ll> B;

void solve(){

	ll ans = 0;

    int ptr = 0, ptr2 = -1;

    while(ptr < N){
        while(ptr2 + 1 < N){
            bool ok = false;

            if(s.empty()) ok = true;
            else{
                ll x = A[ptr2 + 1];
                
                ll l = min(x, *s.begin());
                ll r = max(x, *s.rbegin());
                if(r - l <= M) ok = true;
            } 
            
            if(ok){
                ptr2++;
                if(!B[A[ptr2]]) s.insert(A[ptr2]);
                B[A[ptr2]]++;
            }
            else break;
        }
        
        ans += max(ptr2 - ptr + 1, 0);
        B[A[ptr]]--;
        if(!B[A[ptr]]) s.erase(A[ptr]);
        
        ptr++;
    }   

    cout << ans << endl;
}

int main(){
	
    optimize;

	cin >> N >> M;
	
    for(int i=0;i<N;i++) cin >> A[i];

	solve();

	return 0;
}