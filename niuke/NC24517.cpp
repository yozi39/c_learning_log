#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b){
    return b==0? a:gcd(b,a%b);
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

signed main(){
    int T;cin>>T;
    while(T--){
        int a,b,c;cin>>a>>b>>c;
        long long ret=a/c+a/b-a/lcm(c,b);
        cout<<ret<<'\n';
    }
}