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
#define MAXM 2000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN], B[MAXM];
map<int,int> mapa;
int sum, men;
vector<pii> nums;

void print(bool k){

    if(!k || (!sum && !men) ){
        cout << "*\n";
    }
    else if(men && sum){
        cout << '-' << men << " +" << sum << endl;
    }
    else if(men){
        cout << '-' << men << endl;
    }
    else if(sum){
        cout << '+' << sum << endl;
    }

    exit(0);
}

void solve(){

    for(int i=0;i<M;i++) B[ A[i] ]++;

    for(int i=1;i<=K;i++){
        nums.pb(pii(B[i], i));
    }

    sort(all(nums));
    
    bool ok = true;

    for(int i=1;i<K-2;i++) if(nums[i].fi != nums[i+1].fi) ok = false;

    if(!ok) print(0);
    
    if(nums[0].fi != nums[1].fi){
        if(nums[0].fi == nums[1].fi-1) sum = nums[0].se;
        else if(nums[0].fi == nums[1].fi+1) men = nums[0].se;
        else print(0);
    }
    
    if(nums[nums.size()-1].fi != nums[nums.size()-2].fi) {
        int u = nums[nums.size()-1].fi;
        int v = nums[nums.size()-2].fi;

        if(u == v-1) {
            if(sum) print(0);
            sum = nums[nums.size()-1].se;
        }
        else if(u == v+1) {
            if(men) print(0);
            men = nums[nums.size()-1].se;
        }
        else{
            print(0);
        }
    }

    print(1);
}

int main(){

	optimize;
	
	cin >> K >> M;
	
    for(int i=0;i<M;i++) cin >> A[i];

	solve();

	return 0;
}