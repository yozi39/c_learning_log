#include<bits/stdc++.h>
using namespace std;

const int N=150,W=1500*200;

long long n,m,ret=1e9,choice,f[W+5];
int k[N],c[N],cnt[N];

bool check(){
    long long sum=1;
    for(int i=1;i<=n;i++){
        sum *= max(1, cnt[i]);
        if(sum >= m) return true;
    }
    return false;
}

void dfs(int x){
    if(x>n){
        if(choice<ret && check()){
            ret=choice;
        }
        return;
    }

    for(int i=1;i<=k[x];i++){
        choice+=i*c[x];
        cnt[x]+=i;
        dfs(x+1);
        cnt[x]-=i;
        choice-=i*c[x];
    }

    dfs(x+1);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    f[0] = 1;

    for(int x=1; x<=n; x++){
        for(int j=W; j>=0; j--){
            for(int p=1; p<=k[x] && p*c[x]<=j; p++){
                f[j] = max(f[j], min(m, f[j-p*c[x]] * p));
            }
        }
    }
    for(int j=0;j<=W;j++){
        if(f[j]>=m){
            cout << j;
            return 0;
        }
    }
    
    cout<<ret;
}