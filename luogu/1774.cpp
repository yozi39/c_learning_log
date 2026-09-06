#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=5e5+10;
LL m[N],n,tmp[N];
LL sum;

void merge(LL l,LL r){
    LL mid=(l+r)/2;

    if(l>=r)return;
    
    merge(l,mid);
    merge(mid+1,r);

    int cur1=l,cur2=mid+1,i=l;

    while(cur1<=mid && cur2<=r){
        if(m[cur1]<=m[cur2]){
            tmp[i++]=m[cur1++];
        }
        else{
            sum+=(mid-cur1+1);
            tmp[i++]=m[cur2++];
        }
    }
    while (cur1<=mid)
    {
        tmp[i++]=m[cur1++];
    }
    while (cur2<=r)
    {
        tmp[i++]=m[cur2++];
    }
    for(int j=l;j<=r;j++){
        m[j]=tmp[j];
    }
    return;
}

int main(){
    cin>>n;for(int i=1;i<=n;i++)cin>>m[i];

    merge(1,n);

    cout<<sum;
}