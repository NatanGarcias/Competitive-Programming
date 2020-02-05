#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,faltaram;
    string s;
    while(true){
        cin >> a;
        if(!a)
            break;
        cin >> s;
        faltaram =0;
        vector<bool> b(a,0);
        vector<char> e(a,0);
        for(int i=0;i<s.size();i++){
            for(int j=0;j<a;j++){
                if(s[i]==e[j]){
                    b[j] = false;
                    e[j] = 1;
                    goto x;
                }
            }
            for(int j=0;j<a;j++){
                if(!b[j]){
                    e[j] = s[i];
                    b[j] = true;
                    break;
                }
                if(j==a-1)
                    faltaram++;
            }
            x:
            int k;
        }
        if(!faltaram)
            cout << "All customers tanned successfully." << endl;
        else
            cout << faltaram/2 << " customer(s) walked away." << endl;
    }
    return 0;
}