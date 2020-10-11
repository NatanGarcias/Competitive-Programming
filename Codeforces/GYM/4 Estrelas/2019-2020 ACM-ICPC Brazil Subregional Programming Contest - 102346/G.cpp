#include<bits/stdc++.h>
using namespace std;
#define MAXN 2009
#define MAXM 2009
#define INF 0x3f3f3f3f

/*
 * Hungarian's Algorithm O(n^2 m)
 * linhas de 1 a n, colunas de 1 a n
 */

int n, m;
long double pu[MAXN], pv[MAXN], cost[MAXN][MAXM];
int pairV[MAXN], way[MAXM];
long double minv[MAXM];
bool used[MAXM];

void hungarian() {
    memset(&pairV, 0, sizeof pairV);
    for(int i = 1, j0 = 0; i <= n; i++) {
        pairV[0] = i;
        memset(&minv, 1000000000, sizeof minv);
        memset(&used, false, sizeof used);
        do {
            used[j0] = true;
            int i0 = pairV[j0], j1;
            long double delta = INF;
            for(int j = 1; j <= m; j++) {
                if (used[j]) continue;
                long double cur = cost[i0][j] - pu[i0] - pv[j];
                if (cur < minv[j])
                    minv[j] = cur, way[j] = j0;
                if (minv[j] < delta)
                    delta = minv[j], j1 = j;
            }
            for(int j = 0; j <= m; j++) {
                if (used[j])
                    pu[pairV[j]] += delta, pv[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while(pairV[j0] != 0);
        do {
            int j1 = way[j0];
            pairV[j0] = pairV[j1];
            j0 = j1;
        } while(j0);
    }
}

int main() {
    scanf("%d",&n);
    
    m = n;

    long double a;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a;
            cost[i][j] = -log2(a);
        }
    }

    int ans = 0;

    hungarian();
    for(int j = 1; j <= m; j++) {
        cout << pairV[j] << " \n"[j==m];
    }
    return 0;
}