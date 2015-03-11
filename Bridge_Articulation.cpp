#include<bits/stdc++.h>
using namespace std;

vector<long long> Adjlist[100001];
bool articulation[100000];
long long num[100001], low[100001], parent[100001], curtime = 0, root, children;

long long a1/*articulation*/, a2/*bridge*/;
void dfs(int x) {
    num[x] = low[x] = ++curtime;
    for(int i = 0 ; i < Adjlist[x].size() ; ++i) {
        long long cur = Adjlist[x][i];
        if(!num[cur]) {
            parent[cur] = x;
            if(parent[cur] == root) ++children;
            dfs(cur);
            if(low[cur] >= num[x]) {
                articulation[x] = true;
            }
            if(low[cur] > num[x]) {
                ++a2;
            }
            low[x] = min(low[cur], low[x]);
        }
        else if(cur != parent[x]) {
            low[x] =min(num[cur], low[x]);
        }
    }
}


main() {
    long long n, m, a, b;
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++i) {
        cin >> a >> b;
        Adjlist[a].push_back(b);
        Adjlist[b].push_back(a);
    }
    for(int j = 1 ; j <= n ; ++j) {
        if(!num[j]) {
            root = j;
            children = 0;
            dfs(j);
            articulation[j]=(children>1);
        }
    }
    for(int i = 1 ; i <= n ; ++i) {
        if(articulation[i]) ++a1;
    }
    cout << a1 << " " << a2;
}
