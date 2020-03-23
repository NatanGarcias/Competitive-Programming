#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)

#define mod %1000000007

int T;
ld a,b,c;

int main(){

	cin >> T;

	ld maior = -999999.0;
	int pos = -1;

	FOR(i,T){
		cin >> a >> b;

		c = b * log(a);

		if(c > maior){
			maior = c;
			pos = i;
		}
	}

	cout << pos << endl;

	return 0;
}