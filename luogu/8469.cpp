#include<bits/stdc++.h>
using namespace std;
//gcd<=min(b1,b2,b3.....)
//所以挑最大的b可以让gcd最大
const int N=1e5+10,P=1e9+7;
long long m[N];

int main(){
    int n;cin>>n;
    long long minn=1e9+1;
    for(int i=1;i<=n;i++){
        cin>>m[i];
        minn=min(minn,m[i]);
    }
    //挑选值要选gcd的倍数才可以
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans = ans*(m[i]/minn)%P;
    }
    cout<<minn<<' '<<ans;
}