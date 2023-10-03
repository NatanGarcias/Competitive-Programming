#include<bits/stdc++.h>
using namespace std;

// Template 1
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

ll T,N,M;
pii v[MAXN];

void solve(){

    int a=0, b=0,c=0;

    FOR(i,0,N){
        if(v[i].fi%2) a++;
        if(v[i].se%2) b++;
        if(v[i].fi%2 && v[i].se%2) c++;

    }

    if( !(a%2) && !(b%2)){
        cout << 0 << endl;
        return;
    }

    if( ((a%2) ^ (b%2))){
        cout << -1 << endl;
        return;
    }

    if( (a%2) && (b%2) && (a-c)==0 && (b-c) ==0){
        cout << -1 << endl;
        return;
    }

    cout << 1 << endl;
}

int main(){

	cin >> N;

    FOR(i,0,N){
        cin >> v[i].fi >> v[i].se;
    }

    solve();

	return 0;
}