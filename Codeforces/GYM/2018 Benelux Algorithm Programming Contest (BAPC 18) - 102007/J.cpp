#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ld long double 

#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff

ld v[4];

ld f(ld D){

	ld ans = 0;
	
	for(int i=0;i<4;i+=2){

		ld l = min(v[i],v[i+1]);
		ld L = max(v[i],v[i+1]);
		ld x = (l*l - L*L + D*D) / (2.0*D);

		ld h = sqrt(l*l - x*x);

		if(D > l + L)
			return 0.0;

		ans+= ((D - x) * h)/2.0;
		ans+= (x * h)/2.0;	
	}

	return ans;
}

ld ternarySearch(){

	ld l = 10E-4, r = 2.0*max({v[0],v[1],v[2],v[3]}) , eps = 10E-13;

	while(abs(l-r) > eps){

		ld m1 = l + (r-l)/3.0;
		ld m2 = l + 2.0*( (r-l)/3.0 );

		ld f1 = f(m1);
		ld f2 = f(m2);

		//Para encontrar o minimo da funcao basta colocar f1 <= f2 na condição
		if(f1 >= f2){
			r = m2;
		}else{
			l = m1;
		}
	}

	return l;
}

int main(){

	for(int i=0;i<4;i++){
		cin >> v[i];
	}
	
	ld ans = 0;

	do{
		ld temp = f(ternarySearch());
		ans = max(ans,temp);
	}while(next_permutation(v,v+4));
	
	cout << fixed << setprecision(8) << ans << endl;

    return 0;
}