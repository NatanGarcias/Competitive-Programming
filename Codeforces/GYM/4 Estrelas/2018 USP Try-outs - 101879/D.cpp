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
#define MAXN 1234567

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

pii H[MAXN], V[MAXN];
int vaiB[MAXN], vaiP[MAXN], vemB[MAXN], vemP[MAXN];

int dimensao(pii A[]){

    ms(vaiB,0);
    ms(vaiP,0);
    ms(vemB,0);
    ms(vemP,0);

    int n, j = 1, ans = 0;

    for(int i=0; i<N ;i++, j++){
        if(!A[i].se){
            vaiB[j] = vaiB[j-1] + 1;
            vaiP[j] = vaiP[j-1];
        }
        else{
            vaiP[j] = vaiP[j-1] + 1;
            vaiB[j] = vaiB[j-1];
        }

        while(i < N-1 && A[i].fi == A[i+1].fi){
            i++;

            if(!A[i].se)    vaiB[j]++;
            else            vaiP[j]++;
        }
    }

    n = j;
    j-= 2;
    
    for(int i=N-1; i>=0 ;i--, j--){
        if(!A[i].se){
            vemB[j] = vemB[j+1] + 1;
            vemP[j] = vemP[j+1];
        }
        else{
            vemP[j] = vemP[j+1] + 1;
            vemB[j] = vemB[j+1];
        }

        while(i > 0 && A[i].fi == A[i-1].fi){
            i--;

            if(!A[i].se)    vemB[j]++;
            else            vemP[j]++;
        }
    }

    for(int i=0;i<n;i++){
        ans = max(ans, vaiB[i] + vemP[i]);
        ans = max(ans, vaiP[i] + vemB[i]);
    }

    return ans;
}

void solve(){

    sort(H,H+N);
    sort(V,V+N);

    int ans = max(dimensao(H), dimensao(V) );
 
    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;
    
    for(int i=0;i<N;i++){
        int a,b,c;
        char k;

        cin >> a >> b >> k;

        if(k == 'b')    c = 0;
        else            c = 1;

        H[i] = pii(b,c);
        V[i] = pii(a,c);
    }

	solve();
    
	return 0;
}