#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

ll T,N,M,A,B;
int v[MAXN];

int sub(int l, int r, vector<int> &nums){
    
    FOR(i,l+1,r){
        nums[ v[i] ]++;
    }

    int maior = -1;

    FOR(i,0,201){
        if( nums[i] > maior ) maior = nums[i];
    }
    return maior;
}

int sub2(int l, int r, vector<int> &nums, int lA, int rA){
    
    FOR(i,l+1,lA+1){
        nums[ v[i] ]++;
    }

    FOR(i,rA,r){
        nums[ v[i] ]++;
    }

    int maior = -1;

    FOR(i,0,201){
        if( nums[i] > maior ) maior = nums[i];
    }
    return maior;
}

int sub3(int l, int r){
    
    vector<int> nums(201,0);

    FOR(i,l+1,r){
        nums[ v[i] ]++;
    }

    int maior = -1;

    FOR(i,0,201){
        if( nums[i] > maior ) maior = nums[i];
    }
    return maior;
}

void solve(){
    
    vector<vector<int>> nums(201);

    FOR(i,0,N){
        nums[ v[i] ].pb(i);
    }

    int maior = sub3(-1,N);

    FOR(i,1,201){
        if(!nums[i].empty()){
            
            vector<int> qtdd(201,0);
            int lA = -1, rA = -1 ,l ,r;
            int valor = sz(nums[i])/2;

            FOR(j,0, sz(nums[i])/2 ){

                l = nums[i][valor -j -1];
                r = nums[i][ sz(nums[i])-valor+j ];

                int aux;

                if(lA == -1)   
                    aux = sub(l,r,qtdd);
                else
                    aux = sub2(l,r,qtdd,lA,rA);

                lA = l;
                rA = r;

                if( (valor-j)*2 + aux > maior ) maior = (valor-j)*2 + aux;
            }
        }
    }

    cout << maior << endl;
}

int main(){

    optimize;
    
	cin >> T;

    while(T--){
        cin >> N;

        FOR(i,0,N){
            cin >> v[i];
        }

        solve();
    }

	return 0;
}