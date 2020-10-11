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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s, s1, s2;
int t2[3];

vector<int> dif(string &p, string &q){
	vector<int> aux;

	for(int i=0;i<p.size();i++)
		if(p[i] != q[i]) aux.pb(i);

	return aux;
}

void print(int x){
	if(!x) cout << "Impossible\n";
	else if(x == 1) cout << "Ambiguous\n";
	else cout << s << endl;
	exit(0);
}

void conserta(set<int> &nums, int x){

	int m, p = 0, q; 
	char k; 

	if(x){
		for(auto i : nums){
			int v[26]= {0};

			m = -1;
			
			v[s[i] - 'a']++;
			v[s1[i] - 'a']++;
			v[s2[i] - 'a']++;

			for(int j=0;j<26;j++){
				if(v[j] > m){
					m = v[j];
					k = j + 'a';
				}
			}
			assert(m == 2);
			s[i] = k;
		}
	}else{

		for(auto i : nums){
			int v[26]= {0};
			
			m = -1;
			
			v[s[i] - 'a']++;
			v[s1[i] - 'a']++;
			v[s2[i] - 'a']++;

			for(int j=0;j<26;j++){
				if(v[j] > m){
					m = v[j];
					k = j + 'a';
				}
			}
			
			if(m == 2){
				s[i] = k;	
				p = i;

				if(t2[0] == 1) q = 2;
				else if(t2[1] == 1) q = 1;
				else if(t2[2] == 1) q = 0;
			}
		}

		for(auto i : nums){
			if(i != p){
				if(q == 2) s[i] = s2[i];
				else if(q) s[i] = s1[i];				
			}
		}
	}
}

void solve(){

	set<int> nums;
	int t[3]= {0};

	// a != b
	vector<int> aux = dif(s,s1);
	t[0] = aux.size();
	for(auto i : aux) nums.insert(i);

	// a != c
	aux = dif(s,s2);
	t[1] = aux.size();	
	for(auto i : aux) nums.insert(i);
	
	// b != c
	aux = dif(s1,s2);
	t[2] = aux.size();
	for(auto i : aux) nums.insert(i);
	
	t2[0] = t[0];
	t2[1] = t[1];
	t2[2] = t[2];

	sort(t,t+3);

	if(t[2] >= 3) print(0);
	if(nums.empty()) print(1);
	if(nums.size() == 1) print(1);
	if(nums.size() >= 4) print(0);

	// cerr << nums.size() << endl;
	// cerr << t[0] << " " << t[1] << " " << t[2] << endl;
	
	if(nums.size() == 3){
		if(t[0] == 2 && t[1] == 2 && t[2] == 2) { conserta(nums,1); print(2); }
		else if(t[0] == 1 && t[1] == 2 && t[2] == 2) print(0);
		else assert(false);
	}

	else if(nums.size() == 2){
		if(t[0] == 2 && t[1] == 2 && t[2] == 2) print(0);
		if(t[0] == 0 && t[1] == 2 && t[2] == 2) print(1);
		else if(t[0] == 1 && t[1] == 2 && t[2] == 2) { conserta(nums,0); print(2); }
		else if(t[0] == 1 && t[1] == 1 && t[2] == 2) { conserta(nums,1); print(2); }
		else assert(false);
	}		
	assert(false);
}

int main(){

	optimize;
	
	cin >> s >> s1 >> s2;

	solve();

	return 0;
}