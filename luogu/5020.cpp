#include<bits/stdc++.h>
using namespace std;

const int N=110,M=25010;
bool f[M];

int main(){
    int T;cin>>T;
    while(T--){
        int n;
        int a[N];

        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];

        sort(a+1,a+1+n);
        memset(f,0,sizeof f);
        f[0]=true;

        int ret=0;
        for(int i=1;i<=n;i++){
            if(!f[a[i]]){
                ret++;
            }
            for(int j=a[i];j<=a[n];j++){
                f[j]=f[j] || f[j-a[i]];
            }
        }
        cout<<ret<<'\n';
    }
}