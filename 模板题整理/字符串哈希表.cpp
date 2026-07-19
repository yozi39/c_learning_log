#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P=131,N=1e6+10;
int n,a[N];
string s;

ULL givehash(string s){
    int ret=1;
    for(auto v:s){
        ret+=ret*P+v;
    }
    return ret;
}

int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=givehash(s);
    }
    sort(a+1,a+1+n);
    int ans=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1])ans++;
    }

    cout<<ans;
}