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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;
int v[MAXN], v2[MAXN], v3[MAXN], v4[MAXN];

void zero(){
    for(int i=0;i<N;i++){
        if(!i)  v[i] = (s[i] != '0');
        else    v[i] = v[i-1] + (s[i] != '0');
    }

    for(int i=N-1;i>=0;i--){
        if(i == N-1)    v3[i] = (s[i] != '0');
        else            v3[i] = v3[i+1] + (s[i] != '0');
    }
}

void one(){
    for(int i=0;i<N;i++){
        if(!i)  v2[i] = (s[i] != '1');
        else    v2[i] = v2[i-1] + (s[i] != '1');
    }

    for(int i=N-1;i>=0;i--){
        if(i == N-1)    v4[i] = (s[i] != '1');
        else            v4[i] = v4[i+1] + (s[i] != '1');
    }
     
}

void solve(){
    ms(v,0);
    ms(v2,0);
    ms(v3,0);
    ms(v4,0);

    zero();
    one();

    int ans = min({v[N-1],v2[N-1],v3[0],v4[0]});

    for(int i=0;i<N-1;i++) ans = min(ans, v[i] + v4[i+1]);

    for(int i=0;i<N-1;i++) ans = min(ans, v2[i] + v3[i+1]);

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
        cin >> s;
        
        N = s.size();

		solve();
    }

	return 0;
}