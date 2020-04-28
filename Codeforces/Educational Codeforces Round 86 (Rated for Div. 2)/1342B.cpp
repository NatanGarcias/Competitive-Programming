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

#define mod 1000000007
#define MAXN 200010

ll T,N,M,A,B;
string S;

bool igual(string &a){

    FOR(i,0,sz(a)-1){
        if(a[i] != a[i+1]) return false;
    }
    return true;
}

bool periodo2(string &a){

    FOR(i,0,sz(a)-2){
        if(a[i] != a[i+2]) return false;
    }

    return true;
}

string concerta(string &a){

    string ans;

    FOR(i,0,sz(a)){
        
        if(!i){ 
            ans += a[i];
        }else if(ans[ sz(ans) -1 ] != a[i] ){
            ans += a[i];
        }else{
            char k;

            if(a[i] == '1') k = '0';
            else k = '1';

            ans += k;
            ans += a[i];
        }
    }

    return ans;
}

void solve(){

    string ans;

    if( igual(S) || periodo2(S)) cout << S << endl;

    else{
        ans = concerta(S);

        cout << ans << endl;
    }
}

int main(){

	cin >> T;

    while(T--){
        cin >> S;

    	solve();
    }

	return 0;
}