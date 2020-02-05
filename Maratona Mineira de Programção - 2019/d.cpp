#include<bits/stdc++.h>
using namespace std;


bool cmp(const tuple<int,int,int> &a , const tuple<int,int,int> &b){
	if(get<0>(a) < get<0>(b))
		return false;
	else if (get<0>(a) > get<0>(b))
		return true;
	else
		return get<1>(a) < get<1>(b);
}

int main(){
    int n,k;
    cin >> n >> k;
    
    vector <tuple<int,int,int> > arroz;
 	int a,b,c;
    for(int i=0;i<n;i++){
    	cin >> a >> b >> c;
    	arroz.push_back(make_tuple(b,c,a));
    } 

    sort(arroz.begin(),arroz.end(),cmp);

    cout << get<2>(arroz[--k]) << endl;
    return 0;
}