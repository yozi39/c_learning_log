#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=1e3+5,M=1e4+5;

int n,m,k;
int fa[N];

int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

void un(int a,int b){
    fa[find(a)]=find(b);
}

struct node{
    int x,y,l;

    bool operator<(node& b){
        return l<b.l;
    }
}a[M];

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].l;
    }

    sort(a+1,a+1+m);
    for(int i=1;i<=n;i++)fa[i]=i;

    int cnt=n,step=0;
    long long ret=0;
    for(int i=1;cnt>k && i<=m;i++){
        if(find(a[i].x)!=find(a[i].y)){
            un(a[i].x,a[i].y);
            cnt--;
            step++;
            ret+=a[i].l;
        }
    }

    if(step==n-k){
        cout<<ret;
    } else {
        cout<<"No Answer";
    }
}