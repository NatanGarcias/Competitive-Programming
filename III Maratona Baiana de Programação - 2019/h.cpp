#include<bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long int i;
    cin >> i;
    if(i == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << (unsigned long long int)log2(i) + 1 << endl;
}