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

struct KMP{
    int m;
    string q;
    vector<int> lps;
    
    KMP(string &_q) : q{_q} {
        m = q.size();
        pre_process();
    }

    void pre_process(){
        lps.assign(m+1,-1);

        for(int i=0, j=-1; i<m ; ){
            while(j>=0 && q[i] != q[j]) j = lps[j];
            lps[++i] = ++j; 
        }
    }

    vector<int> match(string &p){
        vector<int> ans;

        ll n = p.size();

        if(n < m) return ans;

        for(int i=0,j=0; i<n ; ){
            while( j>=0 && p[i] != q[j]) j = lps[j];
            i++; j++;

            if(j == m){
                ans.push_back(i-j);
                j = lps[j];
            }
        }
        return ans;
    }
};

void solve(){

    string s3(s2);
    reverse(all(s3));

    KMP kmp(s2);
    KMP kmp2(s3);

    vector<int> pos = kmp.match(s);
    vector<int> pos2 = kmp2.match(s);

    ll ans = 0;
    int n = pos.size();

    for(int i = 0; i < n; i++){

        auto it = lower_bound(all(pos2), pos[i] + (int) s2.size());

        if(it != pos2.end()) ans += pos2.size() - ( it - pos2.begin());
    }

    cout << ans << endl;
}

int main(){

	optimize;
    
    cin >> s >> s2;

	solve();
    

	return 0;
}