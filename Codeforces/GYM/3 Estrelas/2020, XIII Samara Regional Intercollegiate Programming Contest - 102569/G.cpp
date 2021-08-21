#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int query(int x, int y){
    cout << "? " << x << " " << y << endl;
    cout.flush();

    char k;
    cin >> k;

    if(k == '>') return 1;
    else if(k == '<') return -1;
    else if(k == '=') return 0;
}

void result(vector<int> &ans){
    cout << "! ";
    for(int i=0;i<N;i++) {
        if(i == N-1) cout << ans[i] << endl;
        else         cout << ans[i] << " ";
    }

    cout.flush();
}

vector<int> ans;

void solve(int n, vector<int> &Porca, vector<int> &Parafuso){
    
    if(!n) return;

    if(n <= 1) {
        ans[ Porca.back() - 1] = Parafuso.back();
        return;
    }

    vector<int> aux(N);
    int num = rng() % n;

    for(int i=0;i<n;i++) aux[i] = query(Porca[num] , Parafuso[i]);

    vector<int> Porca1, Porca2;
    vector<int> Parafuso1, Parafuso2;

    int d = -1;
    for(int i=0;i<n;i++) if(!aux[i]) d = i;

    for(int i=0;i<n;i++) {
        if(i == num) continue;

        int e = query(Porca[i], Parafuso[d]);

        if(e < 0)   Porca1.pb(Porca[i]);
        else        Porca2.pb(Porca[i]);
    }

    for(int i=0;i<n;i++) {
        if(i == d) continue;

        if(aux[i] > 0)  Parafuso1.pb(Parafuso[i]);
        else            Parafuso2.pb(Parafuso[i]);
    }

    //Salvando a resposta
    ans[ Porca[num] - 1 ] = Parafuso[d];

    solve(Porca1.size(), Porca1, Parafuso1);
    solve(Porca2.size(), Porca2, Parafuso2);
}

void solve(){

    ans.resize(N);
    
    vector<int> Porca(N), Parafuso(N);
    iota(all(Porca), 1);
    iota(all(Parafuso), 1);

    solve(N, Porca, Parafuso);

    assert(K <= 5 * N * (int)log2(N));
    
    result(ans);
}

int main(){
    
	cin >> N;

    solve();
    
	return 0;
}