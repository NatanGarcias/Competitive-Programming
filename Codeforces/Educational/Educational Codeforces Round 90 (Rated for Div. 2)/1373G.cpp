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
ll T,N,M,K;

int nums[2 * MAXN], seg[8 * MAXN], lazy[8 * MAXN];
set<pii> coor;
set<int> s;

void build(int p, int tl, int tr){
    if(tl == tr){
        seg[p] = tl-1;
    }else{
        int tm = (tl+tr)/2;
	    int e = (p << 1);
		int d = (p << 1) | 1;

        build(e,tl,tm);
        build(d,tm+1,tr);
        
        seg[p] = max(seg[e], seg[d]);
    }
}

void push(int p , int tl, int tr){

    int e = (p << 1);
	int d = (p << 1) | 1;

    seg[p] += lazy[p];

    if(tl != tr){
	    lazy[e] += lazy[p];
	    lazy[d] += lazy[p];
	}
	
	lazy[p] = 0;
}

int query(int p, int tl, int tr, int a, int b){
	
	push(p,tl,tr);

	if(a > tr || b < tl) return 0;
	
	if(a <= tl && tr <= b){
		return seg[p];
	}

	int tm = (tl + tr)/2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	return max(query(e,tl,tm,a,b), query(d,tm+1,tr,a,b));
}

void update(int p, int tl, int tr, int a, int b, int z){

    push(p,tl,tr);

    if(a > tr || b < tl){
        return;
    }else if(tl >= a && tr <= b){
        lazy[p] += z;
        push(p,tl,tr);
        return;
    }else{
        int tm = (tl+tr)/2;
        int e = (p << 1);
		int d = (p << 1) | 1;

        update(e,tl,tm,a,b,z);
        update(d,tm+1,tr,a,b,z);
        
        seg[p] = max(seg[e], seg[d]);
    }
}

int qry(int l, int r){
	return query(1, 1, 2*N, l, r);
}

void upd(int l, int r, int x){
	update(1, 1, 2*N, l, r, x);
}

int getAns(){
	if(s.empty()) return 0;
	return max(0LL , qry(1, *s.rbegin()) - N);
}

int main(){

	optimize;
	
	cin >> N >> M >> K;
	
	build(1,1,2*N);

	for(int i=0;i<K;i++){
		int a, b;

		cin >> a >> b;

		int p = abs(a - M) + b;

		if(coor.count(pii(a,b))){
			nums[p]--;

			if(!nums[p]) s.erase(p);

			upd(1, p, -1);
			coor.erase(pii(a,b));
		}
		else{
			nums[p]++;

			if(nums[p] == 1) s.insert(p);

			upd(1, p, 1);
			coor.insert(pii(a,b));
		}

		cout << getAns() << endl;
	}

	return 0;
}