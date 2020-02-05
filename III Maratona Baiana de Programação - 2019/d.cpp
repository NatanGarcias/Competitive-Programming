#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<string> v;
    int a, b, c;
    cin >> a >> b >> c;
    if(a <= 30 && b <= 12){
        v.push_back("d-m-a");
    }
    if(a <= 30 && c <= 12){
        v.push_back("d-a-m");
    }
    if(b <= 30 && a <= 12){
        v.push_back("m-d-a");
    }
    if(b <= 30 && c <= 12){
        v.push_back("a-d-m");
    }
    if(c <= 30 && a <= 12){
        v.push_back("m-a-d");
    }
    if(c <= 30 && b <= 12){
        v.push_back("a-m-d");
    }

    if(v.size() == 0){
        cout << "invalida\n";
    }
    else if(v.size() > 1){
        cout << "ambigua\n";
    }
    else{
        cout << v[0] << endl;
    }
}