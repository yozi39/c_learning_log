#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1 | 1

using namespace std;
typedef long long LL;

enum LIGHT{
    CLOSE,OPEN
};

const int N=1e5+5;

int n,m;
struct node{
    int l,r;
    bool light=CLOSE;
    LL sum=0;
    int changes=0;
}tr[4*N];

void lazy(int p){
    int l=tr[p].l,r=tr[p].r;
    tr[p].sum=(r-l+1)-tr[p].sum;
    tr[p].changes++;
}

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int p){
    if(tr[p].changes%2==0){
        return;
    } else {
        tr[lc].sum=(tr[lc].r-tr[lc].l+1)-tr[lc].sum;
        tr[rc].sum=(tr[rc].r-tr[rc].l+1)-tr[rc].sum;
        tr[lc].changes++;
        tr[rc].changes++;
        tr[p].changes=0;
    }
}

void build(int p,int l,int r){
    tr[p]={l,r,CLOSE,0,0};
    if(l==r){
        return;
    }

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    return;
}

void change(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        lazy(p);
        return;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid)change(lc,x,y);
    if(y>mid)change(rc,x,y);
    pushup(p);
    return;
}

LL query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].sum;
    }

    LL ret=0;
    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid)ret+=query(lc,x,y);
    if(y>mid)ret+=query(rc,x,y);
    return ret;
}

int main(){
    cin>>n>>m;

    build(1,1,n);

    while(m--){
        int c,x,y;
        cin>>c>>x>>y;
        
        if(c){
            cout<<query(1,x,y)<<'\n';
        } else {
            change(1,x,y);
        }
    }
}