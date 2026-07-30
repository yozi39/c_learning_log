#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5,M=1e4+5
;

int n,m;
int f[M],t[M],x[M],y[M];

int main(){
    cin>>n>>m;
    int ret=0;
    for(int i=1;i<=m;i++){
        cin>>t[i]>>x[i]>>y[i];
        
        f[i] = 1;
        for(int j=1;j<i;j++){
            if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j])){
                f[i]=max(f[i],f[j]+1);
            }
        }

        ret = max(ret,f[i]);
    }

    cout<<ret;
}