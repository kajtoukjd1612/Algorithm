#include <bits/stdc++.h>
using namespace std;
 
int parent[21][1001];
int n, root, t, q;
int Level[1001];
 
void Root() {
    for(int i = 1 ; i <= n ; ++i) {
        if(parent[0][i] == 0) root = i;
    }
    parent[0][root] = root;
}
 
int level(int x) {
    if(x == root) return 1;
    if(Level[x]) return Level[x];
    return Level[x] = level(parent[0][x]) + 1;
}
 
int lca(int x, int y) {
    for(int i = 20 ; i >= 0 ; --i) if(level(parent[i][x]) >= level(y)) {x = parent[i][x];}
    for(int i = 20 ; i >= 0 ; --i) if(level(parent[i][y]) >= level(x)) {y = parent[i][y];}
    for(int i = 20 ; i >= 0 ; --i) if(parent[i][x] != parent[i][y]) { x = parent[i][x]; y = parent[i][y]; };
 
    while(x != y) {
        x = parent[0][x];
        y = parent[0][y];
    }
 
    return x;
}
 
main() {
    //freopen("LCA.in","r",stdin);
    scanf("%d", &t);
    for(int k = 1 ; k <= t ; ++k) {
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; ++i) {
            int u, v;
            scanf("%d", &u);
            while(u--) {
                scanf("%d", &v);
                parent[0][v] = i;
            }
        }
 
        //printf("1");
 
        Root();
        for(int i = 1 ; i < 21 ; ++i) {
            for(int j = 1 ; j <= n ; ++j) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
 
        //printf("2");
        scanf("%d", &q);
        printf("Case %d:\n", k);
        while(q--) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", lca(u, v));
        }
    }
}
