#include<bits/stdc++.h>

using namespace std;

bool cmp(tuple<int, int, int, string> &a, tuple<int, int, int, string> &b){
    if(get<0>(a) != get<0>(b))
        return get<0>(a) > get<0>(b);
    if(get<1>(a) != get<1>(b))
        return get<1>(a) > get<1>(b);
    if(get<2>(a) != get<2>(b))
        return get<2>(a) > get<2>(b);
    if(get<3>(a) != get<3>(b))
        return get<3>(a) < get<3>(b);
}

int main(){
    vector<tuple<int,int,int, string>> times;
    map<string, int>pos;
    string s;
    for(int i=0;i<4;i++){
        cin >> s;
        pos[s] = i;
        times.push_back({0,0,0,s});
    }
    int jogos;
    cin >> jogos;
    string s1,s2;
    int placar,placar2;
    for(int i=0;i<jogos;i++){
        cin >> s1 >> placar >> s2 >> placar2;
        if(placar > placar2){
            get<0>(times[pos[s1]]) += 3;
            get<1>(times[pos[s1]]) += 1;
            get<2>(times[pos[s1]]) += placar - placar2;
            get<2>(times[pos[s2]]) += -placar + placar2;
        }
        else if(placar < placar2){
            get<0>(times[pos[s2]]) += 3;
            get<1>(times[pos[s2]]) += 1;
            get<2>(times[pos[s2]]) += -placar + placar2;
            get<2>(times[pos[s1]]) += +placar - placar2;
        }
        else{
            get<0>(times[pos[s1]]) += 1;
            get<0>(times[pos[s2]]) += 1;
        }
    }

    sort(times.begin(), times.end(), cmp);
    cout << get<3>(times[0]) << endl;
    cout << get<3>(times[1]) << endl;
    
}