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

class SwapAndArithmetic {
    public:
    string able(vector <int> x) {
        int n = SIZE(x);
        if (n == 1) return "Possible";
        sort(ALL(x));
        int d = x[1] - x[0];
        REP(i, n - 1) {
            if (d != x[i + 1] - x[i]) return "Impossible";
        }
        return "Possible";
    }
};
