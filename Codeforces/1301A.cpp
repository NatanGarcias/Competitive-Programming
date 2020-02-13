#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b,c;

    int n;
    bool ans;
    cin >> n;
    while(n--){
        ans = true;
        cin >> a >> b >> c;

        for(int i=0;i<a.size();i++){
            if(a[i] == c[i] || b[i] == c[i])
                continue;
            else{
                ans = false;
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}