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
#define MAXM 1010
#define MAXK 110
#define MAXL 20

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

vector<int> buildSa(const string& in) {
    int n = in.size(), c = 0;
    
    vector<int> temp(n), posBucket(n), bucket(n), bpos(n), out(n);
    
    for (int i = 0; i < n; i++) out[i] = i; 
    
    sort(out.begin(), out.end(), [&](int a, int b) { return in[a] < in[b]; });
    
    for (int i = 0; i < n; i++) {
        bucket[i] = c;
    
        if (i + 1 == n || in[out[i]] != in[out[i + 1]]) c++;
    }
    
    for (int h = 1; h < n && c < n; h <<= 1) {
    
        for (int i = 0; i < n; i++) posBucket[out[i]] = bucket[i];
        for (int i = n - 1; i >= 0; i--) bpos[bucket[i]] = i;

        for (int i = 0; i < n; i++) {
            if (out[i] >= n - h) temp[bpos[bucket[i]]++] = out[i];
        }
        
        for (int i = 0; i < n; i++) {
            if (out[i] >= h) temp[bpos[posBucket[out[i] - h]]++] = out[i] - h;
        }
        
        c = 0;
        
        for (int i = 0; i + 1 < n; i++) {
            int a = (bucket[i] != bucket[i + 1]) || (temp[i] >= n - h)
                || (posBucket[temp[i + 1] + h] != posBucket[temp[i] + h]);
        
            bucket[i] = c;
            c += a;
        }
        
        bucket[n - 1] = c++;
        
        temp.swap(out);
    }
    
    return out;
}

vector<int> sa;
string s, s2;
vector<string> t;
int ans, st[MAXL][MAXN], loga2[MAXN];
int pre[MAXK][MAXM], suf[MAXK][MAXM];

void build(int N){

	for(int i=0;i<N;i++) st[0][i] = sa[i];

	for(int j=1;j<=K;j++){
		for(int i=0;i + (1<<j) <= N ; i++){
            st[j][i] = min(st[j-1][i], st[j-1][i + (1<<(j-1))]);
		}
	}
}

int query(int L,int R){

	int j = loga2[R-L+1];

    return min(st[j][L], st[j][R - (1<<j) + 1]); 
}

int f(int m, int a, int cnt, int pos){

    int p = sa[m];

    if(s[p + cnt] >= t[pos][a + cnt]) return true;
    return false;
}

int f2(int m, int a, int cnt, int pos){

    int p = sa[m];

    if(s[p + cnt] <= t[pos][a + cnt]) return true;
    return false;
}

int bb(int l, int r, int a, int cnt, int pos){

    while(l < r){
        int  m = (l+r)/2;

        if( f(m, a, cnt, pos) )  r = m;
        else                l = m + 1;
    }

    if(s[ sa[l] + cnt] != t[pos][a + cnt]) return -1;
    return l;
}

int bb2(int l, int r, int a, int cnt, int pos){

    while(l < r){
        int  m = (l+r+1)/2;

        if( f2(m, a, cnt, pos) ) l = m;
        else                r = m - 1;
    }

    if(s[ sa[l] + cnt] != t[pos][a + cnt]) return -1;
    return l;
}

int find(int a, int b, int pos, int tip){

    int l = 0, r = N-1, cnt = 0;

    while(a + cnt <= b){
        int l2 = bb(l, r, a, cnt, pos);
        int r2 = bb2(l, r, a, cnt, pos);

        if(l2 == -1 || r2 == -1) return -1;

        l = l2, r = r2;

        if(tip) suf[pos][cnt] = N - 1 - cnt - query(l, r);
        else    pre[pos][cnt] = query(l, r);
        
        cnt++;
    }
}

void solve(){
    
    ms(pre, -1);
    ms(suf, -1);

    for(int j=0;j<t.size();j++){
        M = t[j].size();
        
        find( 0, M-1, j, 0);
    }

    s = s2;

    sa = buildSa(s);
    build(N);

    for(int j=0;j<t.size();j++){
        reverse(all(t[j]));
        
        M = t[j].size();

        find( 0, M-1, j, 1);
    }

    for(int j=0;j<t.size();j++){
        M = t[j].size();
        
        for(int i=0;i<M-1;i++) {     
            if(suf[j][M-2-i] == -1 || pre[j][i] == -1) continue;
            
            if(suf[j][M-2-i] >= pre[j][i] + i + 1) {
                ans++;
                break;
            }            
        }
    }

    cout << ans << endl;
}

void preCalc(){
    
    N = s.size();
    K = 18;
    
    loga2[0] = loga2[1] = 0;
    for(int i=2;i<=N;i++) loga2[i] = loga2[i/2] + 1;
    
    s2 = s;
    reverse(all(s2));

    sa = buildSa(s);

    build(N);
}

int main(){

	optimize;
    
    cin >> s;

	cin >> T;

    t.resize(T);

    preCalc();

    for(int i=0;i<T;i++) cin >> t[i];
    
    solve();
    
	return 0;
}