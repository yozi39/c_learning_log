#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1 | 1
using namespace std;

const int N=1e5+5;

int n,m;
int x[N];
struct P1816
{
    int l,r,min;
}tr[4*N];

void pushup(int p){
    tr[p].min=min(tr[lc].min,tr[rc].min);
}

void build(int p,int l,int r){
    tr[p]={l,r,x[l]};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

int query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].min;
    }

    int ret=1e9;
    int mid=(l+r)>>1;
    if(x<=mid)ret=min(ret,query(lc,x,y));
    if(y>mid)ret=min(ret,query(rc,x,y));
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    build(1,1,n);

    while(m--){
        int x,y;cin>>x>>y;
        cout<<query(1,x,y)<<' ';
    }
}