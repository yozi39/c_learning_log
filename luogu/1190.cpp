#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;
int m,n;
int t[N],water[105];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>t[i];

    for(int i=1;i<=m;i++){
        water[i]=t[i];
    }

    for(int i=m+1;i<=n;i++){
        int minn=water[1],pos=1;
        for(int j=2;j<=m;j++){
            if(water[j] < minn){
                minn = water[j];
                pos = j;
            }
        }

        water[pos]+=t[i];
    }

    int maxn=0;
    for(int i=1;i<=m;i++){
        maxn=max(maxn,water[i]);
    }
    cout<<maxn;
}