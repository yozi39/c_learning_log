#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=2e6+5;

LL n,MOD;
int p[N],pcnt;
int fac[N];
bool st[N];
int cnt[N];

void get_prime(){
    for(int i=2;i<N;i++){
        if(!st[i]){
            p[++pcnt]=i;
        }

        for(int j=1;j<=pcnt && 1LL*i*p[j]<N;j++){
            int next=i*p[j];
            st[next]=true;

            fac[next]=p[j];

            if(i%p[j]==0)break;
        }
    }
}

LL catlan(LL x){
    LL ret=1;

    // (n+2)...(2n) / 2...(n)
    for(int i=2;i<=n;i++){
        cnt[i]--;
    }

    for(int i=n+2;i<=2*n;i++){
        cnt[i]++;
    }

    for(int i=2*n;i>=2;i--){
        if(!fac[i])continue;

        cnt[fac[i]]+=cnt[i];
        cnt[i/fac[i]]+=cnt[i];
        cnt[i]=0;
    }

    for(int i=2;i<=2*n;i++){
        for(int j=1;j<=cnt[i];j++){
            ret=ret*i%MOD;
        }
    }

    return ret%MOD;
}

int main(){
    cin>>n>>MOD;

    get_prime();

    cout<<catlan(n);
}