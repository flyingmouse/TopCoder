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

class HungryCowsEasy {
    public:
    vector <int> findFood(vector <int> cowPositions, vector <int> barnPositions) {
        vector<int> ans;
        int m = barnPositions.size();
        for (int p : cowPositions) {
            int x = 0;
            REP(i, m) {
                int d = abs(barnPositions[i] - p) - abs(barnPositions[x] - p);
                if (d < 0) x = i;
                else if (d == 0 && barnPositions[i] < barnPositions[x]) x = i;
            }
            ans.push_back(x);
        }
        return ans;
    }
};

