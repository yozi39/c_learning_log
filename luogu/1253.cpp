#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lc p<<1
#define rc p<<1 | 1

const int N=1e6+5;

int n,q;
int a[N];
struct node{
    int l,r;
    LL max,add,change;
    bool tag;
}tr[N<<2];

void pushup(int p){
    tr[p].max=max(tr[lc].max,tr[rc].max);
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],0,0};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void lazy(int p,LL x,int op){
    if(op==1){
        tr[p].max=x;
        tr[p].change=x;
        tr[p].add=0;
        tr[p].tag=1;
    } else {
        tr[p].max=tr[p].max+x;
        tr[p].add+=x;
    }
}

void pushdown(int p){
    if(tr[p].tag){
        lazy(lc,tr[p].change,1);
        lazy(rc,tr[p].change,1);
        tr[p].tag=0;
    }

    if(tr[p].add){
        lazy(lc,tr[p].add,2);
        lazy(rc,tr[p].add,2);
        tr[p].add=0;
    }
}

void modify(int p,int x,int y,int op,LL change){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        lazy(p,change,op);
        return;
    }

    pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,y,op,change);
    if(y>mid)modify(rc,x,y,op,change);
    pushup(p);
}

LL query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].max;
    }

    LL ret=LLONG_MIN;
    pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid)ret=max(ret,query(lc,x,y));
    if(y>mid)ret=max(ret,query(rc,x,y));
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];

    build(1,1,n);

    while(q--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1 || op==2){
            LL change;
            cin>>change;
            modify(1,x,y,op,change);
        }
        else {
            cout<<query(1,x,y)<<'\n';
        }
    }
}