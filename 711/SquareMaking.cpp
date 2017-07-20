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

class SquareMaking {
    public:
    int getMinimalPrice(int a, int b, int c, int d) {
        int v[] = {a, b, c, d};
        sort(v, v + 4);
        int ans = v[1] - v[0] + v[2] - v[1] + v[3] - v[1];
        return ans;
    }
};


