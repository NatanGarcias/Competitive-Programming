#include<bits/stdc++.h>
using namespace std;
int main(){
    int b;
    cin >> b;
    vector< tuple<int, int, string> > v;
    string aux;
    int sub[4];
    int temp[4];
    int soma,soma1;
    for(int i=0;i<b;i++){
        cin >> aux;
        for(int j=0;j<4;j++){
            cin >> sub[j];
            cin >> temp[j];
        }
        soma=soma1=0;
        for(int j=0;j<4;j++){
            if(temp[j]){
                soma+= ((sub[j]-1)*20)+temp[j];
                soma1--; 
            }
            v.push_back(make_tuple(soma1,soma,aux));
        }
    }
    sort(v.begin(),v.end());

    cout << get<2>(v[0]) << " " << abs(get<0>(v[0])) << " " << get<1>(v[0]) << endl;
  return 0;
}