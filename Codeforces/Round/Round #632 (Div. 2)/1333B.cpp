#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

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
#define MAXN 100010

int T,N,M;
multiset<int> ms;
int a[MAXN];
int b[MAXN];

void solve(){
    
    FOR(i,0,N){
        int pos = N-i-1;

        ms.erase(ms.find(a[pos]));

        if(a[pos] == b[pos]) continue;
        else if(b[pos] > a[pos]){
            auto it = ms.find(1);
            if(it == ms.end()){
                cout << "NO\n";
                return;
            }

        }else if(b[pos] < a[pos]){
            auto it = ms.find(-1);
            if(it == ms.end()){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES" << endl;  
}

int main(){

	cin >> T;

    int x;

    while(T--){

        ms.clear();

		cin >> N;
        FOR(i,0,N){
            cin >> x;
            ms.insert(x);
            a[i] = x; 
        }

        FOR(i,0,N){
            cin >> b[i];
        }
		solve();
	}
	return 0;
}