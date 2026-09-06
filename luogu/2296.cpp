#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;

int n,m,in[N],s,t;
int ret=1e9;
vector<int> e1[N],e2[N];

bool st[N];
void dfs(int x){
    st[x]=true;
    for(auto v:e2[x]){
        if(!st[v]){
            dfs(v);
        }
    }
}

bool check(int x){
    if(!st[x])return false;
    for(auto v:e1[x]){
        if(!st[v])return false;
    }
    return true;
}

int dist[N];
int bfs(int s){
    memset(dist,0x3f,sizeof dist);
    if(!check(s))return -1;
    dist[s]=0;
    queue<int> q;
    q.push(s);

    while (q.size())
    {
        auto a=q.front();q.pop();

        for(auto v:e1[a]){
            if(!check(v) || dist[v]!=0x3f3f3f3f)continue;
            dist[v]=dist[a]+1;
            q.push(v);
        }     
    }
    
    if(dist[t]==0x3f3f3f3f)return -1;
    return dist[t];
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    cin>>s>>t;

    dfs(t);

    cout<<bfs(s);
}