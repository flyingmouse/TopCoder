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

class TCPhoneHomeEasy {
    public:
    int pow(int n) {
        int res = 1;
        while (n--) res *= 10;
        return res;
    }

    int validNumbers(int n, vector <string> specialPrefixes) {
        int ans = pow(n);
        for (string s : specialPrefixes) {
            ans -= pow(n - s.size());
        }
        return ans;
    }
};
