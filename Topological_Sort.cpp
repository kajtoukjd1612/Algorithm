#include <bits/stdc++.h>
using namespace std;

vector< int > G[30], toposort;
bool visited[30], used[30];
string s[105];
int n;

void dfs(int u) {
    visited[u] = used[u] = true;
    for(int i = 0 ; i < G[u].size() ; ++i) {
        int v = G[u][i];
        if(used[v]) {
            printf("Impossible");
            exit(0);
        }
        else if(!visited[v]) {
            dfs(v);
        }
    }

    used[u] = false;
    toposort.push_back(u);
}

void func(int u) {
    for(int i = 0 ; i < s[u].size() && i < s[u + 1].size() ; ++i) {
        if(s[u][i] != s[u + 1][i]) {
            G[s[u + 1][i] - 'a'].push_back(s[u][i] - 'a');
            return;
        }
    }

    if(s[u].size() > s[u + 1].size()) {
        printf("Impossible");
        exit(0);
    }
}

main() {
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++i) {
        cin >> s[i];
    }

    for(int i = 1 ; i < n ; ++i) {
        func(i);
    }

    for(int i = 0 ; i < 26 ; ++i) {
        if(!visited[i]) dfs(i);
    }
    for(int i = 0 ; i < 26 ; ++i) {
        printf("%c", toposort[i] + 'a');
    }
}
