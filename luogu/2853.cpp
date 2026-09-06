#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int K=105,N=1005,M=10005;

long long ret;
int k,n,m;
int c[K],cnt[N];
vector<int> e[N];

void bfs(int x){
    bool st[N]={};
    cnt[x]++;
    queue<int> q;
    q.push(x);
    st[x]=true;

    while(q.size()){
        auto head=q.front();q.pop();

        for(auto v:e[head]){
            if(!st[v]){
                st[v]=true;
                q.push(v);
                cnt[v]++;
            }            
        }
    }
}

int main(){
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++)cin>>c[i];
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        e[a].push_back(b);
    }

    for(int i=1;i<=k;i++){
        bfs(c[i]);
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==k){
            ret++;
        }
    }

    cout<<ret;
}