#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;

        LL a,p;
        cin>>a>>p;
        a%=p;

        for(int i=3;i<=n;i++){
            LL x;cin>>x;
            a=a*x%p;
        }

        if(a)cout<<"No\n";
        else {
            cout<<"Yes\n";
        }
    }
}