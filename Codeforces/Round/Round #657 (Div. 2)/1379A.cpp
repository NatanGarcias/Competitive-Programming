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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
string s;
const string a = "abacaba";

void print(string &s2){
	cout << "Yes\n";

	for(int i=0;i<N;i++){
		if(s2[i] == '?') s2[i] = 'z';
		cout << s2[i];
	}
	cout << endl;
}

int match(string &s2){
	
	int cnt = 0;

	for(int i=0;i<N-6;i++){
		bool ok = true;

		for(int j=0;j<7;j++){
			if(s2[i+j] != a[j]) ok = false;
		}

		if(ok) cnt++;
	}

	return cnt;
}

void solve(){

	int cnt = match(s);

	if(cnt == 1){
		print(s);
		return;
	}
	else if(cnt > 1){
		cout << "No\n";
		return;
	}

	vector<int> ptr, ptr2, pos;

	for(int i=0;i<N;i++){
		ptr2.clear();

		for(int j=0;j<ptr.size();j++){

			int aux = ptr[j];

			if(s[i] == a[aux] || s[i] == '?') {
				if(aux == 6) 	pos.pb(i-6);
				else 			ptr2.pb(aux+1);
			}
		}

		ptr = ptr2;

		if(s[i] == 'a' || s[i] == '?'){
			ptr.pb(1);
		}
	}

	if(pos.empty()){
		cout << "No\n";
		return;
	}
	else{
		for(int i=0;i<pos.size();i++){
			string s2 = s;

			for(int j=0;j<7;j++){
				s2[pos[i]+j] = a[j];
			}

			if(match(s2) == 1){
				print(s2);
				return;
			}
		}
	}

	cout << "No" << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> s;
		
		solve();
    }

	return 0;
}