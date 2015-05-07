#include <bits/stdc++.h>
using namespace std;

/* Disjoint Set */
vector<int> Setname(1001),Setsize(1001);
int NumSet;

void InitSet(int n) {
    NumSet = n;
    Setsize.assign(n,1);
    Setname.assign(n,0);
    for(int i=0;i<n;++i) Setname[i] = i;
}

int Findset(int n) {
    if(Setname[n] == n) return n;
    else return Findset(Setname[n]);
}

bool Sameset(int i,int j) {
    return Findset(i) == Findset(j);
}

void Union(int i,int j) {
    if(!Sameset(i,j)) {
        NumSet--;
        Setsize[Findset(i)] += Setsize[Findset(j)];
        Setname[Findset(i)] = Findset(j);
    }
}
/* end */

/* Dsu by rank */
int Rank[1001],Parent[1001];

void Createset(int i) {
        Parent[i] = i;
        Rank[i] = 0;
}

int Findset(int i) {
        if(i != P[i]) P[i] = Findset(P[i]);
        return P[i];
}

void Union(int i,int j) {
        int Pi = Findset(i);
        int Pj = Findset(j);
        if(Rank[Pi] > Rank[Pj]) Parent[Pj] = Pi;
        else Parent[Pi] = Pj;
        if(Rank[Pi] == Rank[Pj]) Rank[Pj] += 1;
}

bool sameset(int i, int j) {
        return findset(i) == findset(j);
}
/* end */

