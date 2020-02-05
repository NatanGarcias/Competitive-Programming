#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,c,pico;
   while(cin >> a){
        if(a==0)
            break;
        vector<int> b;
        for(int i=0;i<a;i++){
            cin >> c;
            b.push_back(c);
        }
        pico = 0;
        if(b[0]>b[a-1] && b[0] >b[1])
                    pico++;
        if(b[0]<b[a-1] && b[0] <b[1])
                    pico++;
        if(b[a-1]>b[a-2] && b[a-1] >b[0])
                    pico++;
        if(b[a-1]<b[a-2] && b[a-1] <b[0])
                    pico++;

        for(int i=1;i<a-1;i++){
            if(b[i]>b[i-1] && b[i] >b[i+1])
                    pico++;
            if(b[i]<b[i-1] && b[i] <b[i+1])
                    pico++;
        }

        cout << pico << endl;
    }
    return 0;
}