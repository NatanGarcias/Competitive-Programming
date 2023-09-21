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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
#define MAXN 103000
#define MAXM 1123456

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

bool f(int x, map<char, vector<ll>> m[], map<int, int> &mTemp) {

    for(char c = '0'; c <= '9'; c++) {
        init();

        for(int j = 0; j < N; j++) {
            add(0, j + 1, 1);
        }

        for(int i = 0; i < N; i++) {
            for(int t : m[i][c]) {
                if(t > x) continue;

                add(i + 1, mTemp[t] + N + 1, 1);
            }
        }
        
        for(int j = 0; j < mTemp.size(); j++) {
            add(N + j + 1, mTemp.size() + N + 1, 1);
        }

        if(dinic(0, mTemp.size() + N + 1) >= N) return true;
    }

    return false;
}

int bb(map<char, vector<ll>> m[], map<int, int> &mTemp) {

    int l = 0, r = INF;

    while(l < r) {
        int x = (l + r) / 2;

        if(f(x, m, mTemp))      r = x;
        else                    l = x + 1;
    }

    return l;
}

void solve() {

	cin >> N >> M;

    string s[N];
    vector<int> temp;
    map<int, int> mTemp;
    map<char, vector<ll>> m[N];

    for(int i = 0; i < N; i++) cin >> s[i];

    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            m[i][ s[i][j] ].push_back(j);
        }

        for(auto &d : m[i]) {

            auto &a = d.second;

            if(a.size() > N + 1) {
                a.resize(N + 1);
            }
            else {
                ll cnt = 0;
                while(a.size() < N + 1) a.push_back(M + a[cnt++]);
            }

            for(int e: a) temp.push_back(e);
        }
    }

    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    
    for(int i = 0; i < temp.size(); i++) mTemp[temp[i]] = i;

    int ans = bb(m, mTemp);

    if(ans == INF) ans = -1;

    cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
