#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)

const int N=1e5+5;

int n;
int p[N],t[N];
vector<int> edge[N];
unordered_map<int,int> mp;
int s[N];
int ret[N];

void modify(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        s[i]+=k;
    }
}

int query(int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=s[i];
    }
    return sum;
}

void dfs(int u){
    ret[u]-=query(n)-query(p[u]);

    for(auto v:edge[u]){
        dfs(v);
    }

    ret[u]+=query(n)-query(p[u]);

    modify(p[u],1);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        t[i]=p[i];
    }

    sort(t+1,t+1+n);
    for(int i=1;i<=n;i++) mp[t[i]]=i;
    for(int i=1;i<=n;i++) p[i]=mp[p[i]];

    for(int i=2;i<=n;i++){
        int x;cin>>x;
        edge[x].push_back(i);        
    }

    dfs(1);

    for(int i=1;i<=n;i++){
        cout<<ret[i]<<'\n';
    }
}