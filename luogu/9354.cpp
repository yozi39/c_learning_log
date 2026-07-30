#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        string x;cin>>x;
        int sum=0;
        bool flag=false;
        for(auto n:x){
            if(n-'0'==0)flag=true;
            sum+=n-'0';
        }
        if(flag) cout<<sum+9<<endl;
        else cout<<sum+8<<endl;
    }
}