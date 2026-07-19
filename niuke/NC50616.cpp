//https://ac.nowcoder.com/acm/problem/50616
//sg递归和记忆化搜索
#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;

const int N=2005;

int n,m,k;
int f[N];
vector<int> edge[N];

int sg(int x){
    unordered_set<int> mp;
    if(f[x]!=-1)return f[x];
    for(auto v:edge[x]){
        mp.insert(sg(v));
    }
    for(int i=0;;i++){
        if(!mp.count(i))return f[x]=i;
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        edge[x].push_back(y);
    }
    
    memset(f,-1,sizeof f);

    int ret=0;
    for(int i=1;i<=k;i++){
        int x;cin>>x;
        ret^=sg(x);
    }

    if(ret)cout<<"win\n";
    else cout<<"lose\n";
}