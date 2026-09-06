#include<bits/stdc++.h>
using namespace std;

const int N=1005,M=40;

int t,w;
bool st[N];
int f[N][M];

int main(){
    cin>>t>>w;
    for(int i=1;i<=t;i++){
        int x;cin>>x;
        if(x==1)st[i]=true;
    }

    for(int i=1;i<=t;i++){
        for(int j=0;j<=w;j++){
            bool locate=(j%2==0);

            if(j==0){
                f[i][j]=f[i-1][j]+(st[i]==locate);
            }else{
                f[i][j]=max(f[i-1][j],f[i-1][j-1])+(st[i]==locate);
            }
        }
    }
    
    int ret=0;
    for(int i=0;i<=w;i++){
        ret=max(ret,f[t][i]);
    }
    cout<<ret;
}