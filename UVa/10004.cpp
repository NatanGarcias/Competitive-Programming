#include<bits/stdc++.h>
using namespace std;

bool g(const vector<vector<int>>& v, int color[],int onde, queue<int> &m){
	while(!m.empty()){
		for(int i=0;i<v[onde].size();i++){
			if(color[v[onde][i]]==0){
				color[v[onde][i]] = -color[onde];
				m.push(v[onde][i]);	
			}
			else{
				if(color[v[onde][i]] == color[onde])
					return false;
			}
		}
		m.pop();
		onde = m.front();
	}
	return true;
}

bool f(const vector<vector<int>>& v, int color[],int onde){
	queue<int> m;
	m.push(onde);
	color[onde] = 1;
	return g(v,color,onde,m);

}

int main(){
	int a,z,c,d;
	while(cin >> z){
		if(!z)
			break;
		cin>>a;
		vector< vector<int>> v(z);
		
		for(int i=0;i<a;i++){
			cin>> c >> d;
			v[c].push_back(d);
			v[d].push_back(c);
		}
		int color[a] = {0};

		bool k = f(v,color,0);
		if(k)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
}