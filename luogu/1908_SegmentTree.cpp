#include<bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1 | 1
typedef long long LL;

const int N=5e5+5;

int n,cnt;
int t[N],a[N];
map<int,int> mp;
struct node{
    int l,r;
    LL cnt;
}tr[N<<2];

void pushup(int p){
    tr[p].cnt=tr[lc].cnt+tr[rc].cnt;
}

void build(int p,int l,int r){
    tr[p]={l,r,0};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,int x){
    int l=tr[p].l,r=tr[p].r;
    if(l==r){
        tr[p].cnt++;
        return;
    }

    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x);
    if(x>mid)modify(rc,x);
    pushup(p);
}

LL query(int p,LL x,LL y){
    int l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].cnt;
    }

    LL ret=0;
    int mid=(l+r)>>1;
    if(x<=mid)ret+=query(lc,x,y);
    if(y>mid)ret+=query(rc,x,y);
    pushup(p);
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[i]=a[i];
    }

    sort(t+1,t+1+n);

    for(int i=1;i<=n;i++){
        int x=t[i];
        mp[x]=++cnt;    
    }

    build(1,1,n);

    LL ret=0;
    for(int i=1;i<=n;i++){
        int x=mp[a[i]];
        ret+=query(1,x+1,cnt);
        modify(1,x);
    }
    cout<<ret;
}