#include<bits/stdc++.h>
using namespace std;

const int N=1000005;

int l,n,k;
int a[N];

bool check(int x){
    int ret=0;
    for(int i=1;i<=n+1;i++){
        ret+=(a[i]-a[i-1]-1)/x;
    }
    return ret<=k;
}

int main(){
    cin>>l>>n>>k;
    a[0]=0;a[n+1]=l;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int le=1,ri=l;
    while(le<ri){
        int mid=(le+ri)/2;
        if(check(mid)){
            ri=mid;
        } else {
            le=mid+1;
        }
    }
    cout<<le;
}