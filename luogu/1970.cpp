#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n;
int a[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    int prev=0,cnt=0;
    for(int i=1;i<n;i++){
        int d=a[i+1]-a[i];
        if(!d)continue;

        d=(d>0? 1:-1);
        if(d != prev){
            cnt++;
        }
        prev=d;
    }
    cout<<cnt+1;
}