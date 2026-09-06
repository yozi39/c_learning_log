#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int C=205;

int n,s,c,maxx,minn=1e9;
int a[C],m[C];

int main(){
    cin>>n>>s>>c;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }

    sort(a+1,a+c+1);
    minn=a[1];
    maxx=a[c];
    for(int i=1;i<c;i++){
        m[i]=a[i+1]-a[i]-1;
    }
    sort(m+1,m+c,greater<int>());

    if(c<=n){
        cout<<c;
    } else {
        LL sum=maxx-minn+1;
        for(int i=1;i<n;i++){
            sum-=m[i];
        }
        cout<<sum;
    }
}