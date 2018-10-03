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

class DriveTheCarEasy {
    public:
    long long calculateDistance(int s, int n, vector <int>& speed_changes, vector <int>& moments) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * (s - moments[i] + 1) * speed_changes[i];
        }
        return ans;
    }
};
