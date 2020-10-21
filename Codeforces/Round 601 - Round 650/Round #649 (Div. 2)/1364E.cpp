#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];

int query(int a, int b){
	int aux;

    cout << "? " << a << " " << b << endl;
    cin >> aux;
    
    return aux;
}

void imprimi(){
	FOR(i,1,N+1){
        if(i == 1) cout << "! " << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

void solve(){

    vector<int> nums(N);
    iota(all(nums),1);

    int a = nums[0], b = nums[1], c;
    int vAB = query(a,b), vBC;

    FOR(i,2,N){
    	c = nums[i];

    	vBC = query(b,c);

    	if(vAB > vBC){
    		a = c;
    		vAB = vBC;
    	}else if(vBC > vAB){
    		continue;
    	}else{
    		b = c;
    		vAB = query(a,b);
    	}
    }

    int zero = 0;

    while(true){
    	int aux = rng()%N +1; 
    	while(aux == a || aux == b) aux = rng()%N +1;

    	int q1 = query(a,aux), q2 = query(b,aux);

    	if(q1 > q2) {
    		zero = b;
    		break;
    	}else if(q2 > q1){
    		zero = a;
    		break;
    	}
    }

    v[zero] = 0;

    FOR(i,1,N+1) if( i != zero )  v[i] = query(zero, i);

    imprimi();
}

int main(){

    cin >> N;

    solve();

	return 0;
}