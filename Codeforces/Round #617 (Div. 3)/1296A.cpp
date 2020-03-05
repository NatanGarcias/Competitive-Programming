#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int i=0;i<n;i++)

int main(){

    int N,n,aux;

    cin >> N;

    while(N--){
        cin >> n;

        bool odd,even;

        odd = even = 0;
        
        FOR(i,n){
            cin >> aux;
            if(aux % 2){
                odd = true;
            }else{
                even = true;
            }
        }

        if((odd && even) || (odd && n&1)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;    
        }
    }
    return 0;
}