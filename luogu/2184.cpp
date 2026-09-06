#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;

const int N=1e5+5;

int n,m;

struct node{
    int l,r;
    LL st,ed;
}tr[4*N];

void build(int p,int l,int r){
    tr[p]={l,r,0,0};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
}

void pushup(int p){
    tr[p].st=tr[lc].st+tr[rc].st;
    tr[p].ed=tr[lc].ed+tr[rc].ed;
}

void modify(int p,int x,int type){
    int l=tr[p].l,r=tr[p].r;

    if(l==r){
        if(type==0)tr[p].st++;
        else tr[p].ed++;
        return;
    }

    int mid=(l+r)>>1;

    if(x<=mid)modify(lc,x,type);
    else modify(rc,x,type);

    pushup(p);
}

LL query(int p,int x,int y,int type){
    if(x>y)return 0;

    int l=tr[p].l,r=tr[p].r;

    if(x<=l&&r<=y){
        if(type==0)return tr[p].st;
        else return tr[p].ed;
    }

    LL ret=0;
    int mid=(l+r)>>1;

    if(x<=mid)ret+=query(lc,x,y,type);
    if(y>mid)ret+=query(rc,x,y,type);

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    build(1,1,n);

    while(m--){
        int q,x,y;
        cin>>q>>x>>y;

        if(q==1){
            modify(1,x,0);
            modify(1,y,1);
        }
        else{
            cout<<query(1,1,y,0)-query(1,1,x-1,1)<<'\n';
        }
    }

    return 0;
}