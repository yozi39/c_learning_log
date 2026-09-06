#include<bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> TIII;
typedef pair<int,int> PII;

const int N=1e3+5,INF=0x3f3f3f3f;

int n,p,k;
vector<PII> edge[N];

int dist[N][N];

void dijkstra(int x){
    memset(dist,0x3f,sizeof dist);

    // {当前花费, 当前点, 已经免费了几条}
    priority_queue<TIII,vector<TIII>,greater<TIII>> heap;

    dist[x][0]=0;
    heap.push({0,x,0});

    while(heap.size()){
        auto head=heap.top();
        heap.pop();

        int d=get<0>(head);
        int a=get<1>(head);
        int cnt=get<2>(head);

        if(d!=dist[a][cnt])continue;

        for(auto v:edge[a]){
            int b=v.first,w=v.second;

            // 1. 这条边不免费
            int nd=max(d,w);

            if(dist[b][cnt]>nd){
                dist[b][cnt]=nd;
                heap.push({nd,b,cnt});
            }

            // 2. 这条边免费
            if(cnt<k && dist[b][cnt+1]>d){
                dist[b][cnt+1]=d;
                heap.push({d,b,cnt+1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>p>>k;

    // 一条最优路径没必要重复走点
    // 所以最多只需要考虑 n-1 次免费
    k=min(k,n-1);

    for(int i=1;i<=p;i++){
        int a,b,c;
        cin>>a>>b>>c;

        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    dijkstra(1);

    int ret=INF;

    for(int i=0;i<=k;i++){
        ret=min(ret,dist[n][i]);
    }

    if(ret==INF){
        cout<<-1;
    } else {
        cout<<ret;
    }

    return 0;
}