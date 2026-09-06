#include<bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1 | 1
typedef long long LL;

const int N=1e5+5;

int n,m;
LL a[N];
struct node{
    int l,r;
    LL max,sum;
}tr[N<<2];

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
    tr[p].max=max(tr[lc].max,tr[rc].max);
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],a[l]};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,int x,int y){
    if(tr[p].max == 1)return;

    int l=tr[p].l,r=tr[p].r;
    if(l==r){
        tr[p].sum=sqrt(tr[p].sum);
        tr[p].max=sqrt(tr[p].max);
        return;
    }

    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,y);
    if(y>mid)modify(rc,x,y);
    pushup(p);
}

LL query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].sum;
    }

    int mid=(l+r)>>1;
    LL ret=0;
    if(x<=mid)ret+=query(lc,x,y);
    if(y>mid)ret+=query(rc,x,y);
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;

    build(1,1,n);
    
    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(x>y)swap(x,y);

        if(op){
            cout<<query(1,x,y)<<'\n';
        } else {
            modify(1,x,y);
        }
    }

}