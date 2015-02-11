#include <bits/stdc++.h>
using namespace std;

char dp[100][100];

int visited[100][100];
int n,cont,I,J;
vector<string> v;
pair<int,int> Parent[100][100];
pair<int, int> P;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool bl=false;

void floodfill(int a, int b){
        cont++;
        memset(visited,0,sizeof visited);
        stack< pair<int, int> > X;
        Parent[a][b]=make_pair(0,0);
        X.push(make_pair(a,b));

        while(!X.empty()){
                P=X.top();
                X.pop();
                visited[P.first][P.second]=1;

                for(int i=0;i<4;i++){
                        I=P.first+dx[i];
                        J=P.second+dy[i];
                        if(I==a && J==b && Parent[P.first][P.second]!=make_pair(a,b)) {
                                bl=true;
                                break;
                        }
                        if(dp[I][J]==dp[P.first][P.second] && !visited[I][J]) {
                                Parent[I][J] = make_pair(P.first,P.second);
                                X.push(make_pair(I,J));
                        }
                }
                if(bl) break;
        }

}
