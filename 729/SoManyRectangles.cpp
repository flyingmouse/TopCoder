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

const int maxn = 205;
int used[maxn][maxn];

class SoManyRectangles {
    public:
    int maxOverlap(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
        int n = x1.size();
        vector<int> v;
        REP(i, n) {
            v.push_back(x1[i]);
            v.push_back(y1[i]);
            v.push_back(x2[i]);
            v.push_back(y2[i]);
        }
        sort(ALL(v));
        v.resize(unique(ALL(v)) - v.begin());
        int K = v.size();
        REP(i, n) {
            x1[i] = lower_bound(ALL(v), x1[i]) - v.begin();
            y1[i] = lower_bound(ALL(v), y1[i]) - v.begin();
            x2[i] = lower_bound(ALL(v), x2[i]) - v.begin();
            y2[i] = lower_bound(ALL(v), y2[i]) - v.begin();
        }
        REP(i, n) {
            REPP(j, x1[i], x2[i]) REPP(k, y1[i], y2[i])
                used[j][k]++;
        }
        int ans = 0;
        REP(i, K) REP(j, K) ans = max(ans, used[i][j]);
        return ans;
    }
};
