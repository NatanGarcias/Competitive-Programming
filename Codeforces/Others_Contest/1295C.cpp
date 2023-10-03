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
string s,s2;

int getchar(char k){
    return k - 'a';
}

void solve(){
    vector<set<int>> pos;

    pos.resize(26);

    int nums[26] = {0};
    
    FOR(i,0,sz(s)) pos[ getchar(s[i]) ].insert(i);

    FOR(i,0,sz(s2)) nums[getchar(s2[i])]++;

    FOR(i,0,26){
        if(nums[i] && pos[i].empty()){
            cout << "-1\n";
            return;
        }
    }

    int i = 0;
    int ans = 0;
    
    while(i < sz(s2)){
        int p = 0;
        int id = getchar(s2[i]);
        auto it = pos[id].lower_bound(p);
        
        while(i < sz(s2) && p < sz(s) && it != pos[id].end()){
            p = (*it) +1;
            i++;

            if(i<sz(s2)){
                id = getchar(s2[i]);
                it = pos[id].lower_bound(p);
            }
        }
        ans++;
    }

    cout << ans << endl;
}

int main(){

    cin >> T;

    while(T--){
        cin >> s >> s2;
        
        solve();
    }

	return 0;
}