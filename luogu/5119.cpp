#include<bits/stdc++.h>
using namespace std;
using LL= long long;

const int N=1e5+5;

int n,m,c;
LL t[N];

bool check(LL x){
    int cnt=1,sum=1;
    LL basetime=t[1];

    for(int i=2;i<=n;i++){
        if(sum==c || t[i]-basetime>x){
            cnt++;
            basetime=t[i];
            sum=1;
        }
        else{
            sum++;
        }
    }

    return cnt<=m;
}

int main(){
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    sort(t+1,t+1+n);

    LL l=0,r=1e9;
    while(l<r){
        LL mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        } else {
            l=mid+1;
        }
    }

    cout<<r;
}