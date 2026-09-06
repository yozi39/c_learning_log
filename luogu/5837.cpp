#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;


const int N=1005,P=1e6;


int n,m;
long long ret,tmp;

struct edge{
    int to,cost,flow;
};

vector<edge> e[N];


int dist[N];bool st[N];
void dijkstra(int xmin){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});


    while (heap.size())
    {   
        auto x=heap.top();heap.pop();

        int a=x.second;
        if(st[a])continue;
        st[a]=true;

        for(auto v:e[a]){
            int b=v.to,c=v.cost;

            if(dist[b]>dist[a]+c && v.flow>=xmin){
                dist[b]=dist[a]+c;
                heap.push({dist[b],b});
            }
        }
    }
    tmp=dist[n];
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,w,f;
        cin>>x>>y>>w>>f;
        e[x].push_back({y,w,f});
        e[y].push_back({x,w,f});
    }

    for(int i=1;i<=1000;i++){
        dijkstra(i);

        if(tmp==0x3f3f3f3f)continue;

        ret=max(ret,1LL*i*P/tmp);
    }
    cout<<ret;
}