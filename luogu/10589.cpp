#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lowbit(x) (x&-x)

const int N=2e5+5;

int n,a[N];
LL s[N];

LL query(int x){
    LL sum=0;
    for(int i=x;i;i-=lowbit(i)) sum+=s[i];
    return sum;
}

void modify(int x){
    for(int i=x;i<=n;i+=lowbit(i)) s[i]++;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    LL V=0,A=0;

    for(int i=1;i<=n;i++){
        int x=a[i];

        LL ls=query(x-1);
        LL lb=i-1-ls;

        LL rs=x-1-ls;
        LL rb=n-x-lb;

        V+=lb*rb;
        A+=ls*rs;

        modify(x);
    }

    cout<<V<<' '<<A;
}