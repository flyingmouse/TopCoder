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
        int a[m];
        fill(a, a + m, -1);
        REP(i, n) {
            REP(j, m) {
                int val = grid[i * m + j] % m;
                if (a[j] < 0) a[j] = val;
                else if (a[j] != val) return "Impossible";
            }
        }
        return "Possible";
    }
};
