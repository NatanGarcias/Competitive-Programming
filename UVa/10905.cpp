#include<bits/stdc++.h>
using namespace std;

bool sorr(string b, string a){
   return (b+a) > (a+b);
}
int main(){
    int a;
    while(cin >> a){
        if(a==0)
            break;
        vector<string> b;
        string c;
        for(int i=0;i<a;i++){
            cin >> c;
            b.push_back(c);
        }
        for(int i=1;i<a;i++){
            string elementoInserir=b[i];
            int j= i-1;
            while(j>=0 && !(sorr(b[j],elementoInserir))){  
                b[j+1]=b[j];
                j--;
            }
            b[j+1]=elementoInserir;
        }
        string total;
        for(int i=0;i<a;i++){
            total+= b[i];
        }
        cout << total << endl;
    }
    return 0;
}