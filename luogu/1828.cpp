#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

const int N=805;

int n,p,c,pos;
unordered_map<int,int> mp;
LL ret,saveret[N];
vector<PII> edge[N];

bool st[N];
int cnt,dist[N];
void dijkstra(int tmp){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    ret=0;

    priority_queue<PII,vector<PII>,greater<PII>> heap;
    dist[tmp]=0;
    heap.push({0,tmp});
    
    while(heap.size()){
        auto x=heap.top();heap.pop();
        int a=x.second;

        if(st[a])continue;
        st[a]=true;

        for(auto v:edge[a]){
            int b=v.first,c=v.second;
            if(dist[b]>dist[a]+c){
                dist[b]=dist[a]+c;
                heap.push({dist[b],b});
            }
        }
    }

    for(int i=1;i<=p;i++){
        if(mp.count(i)){
            ret+=1ll*mp[i]*dist[i];
        }
    }

    saveret[++pos]=ret;
}

int main(){
    cin>>n>>p>>c;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    for(int i=1;i<=c;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    for(int i=1;i<=p;i++){
        dijkstra(i);
    }

    LL ans=1e18;
    for(int i=1;i<=pos;i++){
        ans=min(ans,saveret[i]);
    }
    cout<<ans;
}