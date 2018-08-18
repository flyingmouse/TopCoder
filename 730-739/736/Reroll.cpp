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

class Reroll {
    public:
    int minimumDice(int target, vector <int> dice) {
        int n = dice.size(), sum = 0;
        REP(i, n) sum += dice[i];
        int diff = sum - target;
        sort(ALL(dice));
        int ans = 0;
        if (diff > 0) {
            PER(i, n) {
                ans++;
                diff -= dice[i] - 1;
                if (diff <= 0) break;
            }
        } else if (diff < 0) {
            REP(i, n) {
                ans++;
                diff += 6 - dice[i];
                if (diff >= 0) break;
            }
        }
        return ans;
    }
};
