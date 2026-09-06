#include<bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1

const int N=1e5+5;

int n,m;
int a[N];

struct node{
    int l,r;
    int sum;

    int l0,r0,m0;
    int l1,r1,m1;

    int change;
    bool rev;
}tr[N<<2];

void pushup(int p){
    int llen=tr[lc].r-tr[lc].l+1;
    int rlen=tr[rc].r-tr[rc].l+1;

    tr[p].sum=tr[lc].sum+tr[rc].sum;

    tr[p].l0=tr[lc].l0;
    if(tr[lc].l0==llen)tr[p].l0+=tr[rc].l0;

    tr[p].r0=tr[rc].r0;
    if(tr[rc].r0==rlen)tr[p].r0+=tr[lc].r0;

    tr[p].m0=max({
        tr[lc].m0,
        tr[rc].m0,
        tr[lc].r0+tr[rc].l0
    });

    tr[p].l1=tr[lc].l1;
    if(tr[lc].l1==llen)tr[p].l1+=tr[rc].l1;

    tr[p].r1=tr[rc].r1;
    if(tr[rc].r1==rlen)tr[p].r1+=tr[lc].r1;

    tr[p].m1=max({
        tr[lc].m1,
        tr[rc].m1,
        tr[lc].r1+tr[rc].l1
    });
}

void build(int p,int l,int r){
    tr[p].l=l;
    tr[p].r=r;
    tr[p].change=-1;
    tr[p].rev=false;

    if(l==r){
        tr[p].sum=a[l];

        if(a[l]){
            tr[p].l1=tr[p].r1=tr[p].m1=1;
            tr[p].l0=tr[p].r0=tr[p].m0=0;
        } else {
            tr[p].l0=tr[p].r0=tr[p].m0=1;
            tr[p].l1=tr[p].r1=tr[p].m1=0;
        }

        return;
    }

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void setlazy(int p,int x){
    int len=tr[p].r-tr[p].l+1;

    tr[p].change=x;
    tr[p].rev=false;

    if(x==0){
        tr[p].sum=0;

        tr[p].l0=tr[p].r0=tr[p].m0=len;
        tr[p].l1=tr[p].r1=tr[p].m1=0;
    } else {
        tr[p].sum=len;

        tr[p].l1=tr[p].r1=tr[p].m1=len;
        tr[p].l0=tr[p].r0=tr[p].m0=0;
    }
}

void revlazy(int p){
    int len=tr[p].r-tr[p].l+1;

    tr[p].sum=len-tr[p].sum;

    swap(tr[p].l0,tr[p].l1);
    swap(tr[p].r0,tr[p].r1);
    swap(tr[p].m0,tr[p].m1);

    if(tr[p].change!=-1){
        tr[p].change^=1;
    } else {
        tr[p].rev^=1;
    }
}

void pushdown(int p){
    if(tr[p].change!=-1){
        setlazy(lc,tr[p].change);
        setlazy(rc,tr[p].change);
        tr[p].change=-1;
    }

    if(tr[p].rev){
        revlazy(lc);
        revlazy(rc);
        tr[p].rev=false;
    }
}

void modify(int p,int x,int y,int op){
    int l=tr[p].l,r=tr[p].r;

    if(x<=l && r<=y){
        if(op==0)setlazy(p,0);
        else if(op==1)setlazy(p,1);
        else revlazy(p);

        return;
    }

    pushdown(p);

    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,y,op);
    if(y>mid)modify(rc,x,y,op);

    pushup(p);
}

int querysum(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;

    if(x<=l && r<=y){
        return tr[p].sum;
    }

    pushdown(p);

    int ret=0;
    int mid=(l+r)>>1;

    if(x<=mid)ret+=querysum(lc,x,y);
    if(y>mid)ret+=querysum(rc,x,y);

    return ret;
}

struct info{
    int len;
    int l1,r1,m1;
};

info mergeinfo(info a,info b){
    info c;

    c.len=a.len+b.len;

    c.l1=a.l1;
    if(a.l1==a.len)c.l1+=b.l1;

    c.r1=b.r1;
    if(b.r1==b.len)c.r1+=a.r1;

    c.m1=max({
        a.m1,
        b.m1,
        a.r1+b.l1
    });

    return c;
}

info querymax(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;

    if(x<=l && r<=y){
        return {
            r-l+1,
            tr[p].l1,
            tr[p].r1,
            tr[p].m1
        };
    }

    pushdown(p);

    int mid=(l+r)>>1;

    if(y<=mid)return querymax(lc,x,y);
    if(x>mid)return querymax(rc,x,y);

    info L=querymax(lc,x,y);
    info R=querymax(rc,x,y);

    return mergeinfo(L,R);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while(m--){
        int op,x,y;
        cin>>op>>x>>y;

        if(op<=2){
            modify(1,x+1,y+1,op);
        } else if(op==3){
            cout<<querysum(1,x+1,y+1)<<'\n';
        } else {
            cout<<querymax(1,x+1,y+1).m1<<'\n';
        }
    }

    return 0;
}