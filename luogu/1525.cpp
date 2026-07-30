#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;

const int N=4e4+10,M=1e5+10;

int n,m;
struct node{
    int a,b,c;
}e[M];

int fa[N];
int find(int x){
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}

void un(int x,int y){
    fa[find(x)]=find(y);
}

bool cmp(node& x,node& y){
    return x.c>y.c;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n+n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[i].a>>e[i].b>>e[i].c;
    } sort(e+1,e+1+m,cmp);

    for(int i=1;i<=m;i++){
        int a=e[i].a,b=e[i].b,c=e[i].c;
        un(a,b+n);un(b,a+n);
        if(find(a)==find(b)){
            cout<<c<<endl;
            return 0;
        }
    }

    cout<<0<<endl;
    return 0;
}