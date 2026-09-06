#include<bits/stdc++.h>
using namespace std;

const int N=5e4+5;

int n,k;
int a[N],f[N],g[N];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    for(int left=1,right=1;right<=n;right++){
        while(a[right]-a[left]>k)left++;
        f[right]=max(f[right-1],right-left+1);
    }
    for(int left=n,right=n;left>=0;left--){
        while(a[right]-a[left]>k)right--;
        g[left]=max(g[left-1],right-left+1);
    }

    int ret=0;
    for(int i=2;i<=n;i++){
        ret=max(ret,f[i-1]+g[i]);
    }
    cout<<ret;
}