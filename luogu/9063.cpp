#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int T;cin>>T;
    while (T--)
    {
        LL n;
        cin>>n;
        bool flag=true;
        for(int i=2;i<=n/i;i++){
            if(i%2==0 && n%i==0){
                cout<<"No\n";
                flag=false;
                break;
            }

            while(n%i==0){
                n/=i;
            }
        }

        if(!flag)continue;

        if(n){
            if(n%2==0){
                cout<<"No\n";
                continue;
            }
        }

        cout<<"Yes\n";
    }
}