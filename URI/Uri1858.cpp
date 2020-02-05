#include<bits/stdc++.h>
using namespace std;

int main(){
	int a;
	cin >> a;
	vector<pair<int,int>>b;
	int c;
	for(int i=0;i<a;i++){
		cin >> c;
		b.push_back({c,i+1});
	}
	sort(b.begin(),b.end());
	cout << b[0].second << endl;

}