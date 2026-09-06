#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

const int N=1e6+5;

LL ret;
int n,size[N];
int h[N],e[2*N],ne[2*N],w[2*N],id;

void add(int a,int b,int c){
    id++;
    e[id] = b;
    w[id] = c;

    ne[id] = h[a];
    h[a] = id;
}

bool st[N];
int dfs(int a){
    st[a]=true;

    int cnt=1;
    for(int i=h[a];i;i=ne[i]){
        int b = e[i];
        LL c=w[i];
        if(st[b])continue;

        int t=dfs(b);
        ret+=abs(n-t-t)*c;
        cnt+=t;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    dfs(1);

    cout<<ret;
}