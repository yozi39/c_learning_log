#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
typedef long long LL;

const int N=5e5+5;

int n,m;
int a[N];
struct node
{
    int l,r;
    LL sum;
}tr[4*N];

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l]};//或者0
    if(l==r)return;
    
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,int x,int k){
    int l=tr[p].l,r=tr[p].r;
    if(x==l && r==x){
        tr[p].sum+=k;
        return;
    }

    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,k);
    else modify(rc,x,k);
    pushup(p);
}

LL query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;

    if(x<=l && y>=r)return tr[p].sum;

    int mid=(l+r)>>1;
    LL sum=0;
    if(x<=mid) sum+=query(lc,x,y);
    if(y>mid) sum+=query(rc,x,y);
    return sum;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    build(1,1,n);

    while(m--){
        int op,x,y;cin>>op>>x>>y;
        if(op==1){
            modify(1,x,y);
        } else {
            cout<<query(1,x,y)<<'\n';
        }
    }
}