#include<bits/stdc++.h>
using namespace std;

// Template 1
typedef long long ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MAXN 200010

#define mod 1000000
#define t 2

ll N,X,Y;

struct Matriz{
	ll m[t][t];

	Matriz operator * (const Matriz &p){
		Matriz ans;

		for(int i=0;i<t;i++){
			for(int j=0;j<t;j++){
				for(int k = ans.m[i][j] = 0;k<t;k++){
					ans.m[i][j] = (ans.m[i][j] + m[i][k] * p.m[k][j]) % mod;
				}
			}
		}

		return ans;
	} 
};

void complete(Matriz &A, ll nums[] ){

	A.m[0][0] = nums[0];
	A.m[0][1] = nums[1];

	A.m[1][0] = nums[2];
	A.m[1][1] = nums[3];
}

void imprimi(Matriz a){

	for(int i = 0; i < t; i++) {
  		for(int j = 0; j < t; j++){
    		cout << setw(2) << a.m[i][j] << " ";
  		}cout << endl;
  	}
}

Matriz fastExpoM(Matriz A, ll n) {
	
	Matriz ret;

	ll nums[] = {1,0, 0,1};

	complete(ret,nums);
	
	Matriz b = A;
  	
  	while (n) {
    	if (n & 1)
     	 	ret = (ret * b);
    	b = (b * b);
    	n >>= 1;
  	}
  	return ret;
}

void solve(){

    Matriz A,B;

    ll nums[4] = {X % mod,Y % mod,1,0};
    ll nums2[4] = {X % mod ,0,1,0};

    complete(A,nums);
    complete(B,nums2);

	A = fastExpoM(A,N-1);

	A = A*B;

    cout << setfill('0') << setw(6) << A.m[0][0] << endl;
}

int main(){

	cin >> N >> X >> Y;

    N /= 5;

    solve();

	return 0;
}