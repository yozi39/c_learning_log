#include<iostream>
using namespace std;

#define lc p<<1
#define rc p<<1 | 1
typedef long long LL;

const int N=5e5+10;

int n,m;
LL a[N];

struct  node
{
    int l,r;
    LL sum,gcd;
}tr[N<<2];

LL gcd(LL a,LL b){
    return b==0? a:gcd(b,a%b);
}

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
    tr[p].gcd=gcd(tr[lc].gcd,tr[rc].gcd);
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],a[l]};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,int aim,LL value){
    int l=tr[p].l,r=tr[p].r;
    if(l==r){
        tr[p].sum+=value;
        tr[p].gcd+=value;
        return;    
    }

    int mid=(l+r)>>1;
    if(aim<=mid)modify(lc,aim,value);
    else modify(rc,aim,value);
    pushup(p);
}

LL query1(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].sum;
    }

    LL ret=0;
    int mid=(l+r)>>1;
    if(x<=mid)ret+=query1(lc,x,y);
    if(y>mid)ret+=query1(rc,x,y);
    return ret;
}

LL query2(int p,int x,int y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].gcd;
    }

    LL ret=0;
    int mid=(l+r)>>1;
    if(x<=mid)ret=gcd(query2(lc,x,y),ret);
    if(y>mid)ret=gcd(query2(rc,x,y),ret);
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        LL x;cin>>x;
        a[i] += x;
        a[i+1] -= x;
    }

    build(1,1,n);

    while (m--)
    {
        string op;LL l,r;LL d;
        cin>>op>>l>>r;
        if(op=="C"){
            cin>>d;
            modify(1,l,d);
            if(r+1<=n)modify(1,r+1,-d);
        } else {
            LL sum = query1(1,1,l);
            LL g = 0;
            if(l+1<=r) g=query2(1,l+1,r);
            LL ret=gcd(sum,g);
            cout<<abs(ret)<<'\n';
        }
    }
    
}