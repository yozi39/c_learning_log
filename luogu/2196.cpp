#include<bits/stdc++.h>
using namespace std;

const int N=25;

int n,ret=0;
int a[N];
vector<int> e[N];
vector<int> path;
vector<int> bestPath;

void dfs(int x, int now) {
    path.push_back(x);
    now += a[x];

    if (now > ret) {
        ret = now;
        bestPath = path;
    }

    for (auto v : e[x]) {
        dfs(v, now);
    }

    path.pop_back();
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int cnt=1;cnt<=n;cnt++){
        for(int i=1+cnt;i<=n;i++){
            int x;cin>>x;
            if(x==1){
                e[cnt].push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
    }
    
    for(auto v:bestPath)cout<<v<<' ';
    cout<<'\n'<<ret;
}