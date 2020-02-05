#include<bits/stdc++.h>
using namespace std;

int b;
double temp;
double calc(double a, double b, double c, double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void f(const vector<vector<double>> &dist, int visited[], int ondeEstou, vector<int>&k){
	while(k.size()!=b){
		priority_queue<pair<double,int> >fila;
		for(int i=0;i<k.size();i++){
			for(int j=0;j<dist[i].size();j++){
				if(visited[j] == 0){
					fila.push({-dist[k[i]][j],j});
				}
			}
		}
		temp+=fila.top().first;
		k.push_back(fila.top().second);
		visited[fila.top().second] =1;
	}
}

void prim(const vector<vector<double>> &dist, int visited[], int ondeEstou){
	vector<int> k;
	k.push_back(ondeEstou);
	visited[ondeEstou]=1;
	f(dist,visited,ondeEstou,k); 
}

int main(){
	int a;
	scanf("%d",&a);
	for(int l=0;l<a;l++){
		cin.ignore();
		cin.ignore();
		if(l)
			cout << endl;
		cin >> b;
		vector<vector<double>> v(b,vector<double>(2,0));
		for(int i=0;i<b;i++){
			cin >> v[i][0];
			cin >> v[i][1];
		}
		
		vector<vector<double>> dist(b,vector<double>(b,0));
		for(int i=0;i<b;i++){
			for(int j=i+1;j<b;j++){
				double real = calc(v[i][0],v[i][1],v[j][0],v[j][1]);
				dist[i][j] = real;
				dist[j][i] = real;
			}
		}
		int visited[b] = {0};
		temp=0;
		prim(dist,visited,0);
		cout << fixed << setprecision(2) << abs(temp) << endl;
	}
}