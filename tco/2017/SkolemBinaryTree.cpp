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

class SkolemBinaryTree {
    public:
    vector <int> construct(int k) {
        vector<int> ans;
        if (k == 1) {
            int a[2] = {0,1};
            REP(i, 2) ans.push_back(a[i]);
            return ans;
        }
        if (k == 2) {
            int a[6] = {0,1,1,2,1,3};
            REP(i, 6) ans.push_back(a[i]);
            return ans;
        }
        int a[10] = {0,1,0,5,0,2,2,4,3,4};
        REP(i, 10) ans.push_back(a[i]);
        REPP(i, 6, 2 * k) {
            int j;
            if (i == 6) j = 2;
            else if (i == 7) j = 3;
            else if (i == 8) j = 6;
            else if (i == 9) j = 3;
            else if ((i - 10) % 4 == 0 || (i - 10) % 4 == 3) j = i - 4;
            else j = i - 2;
            ans.push_back(i);
            ans.push_back(j);
        }
        return ans;
    }
};
