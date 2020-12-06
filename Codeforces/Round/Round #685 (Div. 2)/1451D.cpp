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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int cnt;

bool h(ll x, ll y){
    return x*x + y*y <= N*N;
}

void venc(){
    if(cnt & 1){
        cout << "Ashish\n";
    }
    else{
        cout << "Utkarsh\n";
    }
}

void solve(){

    vector<int> ans;

    ll x = 0,y = 0;
    cnt = 0;

    ll t = N/M , t2 = 0;

    if( !(N%M) ) t--;
    
    ll mov = t;
    
    t = t * M;
    
    while(t >= t2 && h(t , t2+M) ){
        mov++;
        t2 += M;
    }

    ans.push_back(mov);

    while(t >= t2){
        t -= M;

        mov--;

        while(t >= t2 && h (t , t2+M) ){
            mov++;
            t2 += M;
        }

        if(t >= t2){
            ans.push_back(mov);
        }
    }

    if(ans[ans.size()-1] & 1) cnt = 1;
    else cnt = 0;
    
    venc();

}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
		
		solve();
    }

	return 0;
}