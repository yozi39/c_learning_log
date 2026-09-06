#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

const int N=2005;
const LL INF=1e18;

int n,c,pos,m;
int fa[N];
PII p[N];

struct edge{
    int x,y;
    LL z;

    bool operator<(const edge& other) const{
        return z<other.z;
    }
}a[N*N/2+5];

LL caldist(PII a,PII b){
    LL dx=a.first-b.first;
    LL dy=a.second-b.second;
    return dx*dx+dy*dy;
}

int find(int x){
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void un(int x,int y){
    fa[find(x)]=find(y);
}

LL kruskal(){
    sort(a+1,a+1+m);

    int cnt=0;
    LL ret=0;

    for(int i=1;i<=m;i++){
        int x=a[i].x,y=a[i].y;

        int fx=find(x),fy=find(y);
        if(fx!=fy){
            cnt++;
            ret+=a[i].z;
            fa[fx]=fy;
        }
    }

    return cnt==n-1 ? ret : INF;
}

int main(){
    cin>>n>>c;

    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        p[++pos]={x,y};
        fa[i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            LL tmp=caldist(p[i],p[j]);

            if(tmp<c) continue;

            a[++m]={i,j,tmp};
        }
    }

    LL ret=kruskal();
    if(ret==INF){
        cout<<-1;
    } else {
        cout<<ret;
    }
}