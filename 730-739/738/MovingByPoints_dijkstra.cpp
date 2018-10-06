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
        int adj[n][n];
        REP(i, n) REPP(j, i, n) {
            adj[i][j] = adj[j][i] = max(abs(x[i] - x[j]) + abs(y[i] - y[j]) - 1, 0);
        }
        vector<int> dist(n, inf);
        dist[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(MP(0, 0));
        vector<bool> vis(n, false);
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            REP(v, n) if (v != u && !vis[v]) {
                if (dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                    pq.push(MP(dist[v], v));
                }
            }
            vis[u] = true;
        }
        return dist[n - 1];
    }
};
