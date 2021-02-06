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

#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
string s,s2;

typedef struct node{
    int prior,size,val,sum,lazy,rev;
    struct node *l,*r;
}node;

typedef node* pnode;

int sz(pnode t){
    return t ? t->size : 0;
}

void upd_sz(pnode t){
    if(t)	t->size = sz(t->l) + 1 + sz(t->r);
}

void lazy(pnode t){
    if(!t)	return;
	
	if(t->rev){
		t->val ^= 1;
		swap(t->l, t->r);
		
		if(t->l)	t->l->rev ^= 1;
		if(t->r)	t->r->rev ^= 1;
		
		t->rev = 0;
	}
}

void reset(pnode t){
    if(t) 	t->sum = t->val;
}

void combine(pnode& t,pnode l,pnode r){
    if(!l || !r)	return void(t = l?l:r);
    t->sum = l->sum + r->sum;
}

void operation(pnode t){
    if(!t)	return;
    
    reset(t);
    
    lazy(t->l);
    lazy(t->r);
    
    combine(t,t->l,t);
    combine(t,t,t->r);
}

void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)	return void(l = r = NULL);

    lazy(t);
    
    int curr_pos = add + sz(t->l);
    
    if(curr_pos<=pos)	
    	split(t->r,t->r,r,pos,curr_pos+1) , l = t;
    else 
        split(t->l,l,t->l,pos,add) , r = t;
    
    upd_sz(t);
    operation(t);
}

void merge(pnode &t,pnode l,pnode r){

    lazy(l);
    lazy(r);
    
    if(!l || !r) t = l ? l : r;
    else if(l->prior > r->prior) 	merge(l->r,l->r,r),t = l;
    else    merge(r->l,l,r->l),t = r;
    
    upd_sz(t);
    operation(t);
}

pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    
    ret->prior = rng();
    ret->size = 1;
    ret->val = val;
    ret->rev = 0;
	ret->l = ret->r = NULL;
    
    return ret;
}

int range_query(pnode t,int l,int r){
    
    pnode L,mid,R;
    
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    
    int ans = t->val;
    
    merge(mid,L,t);
    merge(t,mid,R);
    
    return ans;
}

void reverse(pnode t, int l, int r){
	
	pnode L,mid,R;
    
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    
    t->rev ^= 1;
    
    merge(mid,L,t);
    merge(t,mid,R);
}

void print(pnode t){
	if(!t)	return;

	if(t->l) print(t->l);
	
	cout << t->val << " ";
	
	if(t->r) print(t->r);
}

void solve(){

	vector<int> ans;
	pnode treap = NULL;

	for(auto &i : s){
		merge(treap, treap, init(i&1));
	}

	for(int i=N-1;i>=0;i--){
		if( (s2[i]&1) == range_query(treap, i, i)) continue;

		if(i && (s2[i]&1) == range_query(treap, 0, 0)){
			ans.pb(1);
			reverse(treap,0,0);	
		}

		reverse(treap,0,i);	

		ans.pb(i+1);
	}

	cout << ans.size();
	for(int i=0;i<ans.size();i++){
		cout << " " << ans[i];
	}
	cout << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

		cin >> s >> s2;

		solve();
    }

	return 0;
}