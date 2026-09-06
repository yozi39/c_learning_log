#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,m,pa,ret[N];
vector<int> edge[N];

void dfs(int x,int r){
    ret[x]=r;

    for(auto v:edge[x]){
        if(ret[v])continue;
        dfs(v,r);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        edge[y].push_back(x);
    }

    for(int i=n;i>=1;i--){
        if(ret[i])continue;
        dfs(i,i);
    }

    for(int i=1;i<=n;i++){
        cout<<ret[i]<<' ';
    }
}