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
#include <unordered_map>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int N = 55;
int x[N], u[N][N], v[N][N], dp[N][N];
bool canBeReplaced[N][N][N];
vector<pii> edges[N][N];

class TreeMovingDiv2 {
    public:
    void add(int &a, int b) {
        a += b;
        if (a >= mod) a -= mod;
    }

    bool dfs(int treeId, int edgeId, int from, int to, int prev=-1) {
        if (from == to) return true;
        for (pii edge : edges[treeId][from]) {
            int u = edge.first, id = edge.second;
            if (u == prev) continue;
            if (dfs(treeId, edgeId, u, to, from)) {
                canBeReplaced[treeId][edgeId][id] = true;
                return true;
            }
        }
        return false;
    }

    int count(int n, vector <int> roots, vector <int> a, vector <int> b, vector <int> c) {
        int m = roots.size();
        REP(i, m) {
            x[0] = c[i];
            REPP(k, 1, n - 1) {
                x[k] = (1LL * a[i] * x[k - 1] + b[i]) % mod;
            }
            REP(j, n - 1) {
                u[i][j] = (roots[i] + j + 1) % n;
                v[i][j] = (roots[i] + (x[j] % (j + 1))) % n;
                edges[i][u[i][j]].push_back(MP(v[i][j], j));
                edges[i][v[i][j]].push_back(MP(u[i][j], j));
            }
        }
        REP(i, n) edges[m][i] = edges[0][i];

        REP(i, m) REP(j, n - 1) {
            dfs(i + 1, j, u[i][j], v[i][j]);
        }
        int ans = 0;
        REP(i, n - 1) {
            memset(dp, 0, sizeof(dp));
            dp[0][i] = 1;
            REPP(j, 1, m + 1) REP(p, n - 1) REP(k, n - 1) {
                if (canBeReplaced[j][p][k])
                    add(dp[j][k], dp[j - 1][p]);
            }
            add(ans, dp[m][i]);
        }
        return ans;
    }
};


