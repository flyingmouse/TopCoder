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

class GridSort {
    public:
    string sort(int n, int m, vector <int> grid) {
        if (n == 1) return "Possible";
        REP(i, n) {
            set<int> sd;
            REP(j, m) {
                int val = (grid[i * m + j] - 1) / m;
                sd.insert(val);
            }
            if (SIZE(sd) != 1) return "Impossible";
        }
        REP(i, m) {
            set<int> sr;
            REP(j, n) {
                int val = grid[j * m + i] % m;
                sr.insert(val);
            }
            if (SIZE(sr) != 1) return "Impossible";
        }
        return "Possible";
    }
};
