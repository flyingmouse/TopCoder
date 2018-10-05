#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;

class MovingByPoints {
    public:
    int countMinimumPoints(int n, vector <int> x, vector <int> y) {
        int dist[n][n];
        REP(i, n) REP(j, n) dist[i][j] = max(abs(x[i] - x[j]) + abs(y[i] - y[j]) - 1, 0);
        REP(k, n) REP(i, n) REP(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        return dist[0][n - 1];
    }
};
