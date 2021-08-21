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

struct Pilha{

    vector<ll> nums, val;

    Pilha(){
        val.pb(0LL);
    }

    bool empty() { return nums.empty(); }
    
    ll gcd(){
        return val.back();
    }

    ll push(ll x){
        nums.pb(x);
        val.pb(__gcd(val.back(), x));
    }

    ll pop(){
        ll x = nums.back();
        nums.pop_back();
        val.pop_back();

        return x;
    }

    void clear() {
        while(!empty()){
            pop();
        }
    }

    void print(){
        cerr << nums << " " << val << endl;
    }
};

Pilha p1, p2;

bool good(){
    return (__gcd(p1.gcd(), p2.gcd()) != 1LL);
}

void remove(){
    if(p2.empty()){
        while(!p1.empty()){
            p2.push(p1.pop());
        }
    }
    p2.pop();
}

void solve(){

    if(N == 1) {
        cout << 1 << endl;
        return;
    }

    ll ans = 0;
    ll l = 0, r = 0;
    
    for(;r + 1 < N;){

        while(good()){
            ans = max(ans, (r - l + 1));

            if(r + 1 >= N) break;

            p1.push(abs(A[r+1] - A[r]));
            r++;
        }
        
        remove();
        l++;
    }

    cout << ans << endl;

    p1.clear();
    p2.clear();
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }		

		solve();
    }

	return 0;
}