#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=1e4+5;

int n,m,s,t;
vector<PII> edge[N];

int ret=0,minret=1e9;
bool st[N];
int dist[N];
void solve(){
    memset(dist,0x3f,sizeof dist);

    priority_queue<PII,vector<PII>,greater<PII>> heap;
    dist[s]=0;
    heap.push({0,s});

    while(!heap.empty()){
        auto x=heap.top();
        heap.pop();

        int a=x.second;
        if(st[a])continue;
        st[a]=true;

        for(auto v:edge[a]){
            int b=v.first,w=v.second;
            int now=max(dist[a],w);

            if(dist[b]>now){
                dist[b]=now;
                heap.push({dist[b],b});
            }
        }
    }
}

int main(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    solve();

    cout<<dist[t];
}