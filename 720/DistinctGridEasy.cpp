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

class DistinctGridEasy {
    public:
    string checkGrid(int n, int k, vector <int> grid) {
        set<int> row, col;
        REP(i, n) {
            row.clear(); col.clear();
            REP(j, n) {
                row.insert(grid[i * n + j]);
                col.insert(grid[j * n + i]);
            }
            if (SZ(row) != k || SZ(col) != k)
                return "Bad";
        }
        return "Good";
    }
};
