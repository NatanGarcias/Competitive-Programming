#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define INF 0x3f3f3f3f
#define ull unsigned long long int

ull n,m,k;

ull somaI(ull a){
	return (a*(a+1))/2;
}

int main(){
    cin >> k;

    while(cin >> n >> m){
        ull total = somaI(n);
        ull espacos = m+1;

        ull zeros = n-m;

        ull a = zeros/espacos;
        ull b = zeros%espacos;

        total-= ((b) * somaI(a+1));
        total-= ((espacos-b) * somaI(a));

        cout << total << endl;
    }
    return 0;
}