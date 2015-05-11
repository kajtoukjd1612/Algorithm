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

vector< int > Adj[40010];
vector< int > color[40010];
int n, m, q, visit[40010], parent[25][40010], lv[40010];

void dfs(int s) {
     visit[s] = 1;
     for(int i = 0 ; i < Adj[s].size() ; ++i) {
          int u = Adj[s][i];
          if(!visit[u]) {
               parent[0][u] = s;
               lv[u] = lv[s] + 1;
               dfs(u);
          }
     }
}

int lca(int x, int y) {
     for(int i = 20 ; i >= 0 ; --i) { if(lv[parent[i][x]] >= lv[y]) x = parent[i][x]; }
     for(int i = 20 ; i >= 0 ; --i) { if(lv[parent[i][y]] >= lv[x]) y = parent[i][y]; }
     for(int i = 20 ; i >= 0 ; --i) { if(parent[i][x] != parent[i][y]) { x = parent[i][x]; y = parent[i][y]; } }

     while(x != y) {
          x = parent[0][x];
          y = parent[0][y];
     }

     return x;
}

void init() {
     for(int i = 1 ; i < 21 ; ++i) {
          for(int j = 1 ; j <= n ; ++j) {
               parent[i][j] = parent[i - 1][parent[i - 1][j]];
          }
     }
}
