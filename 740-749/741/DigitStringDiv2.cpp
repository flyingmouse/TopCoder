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

class DigitStringDiv2 {
    public:
    int count(string s, int x) {
        int n = s.size();
        int ans = 0;
        REP(i, n) REPP(j, i, n) {
            if (s[i] == '0') continue;
            if (stoi(s.substr(i, j - i + 1)) > x) ans++;
        }
        return ans;
    }
};
