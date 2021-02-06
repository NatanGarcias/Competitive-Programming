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
int vai[MAXN], vem[MAXN];

bool vogal(int i){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') return true;
    return false;
}

void erro(){
    cout << 0 << endl;
    exit(0);
}

void pre(){

    vai[0] = vogal(0);
    vem[N-1] = vogal(N-1);

    for(int i=1;i<N;i++)    vai[i] = vai[i-1] + vogal(i);
    for(int i=N-2;i>=0;i--) vem[i] = vem[i+1] + vogal(i);
}

bool f(int l, int r){
    return vai[r] == vai[l];
}

bool f2(int l, int r){
    return vem[l] == vem[r];
}

int solve(int l, int r, bool rev){

    if(l == r) return 1;

    if(rev){
        if(vogal(r)  &&  vogal(l))      return solve(l, r-1, !rev);
        if(vogal(r)  && !vogal(l))      return f2(l,r) + solve(l+1, r, rev);
        if(!vogal(r) &&  vogal(l))      erro();
        if(!vogal(r) && !vogal(l))      return solve(l+1, r, rev);
    }
    else{
        if(vogal(l)  &&  vogal(r))      return solve(l+1, r, !rev);
        if(vogal(l)  && !vogal(r))      return f(l,r) + solve(l, r-1, rev);
        if(!vogal(l) &&  vogal(r))      erro();
        if(!vogal(l) && !vogal(r))      return solve(l, r-1, rev);
    }
}

void solve(){

    N = s.size();

    pre();

    int ans = solve(0,N-1,false);

    cout << ans << endl;
}

int main(){

	optimize;
	
    cin >> s;

	solve();
    
	return 0;
}