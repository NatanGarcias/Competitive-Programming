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
int q;

int query(int a, int b, int c, int d){

	string s;

	cout << "? " << b-a+1 << " " << d-c+1 << endl;

	for(int i=a;i<=b;i++)
		cout << i << " \n"[i==b];

	for(int i=c;i<=d;i++)
		cout << i << " \n"[i==d];

	cin >> s;

	if(s[0] == 'F') return 1;
	if(s[0] == 'S') return 2;
	if(s[0] == 'E') return 3;
	assert(false);
}

void ans(int x){
	cout << "! " << x << endl;
}

void solve(){

	vector<int> nums(N-1);
	iota(all(nums), 2);

	shuffle(all(nums), rng);
	
	//P1, vendo se o primeiro elemento é uma pedra da sorte
	for(int i=0;i<min(30,(int)nums.size());i++){
		int aux = query(1,1,nums[i],nums[i]);

		if(aux == 2){
			ans(1);
			return;
		}
	}

	//P2, vendo em que região está a primeira pedra da sorte
	int i = 1,j = 2;

	for(; j<=N; i*=2, j*=2){
	
		int aux = query(1, i, i+1, j);

		if(aux == 1) break;
	}

	//P3, verificando na região encontrada a posiçao da primeira pedra da sorte
	i++;
	j = min(j,(int)N);

	while(i < j){
		int m = (i+j)/2;

		int aux = query(1,m-i+1,i,m);

		if(aux == 1){
			j = m; 
		}else{
			i = m+1;
		}
	}

	ans(i);
	
	
}

int main(){

	cin >> T;

	while(T--){
		cin >> N >> M;
		solve();
	}

	return 0;
}