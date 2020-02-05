#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n%2==0){
        cout << ((n+1)*(n+2))/2 << endl;
    }
    else
        cout << (((n+1)*(n+2))/2 -(n/2)) << endl;
        
    return 0;
}