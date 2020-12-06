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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 50
#define MAXM 23
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int T,N,M,K;

int p[MAXM][26];
char m[MAXN][MAXN];
int vis[MAXN][MAXN];
bool v[MAXN][MAXN];

void resp(){

    int ans = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v[i][j]) ans++;        
        }
    }

    cout << ans << endl;
}

void solve(){

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){

            vector<int> let(26,0);

            //Horizontal
            for(int k=i;k<min(N,15+i);k++){
                let[ (int)(m[k][j] - 'A')]++;

                for(int l=1;l<=K;l++){
                    bool ok = true;
                    
                    for(int m=0;m<26;m++){
                        
                        if(let[m] != p[l][m]){
                            ok = false;
                            break;
                        }
                    }

                    if(ok){
                        for(int ak = i;ak<=k;ak++){
                            if(!vis[ak][j])     vis[ak][j] = l;
                            else if(vis[ak][j] != l) v[ak][j] = 1;
                        }
                    }
                }
            }

            for(int k=0;k<26;k++) let[k] = 0;

            //Vertical
            for(int k=j;k<min(M,15+j);k++){
                let[ (int)(m[i][k] - 'A')]++;

                for(int l=1;l<=K;l++){
                    bool ok = true;
                    
                    for(int m=0;m<26;m++){

                        if(let[m] != p[l][m]){
                            ok = false;
                            break;
                        }
                    }

                    if(ok){
                        for(int ak = j;ak<=k;ak++){
                            if(!vis[i][ak])     vis[i][ak] = l;
                            else if(vis[i][ak] != l) v[i][ak] = 1;
                        }
                    }
                }
            }

            for(int k=0;k<26;k++) let[k] = 0;

            //Diagonal Principal
            for(int k=0;k<min(min(N-i,M-j),15);k++){
                let[ (int)(m[i+k][j+k] - 'A')]++;

                for(int l=1;l<=K;l++){
                    bool ok = true;
                    
                    for(int m=0;m<26;m++){

                        if(let[m] != p[l][m]){
                            ok = false;
                            break;
                        }
                    }

                    if(ok){
                        for(int ak = 0;ak<=k;ak++){
                            if(!vis[i+ak][j+ak])     vis[i+ak][j+ak] = l;
                            else if(vis[i+ak][j+ak] != l) v[i+ak][j+ak] = 1;
                        }
                    }
                }
            }
            
            for(int k=0;k<26;k++) let[k] = 0;

            //Diagonal Secundária
            for(int k=0;k<min(min(i+1,M-j),15);k++){
                let[ (int)(m[i-k][j+k] - 'A')]++;

                for(int l=1;l<=K;l++){
                    bool ok = true;
                    
                    for(int m=0;m<26;m++){

                        if(let[m] != p[l][m]){
                            ok = false;
                            break;
                        }
                    }

                    if(ok){
                        for(int ak = 0;ak<=k;ak++){
                            if(!vis[i-ak][j+ak])     vis[i-ak][j+ak] = l;
                            else if(vis[i-ak][j+ak] != l) v[i-ak][j+ak] = 1;
                        }
                    }
                }
            }
        }
    }

    resp();
}

int main(){

	optimize;
	
	cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> m[i][j];
        }
    }	

    cin >> K;

    for(int i=1;i<=K;i++){
        string s;
        cin >> s;

        for(auto j : s){
            p[i][ (int) (j - 'A')]++;
        }
    }

	solve();

	return 0;
}