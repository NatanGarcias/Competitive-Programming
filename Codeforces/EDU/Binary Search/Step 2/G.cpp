#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
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
ll A[MAXN], sum;

bool verifica(ll x){

    if(sum < x * N) return false;

    ll ptr = 0, l = 0;

    for(int i=0;i<M;i++){
        ll ptr2 = ptr, aux = A[i];

        if(aux >= x){
            l++;
        }
        else if(ptr + aux >= x){
            l++;
            ptr = (ptr+aux - x);
        }
        else{
            ptr += aux;
        }
    }

    return (l >= N);
}

ll bb(){

    ll l = 0LL, r = INFLL;
    
    while(l < r){
        ll m = (l+r+1)/2LL;

        if(verifica(m))
            l = m;
        else
            r = m - 1LL;
    }

	return l;
}

void solve(){

    sort(A,A+M);
    reverse(A,A+M);

	cout << bb() << endl;
}

int main(){

	optimize;
	
    cin >> N >> M;

    for(int i=0;i<M;i++) cin >> A[i];
    for(int i=0;i<M;i++) sum += A[i];
    	
	solve();
    
	return 0;
}