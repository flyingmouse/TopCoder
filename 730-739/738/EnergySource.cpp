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

set<vector<int> > vis;
vector<int> d[91];

class EnergySource {
public:
    ll sz = 0, ans = 0;

    void dfs(vector<int>& v) {
        if (vis.count(v)) return;
        vis.insert(v);
        sz++;
        ll res = 1;
        for (int x : v) res *= x;
        ans += res;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            for (int x : d[v[i]]) {
                vector<int> w = v;
                w.erase(w.begin() + i);
                REP(j, x) w.push_back(v[i] / x);
                sort(w.begin(), w.end(), greater<int>());
                dfs(w);
            }
        }
	}

    vector<long long> countDifferentSources(int number) {
        for (int i = 1; i <= number; i++) {
            for (int j = 2; j <= i; j++) {
                if (i % j == 0) d[i].push_back(j);
            }
        }
        vector<int> v;
        v.push_back(number);
        dfs(v);
        return {sz, ans};
    }
};
