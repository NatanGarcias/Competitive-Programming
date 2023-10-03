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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 55

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int m[MAXN][MAXN];
int m2[MAXN][MAXN];

void troca(){
    FOR(i,0,N){
        FOR(j,0,M){
            int a = m[i][j];
            int b = m2[i][j];

            m[i][j] = min(a,b);
            m2[i][j] = max(a,b);
        }
    }
}

bool Hor(){
    FOR(i,0,N){
        FOR(j,1,M){
            if(m[i][j] <= m[i][j-1]) return false;
        }
    }
    return true;
}

bool Ver(){
    FOR(i,0,M){
        FOR(j,1,N){
            if(m[j][i] <= m[j-1][i]) return false;
        }
    }
    return true;
}


bool Hor2(){
    FOR(i,0,N){
        FOR(j,1,M){
            if(m2[i][j] <= m2[i][j-1]) return false;
        }
    }
    return true;
}

bool Ver2(){
    FOR(i,0,M){
        FOR(j,1,N){
            if(m2[j][i] <= m2[j-1][i]) return false;
        }
    }
    return true;
}

bool solve(){

    troca();

    if(Hor() && Hor2() && Ver() && Ver2()) return true;
    else return false;
}

int main(){

    cin >> N >> M;

    FOR(i,0,N){
        FOR(j,0,M){
            cin >> m[i][j];
        }
    }

    FOR(i,0,N){
        FOR(j,0,M){
            cin >> m2[i][j];
        }
    }

    if(solve()) cout << "Possible\n";
    else cout << "Impossible\n";

	return 0;
}