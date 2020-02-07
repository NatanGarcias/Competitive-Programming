#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    int cont,d;
    cont =0;
    x:
    while(cin >> a){
        cin.ignore();
        string x1,x2,x3,x4;
        if(a==0)
            break;
        for(int i=0;i<a;i++){
            string s;
            getline(cin,s);
            x1+=s;
            x1+='\n';
        }
        cin >> b; 
        cin.ignore();
        for(int i=0;i<b;i++){
            string s;
            getline(cin,s);
            x2+=s;
            x2+='\n';
        }
        if(x1==x2){
            cout << "Run #" << ++cont << ": Accepted" << endl;
            goto x;
        }
        for(int i=0;i<x1.size();i++){
            if((x1[i]>'0'-1 && x1[i]<'9'+1) || x1[i]=='-'){
                x3+=x1[i];
            }
        }
        for(int i=0;i<x2.size();i++){
            if((x2[i]>'0'-1 && x2[i]<'9'+1) || x2[i]=='-'){
                x4+=x2[i];
            }
        }
        if(x3==x4)
            cout << "Run #" << ++cont << ": Presentation Error" << endl;
        else
            cout << "Run #" << ++cont << ": Wrong Answer" << endl;
    }
    return 0;
}