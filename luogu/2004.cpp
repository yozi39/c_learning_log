#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 1e3 + 5;

int n, m, c;
LL s[N][N];

int main(){
    cin >> n >> m >> c;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            LL x;
            cin >> x;

            s[i][j] = x
                    + s[i - 1][j]
                    + s[i][j - 1]
                    - s[i - 1][j - 1];
        }
    }

    LL ret = LLONG_MIN;
    pair<int, int> pos;

    for(int i = 1; i <= n - c + 1; i++){
        for(int j = 1; j <= m - c + 1; j++){
            int x2 = i + c - 1;
            int y2 = j + c - 1;

            LL sum = s[x2][y2]
                   - s[i - 1][y2]
                   - s[x2][j - 1]
                   + s[i - 1][j - 1];

            if(sum > ret){
                ret = sum;
                pos = {i, j};
            }
        }
    }

    cout << pos.first << ' ' << pos.second;
}