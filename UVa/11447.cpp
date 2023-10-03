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

struct Point {
    int x, y;

    Point(int _x, int _y) : x(_x), y(_y) {}
    ll operator^(const Point &a) { return x * a.y - y * a.x; }
};

vector<Point> pt;

void solve() {

	cin >> N;

    pt.clear();

    for(int i = 0, u, v; i < N; i++) { 
        cin >> u >> v;

        pt.emplace_back(u,v);
    }

    cin >> M;

    double volume = 0;

    for(int i = 0; i < N - 1; i++) {
        volume += pt[i] ^ pt[i + 1];
    }

    volume += pt[N-1] ^ pt[0];

    volume = abs(volume);
    volume /= 2.0;

    volume *= M;

    double capacidade = volume;
    double atual, gasto, chuva;

    cin >> atual >> gasto >> chuva;
    volume *= atual / 100.0;
    volume -= gasto;

    if(volume < 0.0) {
        volume = 0.0;
        cout << "Lack of water. ";
    }

    volume += chuva;
    
    if(volume > capacidade) {
        cout << "Excess of water. ";
        volume = capacidade;
    }
    double final = volume / capacidade;
    final *= 100;

    int ans = final;

    cout << "Final percentage: " << ans << "%\n";

}

int main() {

	optimize;
	
	cin >> T;

    while(T--) {
		
		solve();
    }

	return 0;
}