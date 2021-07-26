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
vector<ll> A,B;
map<vector<int>, vector<int> > mA, mB;

vector<bool> prime;
vector<int> primes;
 
vector<vector<int>> factA, factB;
 
void sieve(int n){
 
    prime.assign(n, true);
 
    for(ll i = 2; i < n; i++){
        if(prime[i]){
            for(ll j = i * i; j < n; j += i){
                prime[j] = false;
            }
            primes.push_back(i);
        }
    }
}
 
vector<int> factors(int val){
    
    vector<int> s;
 
    for(int i = 0; i < primes.size(); i++){
        while(val % primes[i] == 0){
            s.pb(primes[i]);
            val /= primes[i];
        }
    }
 
    if(val != 1) s.pb(val);
 
    return s;
}

void solve(int i, int j, vector<int> nums, int n, vector<vector<int>> &fact, map<vector<int>, vector<int>> &m){

    if(i == n) return;

    solve(i+1, j, nums, n, fact, m);

    j = j | (1 << i);
    for(auto j : fact[i]) nums.pb(j);

    sort(all(nums));
    m[nums].pb(j);

    solve(i+1, j, nums, n, fact, m);
}

void solve(){

    vector<int> auxA, auxB;

    solve(0, 0, auxA, N, factA, mA);
    solve(0, 0, auxB, M, factB, mB);

    for(auto i: mA){
        if(mB.find(i.fi) != mB.end()){
            int aux = i.se[0];
            int aux2 = mB[i.fi][0];

            int bA = 0, bB = 0;

            vector<int> numsA, numsB;

            for(int j=0;j<17;j++) {
                if(aux & (1 << j)) {
                    bA++;
                    numsA.pb(A[j]);
                }
            }

            for(int j=0;j<17;j++) {
                if(aux2 & (1 << j)) {
                    bB++;
                    numsB.pb(B[j]);
                }
            }

            cout << "Y\n";
            cout << bA << " " << bB << endl;

            cout << numsA[0];
            for(int i=1;i<numsA.size();i++) cout << " " << numsA[i];
            cout << endl;

            cout << numsB[0];
            for(int i=1;i<numsB.size();i++) cout << " " << numsB[i];
            cout << endl;
            return;
        }
    }

    cout << "N\n";
}

int main(){

	optimize;
	
	cin >> N >> M;

    sieve(100100);

    A.resize(N);
    B.resize(M);

    factA.resize(N);
    factB.resize(M);

    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<M;i++) cin >> B[i];

    sort(all(A));
    sort(all(B));

    for(int i=0;i<N;i++) factA[i] = factors(A[i]);
    for(int i=0;i<M;i++) factB[i] = factors(B[i]);

	solve();
    
	return 0;
}