#include<bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1 | 1
typedef long long LL;
typedef pair<LL,LL> PLL;

const int N=1e5+5,MOD=1e9+7;

LL n,m;
LL a[N];
struct node{
    int l,r;
    LL sum,other;
}tr[N<<2];

LL qpow(LL a,LL b,LL M){
    LL ret=1;
    while (b)
    {
        if(b&1)ret = ret*a%M;
        b>>=1;
        a = a*a%M;
    }
    return ret;
}

void pushup(node& p,node& l,node& r){
    p.sum=(l.sum+r.sum)%MOD;
    p.other = (l.other + r.other)%MOD;
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],a[l]*a[l]%MOD};
    if(l==r){
        return;
    }

    int mid=(l+r)/2;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(tr[p],tr[lc],tr[rc]);
}

void modify(int p,int x,LL y){
    int l=tr[p].l,r=tr[p].r;
    if(l==r){
        tr[p].sum=y;
        tr[p].other=y*y%MOD;
        return;
    }

    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,y);
    if(x>mid)modify(rc,x,y);
    pushup(tr[p],tr[lc],tr[rc]);
}

node query(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p];
    }

    int mid=(l+r)>>1;
    if(y<=mid)return query(lc,x,y);
    if(x>mid)return query(rc,x,y);

    node ret,L=query(lc,x,y),R=query(rc,x,y);
    pushup(ret,L,R);
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    build(1,1,n);

    while (m--)
    {
        LL op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            modify(1,x,y);
        } else {
            node t=query(1,x,y);
            LL sum=t.sum;LL qsum=t.other;LL len=(y-x+1);
            LL inv=qpow(len,MOD-2,MOD);
            LL A=sum*inv%MOD;
            LL ret=((qsum*inv%MOD-A*A%MOD)%MOD+MOD)%MOD;
            cout<<ret<<'\n';
        }
    }
}