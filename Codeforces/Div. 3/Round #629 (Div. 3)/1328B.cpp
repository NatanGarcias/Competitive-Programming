#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<int,int>
#define fi first 
#define se second 

#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x33ffffff
#define INFLL 0x33ffffffffffffff

#define mod %1000000007

#define MAXN 200010

int T,N,M;

ll v[MAXN];

void prec(){
    int a = 1;
    v[1] = 1;
    FOR(i,2,MAXN){
        v[i] = v[i-1] + (i-1);
    }
}

void solve(){
    int ptr,ptr2;

    if(M == 1){
        ptr = 1;
        ptr2 = 0;
    }
    else{
        int aux =1;

        while(M >= v[aux]){
            aux++;
        }
        aux--;
        
        if(aux > (N-2)){
            M = M - v[aux];
            ptr = N-1;
            ptr2 = M;
        }
        else{
            ptr = aux;
            ptr2 = (M - v[aux]);
        }
    }
    FOR(i,0,N){
        if((N-i-1) == ptr || (N-i-1) == ptr2){
            cout << 'b';
        }else{
            cout << 'a';
        }
    }
    cout << endl;
}

int main(){

    prec();

	cin >> T;

	while(T--){
		cin >> N >> M;		
        solve();            
	}

	return 0;
}