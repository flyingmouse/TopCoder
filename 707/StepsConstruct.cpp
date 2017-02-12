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

int n, m;
int a[55][55];
char h[3005][55][55], dir[6] = "UDLR";
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool can(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !a[x][y];
}

int index(char c) {
    if (c == 'U') return 0;
    else if (c == 'D') return 1;
    else if (c == 'L') return 2;
    else return 3;
}

class StepsConstruct {
    public:
    string construct(vector <string> board, int K) {
        n = board.size(), m = board[0].size();
        REP(i, n) REP(j, m) a[i][j] = (board[i][j] == '#');
        if (a[0][0]) return "";
        h[0][0][0] = '.';
        REP(i, K) REP(j, n) REP(k, m) {
            if (h[i][j][k]) {
                REP(d, 4) {
                    int tx = j + dx[d], ty = k + dy[d];
                    if (can(tx, ty)) {
                        h[i + 1][tx][ty] = dir[d];
                    }
                }
            }
        }
        if (!h[K][n - 1][m - 1]) return "";
        string ans = "";
        int x = n - 1, y = m - 1;
        for (int i = K; i > 0; i--) {
            char c = h[i][x][y];
            int d = index(c);
            ans = c + ans;
            x -= dx[d], y -= dy[d];
        }
        return ans;
    }
};

