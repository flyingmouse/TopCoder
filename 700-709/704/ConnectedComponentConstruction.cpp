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
const int maxn = 55;

class ConnectedComponentConstruction {
    public:
    vector <string> construct(vector <int> s) {
        int n = SIZE(s);
        vector<string> ans;
        vector<int> vs[maxn];
        REP(i, n) {
            if (s[i] > 1)
                vs[s[i]].push_back(i);
        }
        REP(i, maxn) {
            int t = SIZE(vs[i]);
            if (t > 0 && t % i != 0)
                return ans;
        }
        string st = "";
        REP(i, n) st += "N";
        REP(i, n) ans.push_back(st);
        REP(i, maxn) {
            int t = SIZE(vs[i]);
            if (t == 0) continue;
            REP(j, t / i) {
                REPP(k, j * i, (j + 1) * i - 1) REPP(l, k + 1, (j + 1) * i) {
                    ans[vs[i][k]][vs[i][l]] = 'Y';
                    ans[vs[i][l]][vs[i][k]] = 'Y';
                }
            }
        }
        return ans;
    }
};
