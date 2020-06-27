#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,a,b,c;

	cin >> n;

	while(n--){
		
		cin >> a >> b >> c;

		if((a - b + c) <= 0)
			cout << 0 << endl;
		else if(!c)
			cout << 1 << endl;
		else if(a > b+c)
			cout << c+1 << endl;
		else
			cout << ((a - b + c)/2) + ((a - b + c)%2) << endl; 
	}
    return 0;
}