#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,c;
    while(cin >> a){
        vector<int> b;
        for(int i=0;i<a;i++){
            cin >> c;
            b.push_back(c);
        }
        sort(b.begin(),b.end());
        int soma=0;
        int ajuda;
        int outrasoma = 0;
        int k1,k2;
        for(int i=0;i<a;i++){
            k1 =  abs(b[i]-b[i+1]);
            k2 =  24-abs(b[i]-b[i+1]);
            k1<k2?ajuda=k1:ajuda=k2;
            soma += ajuda; 
            i++;
        }
        for(int i=1;i<a-1;i++){
            k1 =  abs(b[i]-b[i+1]);
            k2 =  24-abs(b[i]-b[i+1]);
            k1<k2?ajuda=k1:ajuda=k2;
            outrasoma += ajuda; 
            i++;
        }
        abs(b[0]-b[a-1])<24-abs(b[0]-b[a-1])?ajuda=abs(b[0]-b[a-1]):ajuda=24-abs(b[0]-b[a-1]);
        outrasoma +=ajuda;
        outrasoma>soma?cout<<soma<<endl:cout<<outrasoma<<endl; 
    }

    return 0;
}