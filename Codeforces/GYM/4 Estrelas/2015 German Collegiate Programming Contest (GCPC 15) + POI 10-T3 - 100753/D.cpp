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

ll T,N,M,K,W,H;
vector<pii> piece;
vector<int> height;

bool solve(int area, int bitmask){

	if(!area) return true;

	for(int j=0;j<N;j++){
		if( bitmask & (1 << j) ) continue;

		int maxAlt = 0;

		//Encontro o lugar onde vou colocar a peça
		for(int i=0;i<W;i++){
			if(height[i] > height[maxAlt]) maxAlt = i;
		}

		//Encontro o espaço que tenho para colocar a peça
		int w = 1, h = height[maxAlt];
		int w2 = piece[j].fi, h2 = piece[j].se;

		int k = maxAlt;
		while(k+1 < W && height[k] == height[k+1]) k++, w++;

		//Tento colocar a peça na horizontal
		if(w2 <= w && h2 <= h){

			for(int i=maxAlt;i < maxAlt + w2;i++){
				height[i] -= h2;
			}

			if( solve( area - w2 * h2 , bitmask | ( 1 << j) ) ) return true;

			for(int i=maxAlt;i < maxAlt + w2;i++){
				height[i] += h2;
			}
		}

		swap(w2,h2);

		//Tento colocar a peça na vertical
		if(w2 <= w && h2 <= h){

			for(int i=maxAlt;i < maxAlt + w2;i++){
				height[i] -= h2;
			}

			if( solve( area - w2 * h2 , bitmask | ( 1 << j) ) ) return true;

			for(int i=maxAlt;i < maxAlt + w2;i++){
				height[i] += h2;
			}
		}
	}

	return false;
}

int main(){

	optimize;
	
	cin >> W >> H;

	cin >> N;

	for(int i=0,a,w,h;i<N;i++){
		cin >> a >> w >> h;

		for(int j=0;j<a;j++){
			piece.pb(pii(w,h));
		}
	}

	N = piece.size();

	height.assign(W,H);

	if( solve(W*H, 0) ) cout << "yes\n";
	else 				cout << "no\n";
    
	return 0;
}