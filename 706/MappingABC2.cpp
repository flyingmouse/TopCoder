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

const int mod = 1e9 + 7;

class MappingABC2 {
    public:
    void add(int &x, int y) {
        x += y;
        if (x >= mod) x -= mod;
    }

    int mul(int x, int y) {
        return 1LL * x * y % mod;
    }

    int countStrings(vector <int> t) {
        int n = t.size();
        vector<int> a;
        int mask[55], ans = 0;
        REP(i, n) REPP(j, i + 1, n) REPP(k, j + 1, n) {
            memset(mask, 0, sizeof(mask));
            REP(l, n) mask[t[l]] = 7;
            REP(l, n) {
                if (l < i) mask[t[l]] &= 6;
                else if (l == i) mask[t[l]] &= 1;
                else if (l < j) mask[t[l]] &= 5;
                else if (l == j) mask[t[l]] &= 2;
                else if (l < k) mask[t[l]] &= 3;
                else if (l == k) mask[t[l]] &= 4;
            }
            int cur = 1, ind;
            REP(l, n) {
                ind = t[l];
                if (mask[ind] == -1) continue;
                if (mask[ind] == 0) cur = 0;
                else if (mask[ind] == 1 || mask[ind] == 2 || mask[ind] == 4) cur = mul(cur, 1);
                else if (mask[ind] == 7) cur = mul(cur, 3);
                else cur = mul(cur, 2);
                mask[ind] = -1;
            }
            add(ans, cur);
        }
        return ans;
    }
};


