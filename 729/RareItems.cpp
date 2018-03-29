
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

const int N = 20;
double p[N], dp[1 << N];

class RareItems {
    public:
    double expectedPurchases(vector <int> frequency) {
        int n = frequency.size(), sum = 0;
        REP(i, n) sum += frequency[i];
        REP(i, n) p[i] = (double) frequency[i] / sum;
        int m = (1 << n) - 1;
        dp[m] = 0;
        for (int mask = m - 1; mask >= 0; mask--) {
            double c1 = 0, c2 = 0;
            REP(i, n) {
                if (mask & (1 << i)) c1 += p[i];
                else c2 += p[i] * dp[mask | (1 << i)];
            }
            c2 += 1;
            dp[mask] = c2 / (1 - c1);
        }
        return dp[0];
    }
};
