#include<bits/stdc++.h>
using namespace std;

const int N=210;

int w,h;
int f[N][N];

int sg(int n,int m){
    if(f[n][m]!=-1)return f[n][m];

    unordered_set<int> mp;
    for(int i=2;i<n-1;i++)mp.insert(sg(n-i,m)^sg(i,m));
    for(int i=2;i<m-1;i++)mp.insert(sg(n,m-i)^sg(n,i));
    for(int i=0;;i++){
        if(!mp.count(i)){
            return f[n][m]=f[m][n]=i;
        }
    }
}

int main(){
    memset(f,-1,sizeof f);
    while(cin>>w>>h){
        int ret=sg(w,h);
        if(ret)cout<<"WIN\n";
        else cout<<"LOSE\n";        
    }
}