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

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 100010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll sum;
ll v[MAXN];
int v2[MAXN];

map<pii,ll> mapa;
multiset<ll> ms;
set<pii> s;
ll seg[4*MAXN];

void build(int p, int tl , int tr){
	if(tl == tr){
		seg[p] = v[tl-1];
	}else{
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) +1;

		build(e,tl,tm);
		build(d,tm+1,tr);

		seg[p] = seg[e]+seg[d];
	}
}	

ll query(int p, int tl, int tr, int a, int b){
	if(a > tr || b < tl) return 0;
	else if(tl >= a && tr <= b){
		return seg[p];
	}else{
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) +1;

		return query(e,tl,tm,a,b) + query(d,tm+1,tr,a,b);
	}
}

void solve(){

	ll ans = 0;

	build(1,1,N);
	s.insert(pii(0,N-1));
	mapa[pii(0,N-1)] = sum;
	ms.insert(sum);
		
	FOR(i,0,N-1){

		int aux = v2[i];
		
		auto it = s.lower_bound({aux, INF});
		it--;
		pii itr = *it;
		
		auto it2 = ms.find(mapa[itr]); 
		s.erase(itr);

		ms.erase(it2);

		if(aux == itr.fi && aux == itr.se);
		else if(aux == itr.fi){
			ll q = query(1,1,N,itr.fi+2,itr.se+1);
			ms.insert(q);
			mapa[pii(itr.fi+1,itr.se)] = q;
			s.insert(pii(itr.fi+1,itr.se));
		
		}else if(aux == itr.se){
			ll q = query(1,1,N,itr.fi+1,itr.se);
			ms.insert(q);
			mapa[pii(itr.fi,itr.se-1)] = q;
			s.insert(pii(itr.fi,itr.se-1));
		
		}else{
			ll q = query(1,1,N,itr.fi+1,aux);
			ms.insert(q);
			mapa[pii(itr.fi,aux-1)] = q;
			s.insert(pii(itr.fi,aux-1));

			q = query(1,1,N,aux+2,itr.se+1);
			ms.insert(q);
			mapa[pii(aux+1,itr.se)] = q;
			s.insert(pii(aux+1,itr.se));
		}

		cout << *(ms.rbegin()) << endl;
	}

	cout << 0 << endl;
}	

int main(){

	cin >> N;

	FOR(i,0,N){
		cin >> v[i];

		sum+= v[i];
	}

	FOR(i,0,N){
		cin >> v2[i];
		v2[i]--;
	}

	solve();

	return 0;
}