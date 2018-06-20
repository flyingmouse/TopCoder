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

class Cross {
    public:
    string exist(vector <string> board) {
        int n = board.size(), m = board[0].size();
        REPP(i, 1, n - 1) REPP(j, 1, m - 1) {
            if (board[i][j] == '#' && board[i - 1][j] == '#' && board[i + 1][j] == '#' &&
                board[i][j - 1] == '#' && board[i][j + 1] == '#')
                return "Exist";
        }
        return "Does not exist";
    }
};


