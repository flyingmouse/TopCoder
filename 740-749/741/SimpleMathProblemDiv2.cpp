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

const int maxn = 5e5 + 5;
int n, primes[100000], divp[maxn];

class SimpleMathProblemDiv2 {
    public:
    void init() {
        for (int i = 2; i < maxn; i++) if (divp[i] == 0) {
            primes[n++] = i;
            for (ll j = 1LL*i*i; j < maxn; j += i) {
                if (divp[j] == 0) divp[j] = i;
            }
        }
    }

    long long calculate(int X) {
        init();
        ll ans = 0;
        REP(i, n) {
            int x = 1;
            for (int j = primes[i]; j <= X; j += primes[i]) {
                if (1LL * x * primes[i] <= j) x *= primes[i];
                ans += x;
            }
        }
        return ans;
    }
};
