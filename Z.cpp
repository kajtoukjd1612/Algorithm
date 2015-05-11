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

int z[2000010];
string a, b;

void Z(int n, string s) {
     int L = 0, R = 0;
     for(int i = 1 ; i < n ; i++) {
          if(i > R) {
               L = R = i;
               while(R < n && s[R - L] == s[R]) R++;
               z[i] = R - L; R--;
          }
          else {
               int k = i - L;
               if(z[k] < R - i + 1) z[i] = z[k];
               else {
                    L = i;
                    while(R < n && s[R - L] == s[R]) R++;
                    z[i] = R - L; R--;
               }
          }
     }
}

