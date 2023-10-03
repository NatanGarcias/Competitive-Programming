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

#define INF 0x3f3f3f3f
#define MAXN 103000
#define MAXM 900000

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

string getNome(const vector<vector<string>> &nomes, int i, int j) {
	
	for(auto &k : nomes[i]){
		if(tolower(k[0]) - 'a' == j) return k;
	}
	assert(false);
}

void solve(int id) {

	cin >> N;

    init();

	vector<vector<string>> nomes;

    for(int i = 0; i < N; i++) {
        add(0, i + 1, 1);
        add(N + i + 1, N + 27, 1);

        cin >> M;

		vector<string> linha;
		vector<bool> l(26, 0);

        for(int j = 0; j < M; j++) {
            string s;

            cin >> s;

			linha.pb(s);
			l[tolower(s[0]) - 'a'] = true;
        }

		for(int j = 0; j < 26; j++) {
        	add(i + 1, N + 1 + j, l[j]); 
		}

		nomes.pb(linha);
    }

	dinic(0, N + 27);

	vector<string> ans;
	int pos = 0;

	for(int i = 0; i < N; i++) {

		pos += 4;

		for(int j = 0; j < 26; j++) {
			if(cap[pos + 1]) 	ans.pb( getNome(nomes, i, j) );
			pos += 2;
		}
	}

	cout << "Case #" << id + 1 << ":\n";
	for(int i = 0; i < N; i++){
		
		for(int j = 0; j < ans[i].size(); j++) {
			if(j)	ans[i][j] = tolower(ans[i][j]);
			else 	ans[i][j] = toupper(ans[i][j]);
		}


	}

	sort(all(ans));
	for(auto &i : ans) cout << i << endl;
}

int main() {

	optimize;
	
	cin >> T;

    for(int i = 0; i < T; i++) {
		solve(i);
    }

	return 0;
}