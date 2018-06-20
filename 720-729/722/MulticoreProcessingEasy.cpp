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

class MulticoreProcessingEasy {
    public:
    int calc(int job, int speed, int core, int corePenalty) {
        int capacity = speed * core;
        int res = job / capacity;
        if (job % capacity != 0) res++;
        res += corePenalty * (core - 1);
        return res;
    }

    int fastestTime(int jobLength, int corePenalty, vector <int> speed, vector <int> cores) {
        int n = speed.size();
        int d, ans = 2e9;
        REP(i, n) REPP(j, 1, cores[i] + 1) {
            d = calc(jobLength, speed[i], j, corePenalty);
            ans = min(ans, d);
        }
        return ans;
    }
};
