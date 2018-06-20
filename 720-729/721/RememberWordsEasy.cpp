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

class RememberWordsEasy {
    public:
    ll calc(int a, int n, int sign) {
        int b = max(a + sign * (n - 1), 0);
        return 1LL * (a + b) * ((b - a) * sign + 1) / 2;
    }

    int getMin(int d, int w) {
        int res = 0;
        while (calc(res, d, 1) < 1LL * w) res++;
        return res;
    }

    int getMax(int d, int w) {
        int res = w;
        while (calc(res, d, -1) > 1LL * w) res--;
        return res;
    }

    string isPossible(int d1, int d2, int w1, int w2) {
        int min1 = getMin(d1, w1), max1 = getMax(d1, w1);
        int min2 = getMin(d2, w2), max2 = getMax(d2, w2);
        if (max(min1, min2) <= min(max1, max2) + 1)
            return "Possible";
        else
            return "Impossible";
    }
};
