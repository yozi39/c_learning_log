#include<bits/stdc++.h>
using namespace std;

const int N=15,
    dx[]={0,0,1,-1},
    dy[]={1,-1,0,0}
;
int n,m,t,ret;
struct point{
    int x,y;
}a[N],s,f;

bool operator==(const point& b,const point& a){
    if(a.x==b.x && a.y==b.y) return true;
    return false;
}

bool st[N][N];
void dfs(point x){
    if(x==f){
        ret++;
        return;
    }

    for(int k=0;k<4;k++){
        int nx=x.x+dx[k],ny=x.y+dy[k];
        if(nx<=0 || nx>n || ny<=0 || ny>m || st[nx][ny]){
            continue;
        }
        st[nx][ny]=true;
        dfs({nx,ny});
        st[nx][ny]=false;
    }
}

int main(){
    cin>>n>>m>>t;
    cin>>s.x>>s.y>>f.x>>f.y;
    for(int i=1;i<=t;i++){
        cin>>a[i].x>>a[i].y;
        st[a[i].x][a[i].y]=true;
    }
    
    st[s.x][s.y]=true;
    dfs(s);

    cout<<ret;
}