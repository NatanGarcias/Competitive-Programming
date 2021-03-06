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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
string s;

void solve(){

    string ans;
    vector<vector<int>> l(26);

    M = s.size();

    for(int i=M-1;i>=0;i--){
        l[s[i] - 'a'].pb(i);
    }

    while(ans.size() < N){
    
        for(int i=0;i<26;i++){
            if(!l[i].empty() && M - l[i].back() >= N - ans.size()){
                
                for(int j = i+1;j<26;j++){
                    while(!l[j].empty() && l[j].back() < l[i].back()) l[j].pop_back();
                }

                ans.pb( s[l[i].back()]);
                l[i].pop_back();
                break;
            }
        }    
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
    cin >> s >> N;

	solve();
    
	return 0;
}