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
    ll pow(int n) {
        ll res = 1;
        while (n--) res *= 10;
        return res;
    }

    bool isPart(string a, string b) {
        // if a is a part of b
        if (a.size() >= b.size()) return false;
        int n = a.size();
        REP(i, n) if (a[i] != b[i]) return false;
        return true;
    }

    long long validNumbers(int digits, vector <string> specialPrefixes) {
        ll ans = pow(digits);
        sort(ALL(specialPrefixes));
        vector<string> useful;
        string prev = specialPrefixes.empty() ? "" : specialPrefixes[0];
        for (auto v : specialPrefixes) {
            if (isPart(prev, v)) continue;
            useful.push_back(v);
            prev = v;
        }
        for (auto v : useful)
            ans -= pow(digits - v.size());
        return ans;
    }
};
