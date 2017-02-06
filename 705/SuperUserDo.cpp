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

const int maxn = 1005;
int a[maxn];

class SuperUserDo {
    public:
    int install(vector <int> A, vector <int> B) {
        int n = A.size(), ans = 0;
        REP(i, n) {
            REPP(j, A[i], B[i] + 1) a[j] = 1;
        }
        REP(i, maxn) ans += a[i];
        return ans;
    }
};

