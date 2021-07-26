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
string s,s2,s3;

void solve(string &p, string &q, char k){

    int cnt = 0, cnt2 = 0;
    
    for(int i=0;i<N;i++) cnt += (p[i] == k);
    for(int i=0;i<N;i++) cnt2 += (q[i] == k);

    if(cnt2 > cnt) swap(p,q);

    string ans;

    int i = 0, j = 0;

    while(i < 2*N || j < 2*N){

        //Coloco os caractere que menos aparece da primeira string 
        while(i < 2*N && p[i] != k) {
            ans.pb(p[i++]);
            if(j < 2*N && q[j] != k) j++;
        }

        //Coloco os caractere que menos aparece da segunda string
        while(j < 2*N && q[j] != k) ans.pb(q[j++]);

        while(i < 2*N && j < 2*N && p[i] == q[j]){
            ans.pb(p[i++]);
            j++;
        }

        if(i == 2*N) while(j < 2*N) ans.pb(q[j++]);
        if(j == 2*N) while(i < 2*N) ans.pb(p[i++]);
    }

    cout << ans << endl;
}

void solve(){

    int ones[3] = {0};

    for(int i=0;i<2*N;i++) if(s[i] == '1') ones[0]++;
    for(int i=0;i<2*N;i++) if(s2[i] == '1') ones[1]++;
    for(int i=0;i<2*N;i++) if(s3[i] == '1') ones[2]++;

    if(ones[0] >= N){
        if(ones[1] >= N) solve(s, s2, '1');
        else if(ones[2] >= N) solve(s, s3, '1');
        else if(ones[1] < N && ones[2] < N) solve(s2, s3, '0');
        else solve(s2, s3, '1');
    }
    else{
        if(ones[1] < N) solve(s, s2, '0');
        else if(ones[2] < N) solve(s, s3, '0');
        else if(ones[1] < N && ones[2] < N) solve(s2, s3, '0');
        else solve(s2, s3, '1');
    }
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
        cin >> N;

		cin >> s >> s2 >> s3;
		
		solve();
    }

	return 0;
}