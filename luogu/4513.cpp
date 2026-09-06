#include<bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1|1

const int N=5e5+5;

int n,m;
int a[N];
struct node
{
    int l,r,max,lmax,rmax,sum;
}tr[N<<2];

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
    tr[p].max=max(max(tr[lc].max,tr[rc].max),tr[lc].rmax+tr[rc].lmax);
    tr[p].lmax=max(tr[lc].lmax,tr[lc].sum+tr[rc].lmax);
    tr[p].rmax=max(tr[rc].rmax,tr[rc].sum+tr[lc].rmax);
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],a[l],a[l],a[l]};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,int aim,int score){
    int l=tr[p].l,r=tr[p].r;
    if(l==aim && r==aim){
        tr[p].sum=score;
        tr[p].rmax=score;
        tr[p].lmax=score;
        tr[p].max=score;
        return;
    }
    
    int mid=(l+r)>>1;
    if(aim<=mid)modify(lc,aim,score);
    if(aim>mid)modify(rc,aim,score);
    pushup(p);
    return;
}

node query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p];
    }

    int mid=(l+r)>>1;
    if(y<=mid)return query(lc,x,y);
    if(x>mid)return query(rc,x,y);

    node ret;node L=query(lc,x,y),R=query(rc,x,y);
    ret.sum=L.sum+R.sum;
    ret.max=max(max(L.max,R.max),L.rmax+R.lmax);
    ret.lmax=max(L.lmax,L.sum+R.lmax);
    ret.rmax=max(R.rmax,R.sum+L.rmax);
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while (m--)
    {
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            int s=min(a,b),e=max(a,b);
            cout<<query(1,s,e).max<<'\n';
        } else {
            modify(1,a,b);
        }
    }
    
}