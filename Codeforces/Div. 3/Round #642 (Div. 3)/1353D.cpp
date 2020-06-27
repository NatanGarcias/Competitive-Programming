#include<bits/stdc++.h>
using namespace std;

// Template 1
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

ll T,N,M,K;
int v[MAXN];

void solve(){

    priority_queue<pair<int,pii>> pq;

    pq.push(make_pair(N,pii(-1,-N)));

    int cont = 1;

    while(!pq.empty()){
        int t = pq.top().fi;
        pii u = pq.top().se;

        pq.pop();

        u.fi *= (-1); u.se *= (-1);
     
        if(u.fi == u.se){
            v[u.fi] = cont;
        }else{
            int pos = ( u.fi + u.se )/2;

            v[pos] = cont;

            if(pos != u.fi && pos != u.se){
                pq.push(make_pair( pos - u.fi   , pii(-u.fi, -(pos-1) )  ) );
                pq.push(make_pair( u.se-pos     , pii(-(pos+1), -u.se  )  ) );
            }else if(pos == u.fi){
                pq.push(make_pair( u.se-pos   , pii(-(pos+1), -u.se     )  ) );
            }else if(pos == u.se){
                pq.push(make_pair( pos - u.fi   , pii(-u.fi   , -(pos-1) )  ) );
            }
        }
        cont++;
    }

    FOR(i,1,N+1){
        cout << v[i] << " \n"[i==N];
    }

}

int main(){

    optimize;
    
	cin >> T;

    while(T--){
		cin >> N;

		solve();
    }

	return 0;
}