#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL cx1, cy1, cx2, cy2;
int n;

LL calDis(LL x1, LL y1, LL x2, LL y2) {
    LL dx = x1 - x2;
    LL dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main() {
    cin >> cx1 >> cy1 >> cx2 >> cy2;
    cin >> n;

    vector<pair<LL, LL>> d(n);

    for (int i = 0; i < n; i++) {
        LL x, y;
        cin >> x >> y;

        d[i].first = calDis(x, y, cx1, cy1);
        d[i].second = calDis(x, y, cx2, cy2);
    }

    sort(d.begin(), d.end(),
         [](const pair<LL, LL>& a, const pair<LL, LL>& b) {
             return a.first > b.first;
         });

    LL ret = d[0].first;
    LL r2 = 0;

    for (int i = 0; i < n; i++) {
        r2 = max(r2, d[i].second);

        LL r1 = 0;

        if (i + 1 < n) {
            r1 = d[i + 1].first;
        }

        ret = min(ret, r1 + r2);
    }

    cout << ret;
    return 0;
}