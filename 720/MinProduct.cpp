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

class MinProduct {
    public:
    long long findMin(vector <int> amount, int blank1, int blank2) {
        vector<int> digits;
        int n = blank1 + blank2;
        REP(i, 10) REP(j, amount[i])
            if (digits.size() < n)
                digits.push_back(i);
        ll ans = 1LL << 62;
        REP(i, 1 << n) {
            ll a = 0, b = 0;
            int cnt = 0;
            REP(j, n) {
                if ((1 << j) & i) {
                    a = 10 * a + digits[j];
                    cnt++;
                } else {
                    b = 10 * b + digits[j];
                }
            }
            if (cnt == blank1)
                ans = min(ans, a * b);
        }
        return ans;
    }
};
