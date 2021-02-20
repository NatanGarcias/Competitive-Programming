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
#define MAXN 105

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
string A[MAXN], B[MAXN];

char f(char a, char b){
    return ( ( (a - 'A') + (b - 'A') ) % 26 ) + 'A';
}

char g(char a, char b){

    if(b > a)   return ( ( (b - 'A') - (a - 'A') ) % 26 ) + 'A';
    else        return ( ( 26 + (b - 'A') - (a - 'A') ) % 26 ) + 'A';
}

bool ver(string &a, string &b, string &c){

    string d;

    int n = c.size();

    for(int i=0;i<n;i++){
        if( f(a[i], c[i]) == b[i]){
            d.pb(b[i]);
        }
        else    return false;

        if(i+1 == a.size() ) return true;
    }

    for(int i=n;i<a.size();i++){
        if( f(a[i], d[i-n]) == b[i]){
            d.pb(b[i]);
        }
        else    return false;

        if(i+1 == a.size() ) return true;
    }

    return true;
}

void solve(){

    string ans;
    
    int n = 0;
    int p = 0;

    for(int i=0;i<N;i++) {
        if(n < A[i].size()){
            n = A[i].size();
            p = i;
        }
    }

    swap(A[0], A[p]);
    swap(B[0], B[p]);
    
    for(int i=0;i<n;i++){
        ans.pb( g(A[0][i], B[0][i]));

        bool ok = true;
        for(int j=0;j<N;j++){

            if(! ver(A[j], B[j], ans) ){
                ok = false;
                break;
            }    
        }

        if(ok){
            cout << ans << endl;
            return;
        }
    }

    cout << "Impossible\n";
}

int main(){

	optimize;
	
    while(cin >> N && N){

        for(int i=0;i<N;i++) cin >> A[i] >> B[i];

    	solve();
    }

	return 0;
}