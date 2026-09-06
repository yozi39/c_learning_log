#include<bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1 | 1
typedef long long LL;

const int N=1e5+5;

int n,m;
int a[N];

struct P1438{
    int l,r;
    LL sum,base,add;
}tr[N<<2];

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],0};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void lazy(int p,LL base,LL add){
    LL len=tr[p].r-tr[p].l+1;

    tr[p].base+=base;
    tr[p].add+=add;

    tr[p].sum+=len*(2*base+(len-1)*add)/2;
}

void pushdown(int p){
    if(tr[p].base || tr[p].add){
        LL len=tr[lc].r-tr[lc].l+1;

        lazy(lc,tr[p].base,tr[p].add);
        lazy(rc,tr[p].base+len*tr[p].add,tr[p].add);

        tr[p].base=0;
        tr[p].add=0;
    }
}

LL query(int p,int k){
    int l=tr[p].l,r=tr[p].r;
    if(l==r){
        return tr[p].sum;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(k<=mid)return query(lc,k);
    if(k>mid)return query(rc,k);
}

void modify(int p,int x,int y,LL base,LL add){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        lazy(p,base+1LL*(l-x)*add,add);
        return;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid)modify(lc,x,y,base,add);
    if(y>mid)modify(rc,x,y,base,add);
    pushup(p);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    build(1,1,n);

    while(m--){
        int op;cin>>op;
        if(op==1){
            int l,r,k,d;cin>>l>>r>>k>>d;
            modify(1,l,r,k,d);
        } else {
            int goal;cin>>goal;
            cout<<query(1,goal)<<'\n';
        }
    }
}