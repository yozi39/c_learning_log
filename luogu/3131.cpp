#include<bits/stdc++.h>
using namespace std;

const int N=5e4+5;

int n;
int a[N],f[N];
long long pre[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }

    unordered_map<int,int> mp;
    mp[0]=0;
    for(int i=1;i<=n;i++){
        if(!mp.count(pre[i]%7)){
            mp[pre[i]%7]=i;
        } else {
            f[i]=max(f[i],i-mp[pre[i]%7]);
        }
    }

    int ret=0;
    for(int i=1;i<=n;i++){
        ret=max(ret,f[i]);
    }
    cout<<ret;
}