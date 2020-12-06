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
string s,s2;

void solve(){

    vector<int> l(27), l2(27);

    for(int i=0;i<s.size();i++) l[ s[i] - 'a' ]++;
    for(int i=0;i<s2.size();i++) l2[ s2[i] - 'a' ]++;

    for(int i=0;i<26;i++){
        if(l[i] < l2[i]) {
            cout << "No\n";
            return;
        }
        else if(l[i] == l2[i]) continue;
        else{
            if( !( (l[i] - l2[i]) % M ) ){
                if(i == 25){
                    cout << "No\n";
                    return; 
                }

                l[i+1] += (l[i] - l2[i]);
            }
        }
    }

    cout << "Yes\n";
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
    
        cin >> s >> s2;

		solve();
    }

	return 0;
}