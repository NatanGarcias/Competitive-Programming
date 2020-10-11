#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define mod %1000000007
#define number 1000000007
#define t 3

struct Matriz{
	ll m[t][t];

	Matriz operator * (const Matriz &p){
		Matriz ans;

		for(int i=0;i<t;i++){
			for(int j=0;j<t;j++){
				for(int k = ans.m[i][j] = 0;k<t;k++){
					ans.m[i][j] = (ans.m[i][j] + m[i][k] * p.m[k][j]) mod;
				}
			}
		}

		return ans;
	} 
};

void complete(Matriz &A, ll nums[] ){

	A.m[0][0] = nums[0];
	A.m[0][1] = nums[1];
	A.m[0][2] = nums[2];

	A.m[1][0] = nums[3];
	A.m[1][1] = nums[4];
	A.m[1][2] = nums[5];

	A.m[2][0] = nums[6];
	A.m[2][1] = nums[7];
	A.m[2][2] = nums[8];
}

void imprimi(Matriz a){

	for(int i = 0; i < t; i++) {
  		for(int j = 0; j < t; j++){
    		cout << setw(2) << a.m[i][j] << " ";
  		}cout << endl;
  	}
}

ll fastExpoN(ll a, ll n) {
	ll ret = 1;
	ll b = a;
  	while (n) {
    	if (n & 1)
     	 	ret = (ret * b) mod; // if(n==odd)
    	b = (b * b) mod;
    	n >>= 1;
  	}
  	return (ll)ret;
}

Matriz fastExpoM(Matriz A, ll n) {
	
	Matriz ret;

	ll nums[] = {1,0,0 , 0,1,0 , 0,0,1};

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

int main(){

	ll N;

	cin >> N;

	if(N==1){
		cout << 2 << endl;
	}else if(N==2){
		cout << 24 << endl;
	}else{

		Matriz resp;
		Matriz third;
		Matriz fibo;

		ll respM[] = {1,1,0 , 1,0,0 , 0,1,0 };
		ll thirdM[] = {3,0,0 , 1,0,0 , 0,0,0 };
		ll fiboM[] = {1,1,0 , 1,0,0 , 0,0,0 };

		complete(resp, respM);
		complete(third, thirdM);
		complete(fibo, fiboM);

		Matriz ans = fastExpoM(resp, N-2);
		
		ans = ans * third;

		ll ans2 = fastExpoN(2,N+1);

		Matriz ans3 = fastExpoM(fibo, N-1);

		ll GN = ( ( (ans.m[0][0] + ans3.m[0][0]) mod ) + number -1 ) mod;
		
		ll respostaF = (GN + GN - N - 1 + number ) mod;

		cout << (respostaF * ans2)  mod << endl;
	}
	return 0;
}