#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],b[N];
int f[N];
int n,m;

int sg(int x){
    unordered_set<int> mp;
    if(f[x]!=-1)return f[x];
    sort(b+1,b+m+1);
    for(int i=1;i<=m && x-b[i]>=0;i++){
        mp.insert(sg(x-b[i]));
    }
    for(int i=0;;i++){
        if(!mp.count(i)){
            return f[x]=i;
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }

    memset(f,-1,sizeof f);

    int ret=0;
    for(int i=1;i<=n;i++){
        ret^=sg(a[i]);
    }
    if(!ret){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m&&a[i]-b[j]>=0;j++){
                if((ret ^ sg(a[i]) ^ sg(a[i] - b[j])) == 0){
                    cout<<i<<' '<<b[j];
                    return 0;
                }
            }
        }
    }
}