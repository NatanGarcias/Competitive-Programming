/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://shygypsy.com/tools/
 * LICENSE:
 *      http://shygypsy.com/tools/LICENSE.html
 * Copyright (c) 2006
 * Contact author:
 *      abednego at gmail.c0m
 **/

/****************
 * Maximum flow * (Dinic's on an adjacency list + matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency 
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * RUNNING TIME:
 *      - O(n^3)
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission (Gives WA, but it's probably my graph building that's wrong)
 *      - Valladolid 563:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * 
 **/
#include <bits/stdc++.h>
using std::cin;
using std::min;
using std::endl;
using std::cout;
using std::string;
using std::stringstream;

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int cap[NN][NN], deg[NN], adj[NN][NN];

// BFS stuff
int q[NN], prev[NN];

int dinic( int n, int s, int t )
{
    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        int qf = 0, qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prev[v = adj[u][i]] == -1 && cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // try finding more paths
        for( int z = 0; z < n; z++ ) if( cap[z][t] && prev[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
                bot = min(bot,cap[u][v]);
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}

//----------------- EXAMPLE USAGE -----------------
int main()
{

	int n, s, t, m;
	int cont;

    cin >> cont;

    while(cont--){
        // read a graph into cap[][]
	    memset( cap, 0, sizeof( cap ) );

        int k;

        //Numero de camisas e numero de arestas
        cin >> k >> m;
        
        k = k/6;
        
        n = m+9;

        //Ligo o sorvedouro em cada pessoa com valor 1
        for(int i=1;i<=m;i++)
            cap[0][i] = 1;
        
    	string a,b;

        // Liga a pessoa as 2 camisas que ela escolheu
        for(int i=0;i<m;i++){
            cin >> a >> b;
            if(a == "XXL")
                cap[i+1][m+1]++;
            else if(a== "XL")
                cap[i+1][m+2]++;
            else if(a== "L")
                cap[i+1][m+3]++;
            else if(a== "M")
                cap[i+1][m+4]++;
            else if(a== "S")
                cap[i+1][m+5]++;
            else if(a== "XS")
                cap[i+1][m+6]++;
            
            if(b == "XXL")
                cap[i+1][m+1]++;
            else if(b== "XL")
                cap[i+1][m+2]++;
            else if(b== "L")
                cap[i+1][m+3]++;
            else if(b== "M")
                cap[i+1][m+4]++;
            else if(b== "S")
                cap[i+1][m+5]++;
            else if(b== "XS")
                cap[i+1][m+6]++;

        }

        //Ligo o tamanho das camisas na vazao com valor k 
        // Pois só tem k camisas de cada tipo
        for(int i=m+1;i<=m+1+6;i++){
            cap[i][m+8] = k;
        }

	    // init the adjacency list adj[][] from cap[][]
	    memset( deg, 0, sizeof( deg ) );
	    for( int u = 0; u < n; u++ )
	        for( int v = 0; v < n; v++ ) if( cap[u][v] || cap[v][u] )
	            adj[u][deg[u]++] = v;
        
        if(dinic( n, 0, m+8 ) >= m )
            cout << "YES\n";
        else    cout << "NO\n";
    }

    return 0;
}