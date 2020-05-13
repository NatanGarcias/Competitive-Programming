#include<bits/stdc++.h>
using namespace std;

// Template 1
typedef unsigned long long ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MAXN 200010

map<vector<ll>, int> mapa;
vector<ll> v, v2;
bool ans;
ll N,M,sum;

void imprimi(vector<ll> nums){

	for(int i=0;i<nums.size();i++){
		cout << nums[i] << " \n"[i==sz(nums)-1];
	}
}

void bruta(vector<ll> nums){

	auto it = mapa.find(nums);

	if(it == mapa.end()){
	
		for(int i = 1; i < nums.size() -1; i++){

			vector<ll> aux( max( (int)nums.size() - i, i ) );

			if(nums.size() - i > i){
				for(int j = 0; j < nums.size() -i ; j++){
					aux[j] = nums[ nums.size() - j - 1];
				}
				int cont = 0;
				for(int j = nums.size() -i; j < nums.size() ; j++){
					aux[ aux.size() - ++cont] += nums[ nums.size() - j - 1];
				}
			}else{
				for(int j = 0; j < i ; j++){
					aux[j] = nums[j];
				}
				for(int j = i; j < nums.size() ; j++){
					aux[ aux.size() - j+ i - 1] += nums[j];
				}
			}
			bruta(aux);
			reverse(all(aux));
			bruta(aux);

			mapa[aux] = 2;
			reverse(all(aux)); 
			mapa[aux] = 2; 
		}

	}else if( ((*it).se) == 1){
		ans = true;
	}
}

void solve(){

	mapa[ v2 ] = 1;

	ans = false;
	
	if(M == 1){
		if(sum == v2[0]) ans = true;
	}else{
		bruta(v);

		reverse(all(v));

		bruta(v);
	}

	if (ans) cout << "S\n";
	else cout << "N\n";
}

int main(){

	cin >> N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin >> v[i];
		sum+= v[i];
	}	

	cin >> M;
	v2.resize(M);
	for(int i=0;i<M;i++)  cin >> v2[i];

    solve();

	return 0;
}