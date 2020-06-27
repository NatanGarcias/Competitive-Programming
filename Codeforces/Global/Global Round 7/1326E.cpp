#include<bits/stdc++.h>
using namespace std;

typedef long long ull;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)
#define sz(x) (ll) x.size()
#define all(x) x.begin(),x.end()
#define MAXN 300010
#define ms(x) memset(x,0,sizeof(x))

int s[4*MAXN];
int l[4*MAXN];

void build(){
	ms(s);
	ms(l);
}

void push(int z){
	if(l[z]){
		s[z] += l[z];
		
		if( (z<<1) < 4 * MAXN ){
			l[ (z << 1) ] += l[z];
			l[ (z << 1) +1 ] += l[z];
		}
		l[z] = 0;
	}
}

void update(int z, int tl, int tr, int a, int b, int v){

	push(z);

	if(a > tr || b < tl){
		return;
	}

	if(tl >= a && tr <= b){
		l[z] += v;
		push(z);
		return;
	}
	
	int tm = (tl+tr)/2;
	int e = (z << 1);
	int d = (z << 1) + 1;

	update(e,tl,tm,a,b,v);
	update(d,tm+1,tr,a,b,v);

	s[z] = min(s[e],s[d]);	
}

int query(){
	push(1);

	return s[1];
}

int N;
int nums[MAXN];
int nums2[MAXN];
int pos[MAXN];

bool decrease(int x){

	update(1, 1, N, 1, pos[x], -1);
	if(query() >= 0){
		return true;
	}else{
		update(1, 1, N, 1, pos[x], +1);
		return false;		
	}
}

int main(){

	cin >> N;

	build();

	FOR(i,N){
		cin >> nums[i];
		pos[nums[i]] = i+1;
	}

	FOR(i,N){
		cin >> nums2[i];
	}
    
    int ans = N;
    vector<int> sol;
    
    sol.push_back(N);

    FOR(i,N-1){
    	update(1, 1, N, 1, nums2[i], +1);
    	
    	while(decrease(ans)) ans--;

    	sol.push_back(ans);
    }

    FOR(i,N){
    	cout << sol[i] << " \n"[i==N-1];
    }

	return 0;
}