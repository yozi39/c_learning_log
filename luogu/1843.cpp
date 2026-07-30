#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=5e5+5;

int n,a,b;
int w[N];

bool check(LL x){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(w[i]<=a*x) continue;
        
        LL d=w[i]-a*x;
        cnt=cnt+d/b+(d%b==0 ? 0:1);
    }
    return cnt<=x;
}

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>w[i];

    int l=1,r=5e5;
    while(l<r) {
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        } else {
            l=mid+1;
        }
    }

    cout<<r;

    return 0;
}