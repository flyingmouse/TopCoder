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

class ForumPostMedium {
    public:
    int getSeconds(string& time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    string getShownPostTime(string currentTime, string exactPostTime) {
        int t1 = getSeconds(currentTime), t2 = getSeconds(exactPostTime);
        int ago = t1 - t2;
        if (ago < 0) ago += 3600 * 24;
        if (ago < 60) return "few seconds ago";
        else if (ago < 3600) return to_string(ago / 60) + " minutes ago";
        else return to_string(ago / 3600) + " hours ago";
    }
};
