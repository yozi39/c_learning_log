#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int n,maxx=0;
int a[N];

int main(){
    cin>>n;
    int ret=0;cin>>a[1];
    ret=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]<=a[i-1]){
            continue;
        } else {
            ret+=a[i]-a[i-1];
        }
    }

    cout<<ret;
}