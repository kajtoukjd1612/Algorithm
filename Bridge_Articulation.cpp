#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <bitset>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair< int, int > ii;
typedef pair< int, ii > iii;
const int oo = 1e9 + 7;

int n, m, low[100010], num[100010], Time = 0, res = 0;
vector< int > Adj[100010];
bool art[100010];

void visit(int u, int p) {
     int NumChild = 0;
     low[u] = num[u] = ++Time;
     for (int i = 0 ; i < Adj[u].size() ; ++i) {
          int v = Adj[u][i];
          if(v != p) {
               if(num[v] != 0) low[u] = min(low[u], num[v]);
               else {
                    visit(v, u);
                    NumChild++;
                    low[u] = min(low[u], low[v]);

                    if(low[v] >= num[v]) res++;

                    if(u == p) {
                         if(NumChild >= 2)  art[u] = true;
                    }

                    else {
                         if(low[v] >= num[u])
                         art[u] = true;
                    }
               }
          }
     }
}

main() {
     #ifdef Phong_dz
          freopen("GRAPH_.txt", "r", stdin);
     #endif
     scanf("%d %d", &n, &m);
     for(int i = 0 ; i < m ; ++i) {
          int u, v;
          scanf("%d %d", &u, &v);
          Adj[u].pb(v);
          Adj[v].pb(u);
     }

     for(int i = 1 ; i <= n ; ++i) {
          if(!num[i]) visit(i, i);
     }

     int res1 = 0;
     for(int i = 1 ; i <= n ; ++i) {
          if(art[i]) res1++;
     }

     printf("%d %d", res1, res);
}

