#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

const double inf = 1e100, eps = 1e-9;
const double PI = acos(-1.0L);

int cmp (double a, double b = 0) {
	if (abs(a-b) < eps) return 0;
	return (a < b) ? -1 : +1;
}

struct PT {
	double x, y;
	PT(double x = 0, double y = 0) : x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (double c) const { return PT(x*c, y*c); }
	PT operator / (double c) const { return PT(x/c, y/c); }

	bool operator <(const PT &p) const {
		if(cmp(x, p.x) != 0) return x < p.x;
		return cmp(y, p.y) < 0;
	}
	bool operator ==(const PT &p) const {
		return !cmp(x, p.x) && !cmp(y, p.y);
	}
	bool operator != (const PT &p) const {
		return !(p == *this);
	}
};

double dot (PT p, PT q) { return p.x * q.x + p.y*q.y; }
double cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }
double dist2 (PT p, PT q = PT(0, 0)) { return dot(p-q, p-q); }
double dist (PT p, PT q) { return hypot(p.x-q.x, p.y-q.y); }
double norm (PT p) { return hypot(p.x, p.y); }
PT normalize (PT p) { return p/hypot(p.x, p.y); }
double angle (PT p, PT q) { return atan2(cross(p, q), dot(p, q)); }
double angle (PT p) { return atan2(p.y, p.x); }
double polarAngle (PT p) {
	double a = atan2(p.y,p.x);
	return a < 0 ? a + 2*PI : a;
}

// Determina se as linhas a - b e c - d sao paralelas ou colineares
bool parallel (PT a, PT b, PT c, PT d) {
 	return cmp(cross(b - a, c - d)) == 0;
}

bool collinear (PT a, PT b, PT c, PT d) {
 	return parallel(a, b, c, d) && cmp(cross(a - b, a - c)) == 0 && cmp(cross(c - d, c - a)) == 0;
}

// Parallel and opposite directions
// Determina se o ponto c esta em um segmento a - b
bool ptInSegment (PT a, PT b, PT c) {
	if (a == b) return a == c;
	a = a-c, b = b-c;
	return cmp(cross(a, b)) == 0 && cmp(dot(a, b)) <= 0;
}

// Determina se o segmento a - b intersecta com o segmento c - d
bool segmentsIntersect (PT a, PT b, PT c, PT d) {
	if (collinear(a, b, c, d)) {
		if (cmp(dist(a, c)) == 0 || cmp(dist(a, d)) == 0 || cmp(dist(b, c)) == 0 || cmp(dist(b, d)) == 0) return true;
		if (cmp(dot(c - a, c - b)) > 0 && cmp(dot(d - a, d - b)) > 0 && cmp(dot(c - b, d - b)) > 0) return false;
	return true;
	}
	if (cmp(cross(d - a, b - a) * cross(c - a, b - a)) > 0) return false;
	if (cmp(cross(a - c, d - c) * cross(b - c, d - c)) > 0) return false;
	return true;
}

// Calcula a intersecao entre as retas a - b e c - d assumindo que uma unica intersecao existe
// Para intersecao de segmentos, cheque primeiro se os segmentos se intersectam e que nao sao paralelos
// r = a1 + t*d1, (r - a2) x d2 = 0
PT computeLineIntersection (PT a, PT b, PT c, PT d) {
	b = b - a; d = c - d; c = c - a;
	assert(cmp(cross(b, d)) != 0);
	return a + b * cross(c, d) / cross(b, d);
}

ll T,N,M,K;
vector<vector<pair<PT,PT>>> adj;

bool f(pair<PT,PT> &A, pair<PT,PT> &B, pair<PT,PT> &C){

    if(collinear(A.fi, A.se, B.fi, B.se)){
        //Reta A totalmente dentro
        if(ptInSegment(B.fi, B.se, A.fi) && ptInSegment(B.fi, B.se, A.se)){
            C = A;
            return true;
        }
        //Reta B totalmente dentro
        else if(ptInSegment(A.fi, A.se, B.fi) && ptInSegment(A.fi, A.se, B.se)){
            C = B;
            return true;
        }
        // B.fi - A.se
        else if(ptInSegment(A.fi, A.se, B.fi) && ptInSegment(B.fi, B.se, A.se)){
            C.fi = B.fi;
            C.se = A.se;
            return true;
        }
        // A.fi - B.se
        else if(ptInSegment(B.fi, B.se, A.fi) && ptInSegment(A.fi, A.se, B.se)){
            C.fi = A.fi;
            C.se = B.se;
            return true;
        }
        else if(ptInSegment(A.fi, A.se, B.fi) && ptInSegment(A.fi, A.se, B.se)){
            C = B;
            return true;
        }
        return false;
    }
    else if(parallel(A.fi, A.se, B.fi, B.se)){
        return false;
    }
    else if(segmentsIntersect(A.fi, A.se, B.fi, B.se)){
        C.fi = computeLineIntersection(A.fi, A.se, B.fi, B.se);
        C.se = C.fi;

        if(C.fi.x - int(C.fi.x) > eps) return false;
        if(C.fi.y - int(C.fi.y) > eps) return false;
        return true;
    }

    return false;
}

void solve(){

    vector<pair<PT,PT>> resp;
    resp = adj[N-1];

    for(int i=0;i<N-1;i++){

        vector<pair<PT,PT>> resp2;
        pair<PT,PT> aux;

        for(int k=0;k<resp.size();k++){
            for(int j=0;j<adj[i].size();j++){
                if( f(resp[k], adj[i][j], aux) )
                    resp2.pb(aux);
            }

        }

        resp = resp2;
    }

    bool ok = true;

    for(int i=0;i<resp.size();i++){
        if(resp[0].fi != resp[i].fi || resp[0].fi != resp[i].se) ok = false;
    }

    if(resp.empty()) cout << "impossible\n";
    else if(ok) cout << (int) resp[0].fi.x << " " << (int) resp[0].fi.y << endl;
    else cout << "uncertain\n";
}

int main(){

	optimize;
	
	cin >> N;
    
    adj.resize(N);

    for(int i=0,x,y,r;i<N;i++){
        cin >> x >> y >> r;

        if(r == 0) adj[i].pb(make_pair(PT(x,y), PT(x,y)));
        else if(r == 1){
            adj[i].pb(make_pair(PT(x-r,y), PT(x,y-r)));
            adj[i].pb(make_pair(PT(x,y+r), PT(x+r,y)));
        }
        else{
            adj[i].pb(make_pair(PT(x-r,y), PT(x-1,y+r-1)));
            adj[i].pb(make_pair(PT(x-r+1,y-1), PT(x-1,y-r+1)));
            adj[i].pb(make_pair(PT(x,y+r), PT(x+r,y)));
            adj[i].pb(make_pair(PT(x,y-r), PT(x+r-1,y-1)));
        }
    }

	solve();

	return 0;
}