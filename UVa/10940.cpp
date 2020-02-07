#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    while(cin >> a){  
        if(a==0)
            break;
        if(a==1)
            cout << 1 << endl;
        else{
            if(int(log2(a))-log2(a)==0){
                cout << a  << endl;
            }
            else{
                int aux = int(pow(2,int(log2(a))));
                cout <<(a-(aux))*2  << endl;
            }
        }
    }
    return 0;

}