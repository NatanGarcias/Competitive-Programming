#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int i=0;i<n;i++)

int gasto(int x){

    int ans = 0;

    int maior = 1000000000;

    while(x >=10){
        
        if(x>=maior){
            ans += maior/10;
            x = x - maior + maior/10;
        }else{
            maior/=10;
        }
    }

    return ans;
}

int main(){

    int N,n;

    cin >> N;

    while(N--){
        cin >> n;

        cout << n + gasto(n) << endl;
    }
    return 0;
}