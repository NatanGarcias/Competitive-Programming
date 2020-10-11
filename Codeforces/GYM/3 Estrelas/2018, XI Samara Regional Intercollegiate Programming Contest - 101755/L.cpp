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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;
set<int> v[28];

int getc(char k){
    return k - 'a';
}

void pre(){
    FOR(i,0,s.size()) v[ getc(s[i]) ].insert(i); 
}

void solve(){
    
    pre();

    vector<int> ptr;

    ptr.reserve(MAXN);
    ptr.pb(-1);

    FOR(i,0,N){
        string s2;
        char x;

        cin >> s2;

        if(s2[1] == 'u'){
            cin >> x;

            auto it = v[getc(x)].upper_bound( ptr[ptr.size()-1] );

            if(it == v[getc(x)].end()){
                ptr.pb( INF );
                cout << "NO\n";
            }
            else {
                ptr.pb( *it );
                cout << "YES\n";
            }
        }else{
            ptr.pop_back();

            if(ptr[ptr.size()-1] != INF) cout << "YES\n";
            else cout << "NO\n";
        }

    }
}

int main(){

	optimize;

    cin >> s;
    cin >> N;
		
    solve();
    
	return 0;
}