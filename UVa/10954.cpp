#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    while(cin >> a){
        if(a==0)
            break;
        int aux=0;
        int temp =0;
        vector<int>somas2;
        int d;
        for(int i=0;i<a;i++){
            cin >> d;
            somas2.push_back(d);
        }
        sort(somas2.begin(),somas2.end());
        for(int i=1;i<a;i++){
            temp=somas2[i-1]+somas2[i];
            somas2[i-1] = temp;
            aux+=temp;
            sort(somas2.begin()+i-1,somas2.end());
            }
        cout << aux << endl;
    }
    return 0;
}