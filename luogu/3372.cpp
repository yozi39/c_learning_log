#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
typedef long long LL;

const int N=1e5+5;

int n,m;
LL a[N];
struct node
{
    int l,r;
    LL sum,add;
}tr[4*N];

void lazy(int p,LL add){
    int l=tr[p].l,r=tr[p].r;
    tr[p].sum+=(r+1-l)*add;
    tr[p].add+=add;
}

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int p){
    if(tr[p].add){
        lazy(lc,tr[p].add);
        lazy(rc,tr[p].add);
        tr[p].add=0;
    }
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],0};
    if(l==r){
        return;
    }

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,int x,int y,LL k){
    int l=tr[p].l,r=tr[p].r;
    if(l>=x && r<=y){
        lazy(p,k);
        return;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(mid>=x)modify(lc,x,y,k);
    if(y>mid)modify(rc,x,y,k);
    pushup(p);
}

LL query(int p,int x,int y){
    LL ret=0;
    int l=tr[p].l,r=tr[p].r;
    if(l>=x && r<=y){
        return tr[p].sum;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(mid>=x)ret+=query(lc,x,y);
    if(y>mid)ret+=query(rc,x,y);
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while(m--){
        int op,x,y;cin>>op>>x>>y;
        if(op==1){
            LL k;
            cin>>k;
            modify(1,x,y,k);
        } else {
            cout<<query(1,x,y)<<'\n';
        }
    }
}