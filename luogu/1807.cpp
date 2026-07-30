#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;

const int N=1505,INF=0x3f3f3f3f;

int n,m;
vector<PII> e[N];


int dist[N];
bool st[N];

queue<int> q;
void spfa(int s){
    for(int i=0;i<=n;i++) dist[i] = -INF;

    q.push(s);
    dist[s] = 0;
    st[s] = true;

    while(q.size()){
        int x = q.front();
        q.pop();
        st[x] = false;

        for(auto p : e[x]){
            int to = p.first;
            int di = p.second;

            if(dist[to] < dist[x] + di){
                dist[to] = dist[x] + di;

                if(!st[to]){
                    st[to] = true;
                    q.push(to);
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        e[a].push_back({b,c});
    }

    spfa(1);

    if(dist[n]==-INF){
        cout<<-1;
    } else{
        cout<<dist[n];
    }
}



// void dijkstra(int x){//历史遗留问题,没看到DAG
//     memset(dist,0x3f,sizeof dist);
//     dist[x]=0;
//     priority_queue<PII,vector<PII>> heap;
//     heap.push({0,x});

//     while(heap.size()){
//         auto x=heap.top();heap.pop();

//         if(st[x.second])continue;
//         st[x.second]=true;

//         for(auto p:e[x.second]){
//             int to=p.first,di=p.second;

//             if(dist[to]==INF){
//                 dist[to]=di;
//             } else {
//                 dist[to]=max(di,dist[to]);
//                 heap.push({di,to});
//             }
//         }
//     }
// }