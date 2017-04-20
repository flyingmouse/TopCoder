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

class ForwardMancala {
    public:
    int isValid(vector<int>& a, int p) {
        int n = a.size();
        REP(i, n) {
            if (i == p) continue;
            if (a[i] != 0) return i;
        }
        return -1;
    }
    vector <int> findMoves(vector <int> a) {
        int n = a.size(), maxx = 0, p;
        vector<int> ans;
        REP(i, n) if (a[i] > maxx) maxx = a[i], p = i;
        int x = isValid(a, p);
        while (x != -1) {
            int nb = a[x];
            a[x] = 0;
            REP(i, nb) a[(x + i + 1) % n]++;
            ans.push_back(x);
            x = isValid(a, p);
        }
        return ans;
    }
};


