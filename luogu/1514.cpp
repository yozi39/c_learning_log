#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=505,
    dx[4]={1,-1,0,0},
    dy[4]={0,0,1,-1}
;

int n,m;
int h[N][N];
int FL[N][N],FR[N][N];

bool st[N][N],reach[N];
void bfs(int ix){
    memset(st,0,sizeof st);

    FL[1][ix]=m+1;
    FR[1][ix]=0;

    st[1][ix]=true;
    queue<PII> q;
    q.push({1,ix});

    while(q.size()){
        auto tmp=q.front();q.pop();

        int ox=tmp.first,oy=tmp.second;

        if(ox==n){
            reach[oy]=true;

            FL[1][ix]=min(FL[1][ix],oy);
            FR[1][ix]=max(FR[1][ix],oy);
        }

        for(int k=0;k<4;k++){
            int nx=tmp.first+dx[k],
                ny=tmp.second+dy[k];

            if(nx<1 || nx>n || ny<1 || ny>m)continue;

            if(!st[nx][ny] && h[nx][ny]<h[ox][oy]){
                st[nx][ny]=true;
                q.push({nx,ny});
            }    
        }
    }
}

int greedy(){
    vector<PII> seg;

    for(int i=1;i<=m;i++){
        if(FR[1][i]){
            seg.push_back({FL[1][i],FR[1][i]});
        }
    }

    sort(seg.begin(),seg.end());

    int pos=1,idx=0,ans=0;

    while(pos<=m){
        int far=pos-1;

        while(idx<(int)seg.size() && seg[idx].first<=pos){
            far=max(far,seg[idx].second);
            idx++;
        }

        if(far<pos)return -1;

        ans++;
        pos=far+1;
    }

    return ans;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>h[i][j];
        }
    }

    for(int i=1;i<=m;i++){
        FL[1][i]=i;
        FR[1][i]=i;
    }

    for(int i=1;i<=m;i++){
        bfs(i);
    }

    int bad=0;
    for(int i=1;i<=m;i++){
        if(!reach[i])bad++;
    }

    if(bad){
        cout<<0<<'\n';
        cout<<bad<<'\n';
        return 0;
    }
    else{
        cout<<1<<'\n';
        cout<<greedy()<<'\n';
    }
}