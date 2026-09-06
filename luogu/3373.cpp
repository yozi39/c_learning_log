#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lc p<<1
#define rc p<<1 | 1

const int N=1e5+5;

int n,q,MOD;
int a[N];
struct node{
    int l,r;
    LL sum,add,mul;
}tr[N<<2];

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],0,1};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void lazy(int p,int op,LL change){
    LL len=tr[p].r-tr[p].l+1;

    if(op==1){
        tr[p].mul=tr[p].mul*change%MOD;
        tr[p].add=tr[p].add*change%MOD;
        tr[p].sum=tr[p].sum*change%MOD;
    } else {
        tr[p].add=(tr[p].add+change)%MOD;
        tr[p].sum=(tr[p].sum+len*change)%MOD;
    }
}

void pushdown(int p){
    if(tr[p].mul!=1){
        lazy(lc,1,tr[p].mul);
        lazy(rc,1,tr[p].mul);
        tr[p].mul=1;
    }
    if(tr[p].add){
        lazy(lc,2,tr[p].add);
        lazy(rc,2,tr[p].add);
        tr[p].add=0;
    }
}

void modify(int p,int x,int y,int op,LL change){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        lazy(p,op,change);
        return;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid)modify(lc,x,y,op,change);
    if(y>mid)modify(rc,x,y,op,change);
    pushup(p);
}

LL query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].sum;
    }

    int mid=(l+r)>>1;
    LL ret=0;
    pushdown(p);
    if(x<=mid)ret=(ret+query(lc,x,y))%MOD;
    if(y>mid)ret=(ret+query(rc,x,y))%MOD;
    return ret;
}

int main(){
    cin>>n>>q>>MOD;

    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);

    while(q--){
        int op,x,y;
        cin>>op>>x>>y;
        switch (op)
        {
        case 1:
        case 2:
            int k;cin>>k;
            modify(1,x,y,op,k);
            break;
        case 3:
            cout<<query(1,x,y)<<'\n';
            break;
        default:
            break;
        }
    }
}