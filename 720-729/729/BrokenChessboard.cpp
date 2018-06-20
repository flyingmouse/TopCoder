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

const int maxn = 55;
int a[maxn][maxn];

class BrokenChessboard {
    public:
    int minimumFixes(vector <string> board) {
        int n = board.size(), m = board[0].size();
        REP(i, n) REP(j, m) a[i][j] = board[i][j] == 'W';
        int cnt = 0, x;
        REP(i, n) REP(j, m) {
            x = (i + j) & 1;
            cnt += a[i][j] ^ x;
        }
        return min(cnt, n * m - cnt);
    }
};
