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
#define MAXN 10105

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int m[MAXN][MAXN];

void build(int n) {

    int incX = 1;
    int incY = 0;

    int posX = 1;
    int posY = 1;

    for(int i = 0; i < n * n; i++) {
        m[posY][posX] = i + 1;

        if(incX == 1 && (posX == n || m[posY][posX + 1] != 0) ) {
            incX = 0;
            incY = 1;
        }
        else if(incX == -1 && (posX == 1 || m[posY][posX - 1] != 0) ) {
            incX = 0;
            incY = -1;
        }
        else if(incY == 1 && (posY == n || m[posY + 1][posX] != 0) ) {
            incX = -1;
            incY = 0;
        }
        else if(incY == -1 && (posY == 1 || m[posY - 1][posX] != 0) ) {
            incX = 1;
            incY = 0;
        }

        posX += incX;
        posY += incY;
    }
}

void moveNext(int &posX, int &posY) {

    if(m[posY - 1][posX] == m[posY][posX] + 1) {
        posX = posX;
        posY = posY - 1;
    }
    else if(m[posY + 1][posX] == m[posY][posX] + 1) {
        posX = posX;
        posY = posY + 1;
    }
    else if(m[posY][posX - 1] == m[posY][posX] + 1) {
        posX = posX - 1;
        posY = posY;
    }
    else if(m[posY][posX + 1] == m[posY][posX] + 1) {
        posX = posX + 1;
        posY = posY;
    }
}

void moveCenter(int &posX, int &posY, vector<pii> &ans) {

    ans.emplace_back(m[posY][posX], 0);
    
    bool ok = false;

    if(m[posY - 1][posX] > m[posY][posX] + 1) {
        posX = posX;
        posY = posY - 1;
        ok = true;
    }
    else if(m[posY + 1][posX] > m[posY][posX] + 1) {
        posX = posX;
        posY = posY + 1;
        ok = true;
    }
    else if(m[posY][posX - 1] > m[posY][posX] + 1) {
        posX = posX - 1;
        posY = posY;
        ok = true;
    }
    else if(m[posY][posX + 1] > m[posY][posX] + 1) {
        posX = posX + 1;
        posY = posY;
        ok = true;
    }
    
    ans.back().se = (m[posY][posX]);

    if(!ok) {
        ans.pop_back();
        moveNext(posX, posY);
    }
}

void solve(int caso) {

	cin >> N >> M;
	
    if(M & 1) {
        cout << "Case #" << caso << ": IMPOSSIBLE" << "\n";
        return;
    }

    ms(m, 0);

    build(N);

    vector<pii> ans;

    int k = M;
    int h = N / 2 + 1;

    int posX = 1, posY = 1;

    while(posX != h || posY != h) {

        if(abs(posX - h) + abs(posY - h) != k) {
            moveNext(posX, posY);
        }
        else {
            moveCenter(posX, posY, ans);
        }
        
        k--;
    }

    cout << "Case #" << caso << ": " << ans.size() << "\n";
    for(auto u : ans) cout << u.fi << " " << u.se << endl;
}

int main() {

	optimize;
	
	cin >> T;

    for(int i = 1; i <= T; i++) {
        solve(i);
    }

	return 0;
}