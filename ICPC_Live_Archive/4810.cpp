#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    while(getline(cin,a)){
        if(a[0]=='*')
            break;
        bool ganhei = true;
        char aux = tolower(a[0]);
        for(int i=0;i<a.size();i++){
            if(a[i] == ' '){
                if(tolower(a[i+1])!= aux)
                    ganhei = false;
            }
        }
        if(ganhei)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}