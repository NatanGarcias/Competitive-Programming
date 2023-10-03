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

bool isCorrect(string &ans) {

    vector<int> let(26, -1);

    for(int i = 0; i < ans.size(); i++) {
        int l = ans[i] - 'A';
        
        if(let[l] != -1 && let[l] != i - 1) {
            return false;
        }
        let[l] = i;
    }

    return true;
}
string getTower(vector<string> &words, vector<vector<pii>> &adj, vector<string> &sameWord, vector<bool> &visTopo) {

    string ans;

    vector<int> topo(26, 0);

    for(int i = 0; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            topo[ adj[i][j].first ]++;
        }
    }
    
    for(int i = 0; i < 26; i++) {
        int j = i;
        while(visTopo[j] && topo[j] == 0) {
            
            if(!sameWord[j].empty()) {
                ans += sameWord[j];
                sameWord[j] = "";
            }

            topo[j] = -1;
            
            if(adj[j].size()) {
                ans += words[ adj[j][0].second ];
                topo[adj[j][0].first]--;
                j = adj[j][0].first;
            }
        }
    }

    if(ans.size() != K) ans = "IMPOSSIBLE";
    if(!isCorrect(ans)) ans = "IMPOSSIBLE";
    return ans;
}

void solve(int caso) {

	cin >> N;

    vector<string> words(N);

    K = 0;

    for(int i = 0; i < N; i++) {
        cin >> words[i];
        K += words[i].size();
    }
    
	vector<vector<pii>> adj(26, vector<pii>());
    vector<string> sameWord(26);
    vector<bool> visTopo(26, 0);

    for(int i = 0; i < words.size(); i++) {
        visTopo[ words[i][0] - 'A'] = true;

        if(words[i][0] == words[i].back()) {
            sameWord[words[i][0] - 'A'] += words[i];
        }
        else{
            adj[words[i][0] - 'A'].push_back({words[i].back() - 'A', i});
        }
    }

    string ans = getTower(words, adj, sameWord, visTopo);

    cout << "Case #" << caso << ": " << ans << "\n";
    
}

int main() {

	optimize;
	
	cin >> T;

    for(int i = 1; i <= T; i++) {
        solve(i);
    }

	return 0;
}