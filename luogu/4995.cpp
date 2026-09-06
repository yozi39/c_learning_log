#include<bits/stdc++.h>
using namespace std;

const int N=305;
int n;
int a[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+1+n,greater<int>());

    long long ret=0,l=1,r=n,last=0;
    bool flag=true;
    while(l<=r){
        if(flag){
            ret+=(a[l]-last)*(a[l]-last);
            last=a[l];
            l++;
        } else {
            ret+=(a[r]-last)*(a[r]-last);
            last=a[r];
            r--;
        }
        flag=!flag;
    }
    cout<<ret;
}