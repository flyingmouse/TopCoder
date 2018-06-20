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

class SellingFruits {
    public:
    int maxDays(int x, int f, int d, int p) {
        int a = min(f, d / x), b = 0;
        f -= a, d -= a * x;
        if (f == 0) {
            // n * p + n * x <= d
            b = d / (ll(p) + x);
        }
        return a + b;
    }
};


