#include<bits/stdc++.h>
using namespace std;

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

#define mod 1000000007LL
#define MAXN 100010

ll T,N,M,K;
string s,s2;

void solve(){

    if(sz(s) != sz(s2)){
        cout << "NO\n";
        return;
    }

    if(s == s2){
        cout << "YES\n";
        return;
    }

    bool ok = false;
    FOR(i,0,sz(s)){
        if(s[i] == '1'){
            ok = true;
            break;
        }
    }

    bool ok2 = false;
    FOR(i,0,sz(s2)){
        if(s2[i] == '1'){
            ok2 = true;
            break;
        }
    }

    if(ok && ok2){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main(){

    cin >> s >> s2;

    solve();

	return 0;
}