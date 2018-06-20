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

const int maxn = 1e6 + 10;
int f[maxn], size[maxn];

class GCDGraph {
    public:
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void Union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa, pb);
        size[pa] += size[pb];
        f[pb] = pa;
    }
    string possible(int n, int k, int x, int y) {
        REP(i, n + 1) f[i] = i, size[i] = 1;
        REPP(i, k + 1, n + 1) {
            for (int j = 2 * i; j <= n; j += i)
                Union(i, j);
        }
        if (find(x) == find(y)) return "Possible";
        return "Impossible";
    }
};
