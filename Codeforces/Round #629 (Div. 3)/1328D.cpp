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

ll T,N;
int v[MAXN];
int r[MAXN];

void solve(){
   
    int aux = 1;
    int color = 1;
    int ult = -1;

    r[0] = aux;
    
    FOR(i,1,N){
        if(v[i] == v[i-1]){
            ult = i;
            aux = 1;
            r[i] = 1;
            if(i == N-1 && r[N-2] == 2 && v[0] != v[N-1]){
                r[i] = 2;
            }
        }else{
            color = 2;
            if(aux == 1){
                aux = 2;
            }else{
                aux = 1;
            }
            r[i] = aux;
        }
    }

    if(r[N-1] == r[0] && v[N-1] != v[0]){
        int cont = 0;
        if(r[0] == r[1]){
            r[0] = 2;
        }else if(r[N-2] == r[N-1]){
            r[N-1] = 2;
        }else{
            if(ult != -1 ){
                if(r[ult] == r[ult-1]){
                    if(r[ult-1] == 1) r[ult] = 2;
                    else r[ult] = 1;
                }else{
                    r[ult] = r[ult-1];
                }
                
                FOR(i,ult+1,N){
                    if(r[i] == 2) r[i] = 1;
                    else r[i] = 2;
                }
            }else{

                r[0] = 3;
                color = 3;
                while(cont < N && r[cont] == r[cont+1]){
                    r[cont] = 3;
                    cont++;
                }
            }
        }
        
    }

    cout << color << endl;
    FOR(i,0,N){
        cout << r[i] << " \n"[i==N-1];
    }
}

int main(){

    optimize;
    
	cin >> T;

	while(T--){
        ms(v,0);
        ms(r,0);
		cin >> N;		
        FOR(i,0,N){
            cin >> v[i];
        }
        solve();            
	}

	return 0;
}