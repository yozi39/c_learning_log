#include<bits/stdc++.h>
using namespace std;

const int N=1005;

int fa[N];

int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

void un(int x,int y){
    fa[find(x)]=find(y);
}

int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)fa[i]=i;

        for(int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            un(a,b);
        }

        int cnt=0;
        for(int i=1;i<=n;i++){
            if(fa[i]==i)cnt++;
        }
        cout<<cnt-1<<'\n';
    }
}