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

class ReverseAndIncrease {
    public:
    int digits(ll a) {
        int nb = 0;
        while (a) {
            a /= 10;
            nb++;
        }
        return nb;
    }

    string isPossible(long long s, long long t) {
        if (s <= t) return "Possible";
        if (digits(s) > digits(t)) return "Impossible";
        if (digits(s) == 1) return "Impossible";
        if (digits(s) != digits(s + 1)) return "Impossible";
        if (digits(t) != digits(t - 2)) return "Impossible";
        return "Possible";
    }
};
