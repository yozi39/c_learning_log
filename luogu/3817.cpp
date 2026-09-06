#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,x;
long long a[N];

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];

    long long ret=0;
    for(int i=1;i<=n;i++){
        if(a[i]+a[i-1]>x){
            long long tmp=a[i]-(x-a[i-1]);
            ret+=tmp;
            a[i]=x-a[i-1];
        }
    }

    cout<<ret;
}