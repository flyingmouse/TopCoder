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

bool a[26][26];

class AlphabetOrderDiv2 {
    public:
    string isOrdered(vector <string> words) {
        int n = words.size();
        REP(i, n) {
            string word = words[i];
            REPP(j, 1, SIZE(word)) {
                int x = word[j] - 'a', y = word[j - 1] - 'a';
                if (x == y) continue;
                a[x][y] = true;
                REP(k, 26) if (a[y][k]) a[x][k] = true;
                REP(k, 26) if (a[x][k] && a[k][x]) return "Impossible";
            }
        }
        return "Possible";
    }
};

