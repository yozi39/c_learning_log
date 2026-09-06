#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;

int a,b,c;

int gcd(int a,int b){
    return b==0? a:gcd(b,a%b);
}

signed main(){
    cin>>a>>b>>c;
    
    long long ret=1;
    ret=a/gcd(a,b)*b;
    ret=ret/gcd(ret,c)*c;
    cout<<ret;
}