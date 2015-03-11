#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > Adjlist;
bool visited[51] = {false};
int V , M;

bool isBipartite(int root) {
            int colorArr[51];
            for (int i = 1; i <= V; ++i)
                        colorArr[i] = -1;

            colorArr[root] = 1;
            visited[root] = true;

            queue <int> bfs;
            bfs.push(root);

            while (!bfs.empty()) {
                        int u = bfs.front();
                        bfs.pop();

                        for (int i = 0 ; i < Adjlist[u].size() ; ++i) {
                                    int v = Adjlist[u][i];
                                    if(!visited[v] && colorArr[v] == -1) {
                                        colorArr[v] = 1 - colorArr[u];
                                        bfs.push(v);
                                        //cout << v << endl;
                                    }

                                else if (colorArr[v] == colorArr[u])
                                                return false;
                                }
            }

            return true;
}

main() {
            cin >> V >> M;
            Adjlist.assign(V + 1 , vector<int>());
            for(int i = 1 ; i <= M ; ++i) {
                        int u , v;
                        cin >> u >> v;
                        Adjlist[u].push_back(v);
                        Adjlist[v].push_back(u);
            }

            if(isBipartite(1)) cout << "YES";
            else cout << "NO";
}
