#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int T;cin>>T;

    while(T--){
        LL n;
        cin>>n;

       if(n==1){
            cout<<1<<'\n';        
        } else {
            cout<<n*(n-1)<<'\n';
        }
    }
}
