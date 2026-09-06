#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;

int n,m,w;
int we[N],fa[N],v[N];
vector<pair<int,int>> a;

int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

void un(int x,int y){
    int fx=find(x);
    int fy=find(y);
    fa[fx]=fy;
}

int main(){
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++){
        cin>>we[i]>>v[i];

    }
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        un(x,y);
    }

    int groupW[N]={}, groupV[N]={};

    for (int i = 1; i <= n; i++) {
        int root = find(i);

        groupW[root] += we[i];
        groupV[root] += v[i];
    }

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            a.push_back({groupW[i], groupV[i]});
        }
    }

    int dp[10005] = {};

    for (int i = 0; i < (int)a.size(); i++) {
        int cost = a[i].first;
        int value = a[i].second;

        for (int j = w; j >= cost; j--) {
            dp[j] = max(dp[j], dp[j - cost] + value);
        }
    }

    cout << dp[w];
}