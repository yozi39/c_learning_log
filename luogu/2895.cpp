#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int N = 505;
const int INF = 1e9;

int m;
int danger[N][N];
int dista[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    cin >> m;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            danger[i][j] = INF;
            dista[i][j] = -1;
        }
    }

    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;

        danger[x][y] = min(danger[x][y], t);

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                danger[nx][ny] = min(danger[nx][ny], t);
            }
        }
    }

    if (danger[0][0] == 0) {
        cout << -1;
        return 0;
    }
    //bfs
    queue<PII> q;
    q.push({0, 0});
    dista[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (danger[x][y] == INF) {
            cout << dista[x][y];
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nt = dista[x][y] + 1;

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                continue;
            } if (dista[nx][ny] != -1) {
                continue;
            } if (nt >= danger[nx][ny]) {
                continue;
            }

            dista[nx][ny] = nt;
            q.push({nx, ny});
        }
    }

    cout << -1;
    return 0;
}