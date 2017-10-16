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

class TCPhoneHome {
    public:
    long long validNumbers(int digits, vector <string> prefixes) {
        ll pow[20];
        pow[0] = 1;
        REP(i, 18) pow[i + 1] = pow[i] * 10;
        ll ans = pow[digits];
        sort(ALL(prefixes));
        vector<string> useful;
        REP(i, prefixes.size()) {
            bool ok = true;
            REP(j, i) {
                if (prefixes[j].size() < prefixes[i].size() &&
                    prefixes[i].substr(0, prefixes[j].size()) == prefixes[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                useful.push_back(prefixes[i]);
        }
        for (auto v : useful)
            ans -= pow[digits - v.size()];
        return ans;
    }
};
