#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define endl "\n"
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 200020

int v[MAXN];

int main(){

    optimize;
    
    ll n,k;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    if(n==1LL){
        cout << v[0]+k << endl;
        return 0;
    }

    sort(v,v+n);

    ll med = n/2;

    priority_queue<ll> pq;

    for(ll i=med;i<n;i++){
        pq.push(-v[i]);
    }

    med++;

    while(k>0){
        
        ll x = -pq.top();
        pq.pop();

        ll temp = max(k/med,1LL);

        x += temp;

        pq.push(-x);

        k-= temp;
    }

    cout << -pq.top() << endl;
}