#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define endl "\n"
#define space " "
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;

int main(){

    int n;

    cin >> n;

    ll v[n];

    FOR(i,n){
        cin >> v[i];
    }   

    ll ptr = 0;
    ll ptr2 = n;
    ll somaA = 0;
    ll somaB = 0;
    ll maior = 0;

    while(ptr < ptr2){
        ptr2--;
        somaB += v[ptr2];

        while(ptr < ptr2 && somaA < somaB){
            somaA+= v[ptr];
            ptr++;
        }
        if(somaA == somaB){
            maior = max(maior,somaA);
        }

    }
    cout << maior << endl;
    return 0;
}