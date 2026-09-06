#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
typedef long long LL;

const int N=5e5+5;

int n,m;
LL a[N];
struct P3368
{
    int l,r;
    LL sum,add;
}tr[4*N];

void lazy(int p,LL add){
    int l=tr[p].l,r=tr[p].r;
    tr[p].sum+=(r-l+1)*add;
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
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

LL query(int p,int x){
    int l=tr[p].l,r=tr[p].r;
    if(l==r){
        return tr[p].sum;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid) return query(lc,x);
    else return query(rc,x);
}

void modify(int p,int x,int y,LL k){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        lazy(p,k);
        return;
    }

    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid) modify(lc,x,y,k);
    if(y>mid) modify(rc,x,y,k);
    pushup(p);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    build(1,1,n);

    while(m--){
        int op,x,y;LL k;
        cin>>op>>x;
        if(op==1){
            cin>>y>>k;
            modify(1,x,y,k);
        }
        else {
            cout<<query(1,x)<<'\n';
        }
    }
}