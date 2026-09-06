#include<bits/stdc++.h>
using namespace std;

const int N=10005,M=1005,INF=0x3f3f3f3f;

int n,m,k;
int f[N][M];

struct fly{
    int x,y;
}a[N];

int low[N],high[N];

int main(){
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        low[i]=0;
        high[i]=m+1;
    }

    for(int i=1;i<=k;i++){
        int p,l,h;
        cin>>p>>l>>h;
        low[p]=l;
        high[p]=h;
    }

    memset(f,0x3f,sizeof f);
    for(int h=1;h<=m;h++){
        f[0][h]=0;
    }

    int passed=0;
    for(int i=1;i<=n;i++){
        // 上升：第一次点击 + 连续点击
        for(int h=a[i].x+1;h<=m;h++){
            f[i][h]=min(f[i][h],f[i-1][h-a[i].x]+1);
            f[i][h]=min(f[i][h],f[i][h-a[i].x]+1);
        }

        for(int h=m-a[i].x;h<=m;h++){
            f[i][m]=min(f[i][m],f[i-1][h]+1);
            f[i][m]=min(f[i][m],f[i][h]+1);
        }

        // 不点击，下降
        for(int h=1;h+a[i].y<=m;h++){
            f[i][h]=min(f[i][h],f[i-1][h+a[i].y]);
        }

        // 管道
        for(int h=1;h<=low[i];h++){
            f[i][h]=INF;
        }
        for(int h=high[i];h<=m;h++){
            f[i][h]=INF;
        }

        int best=INF;
        for(int h=1;h<=m;h++){
            best=min(best,f[i][h]);
        }

        if(best==INF){
            cout<<0<<'\n'<<passed;
            return 0;
        }

        if(low[i]!=0 || high[i]!=m+1){
            passed++;
        }
    }

    int ret=INF;
    for(int h=1;h<=m;h++){
        ret=min(ret,f[n][h]);
    }

    cout<<1<<'\n'<<ret;
}