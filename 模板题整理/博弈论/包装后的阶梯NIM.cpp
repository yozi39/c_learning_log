#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int gap[N],a[N];
int n;

int main(){
    int T;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            a[i]=tmp;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)gap[i]=a[i]-a[i-1]-1;
        int ret=0;
        for(int i=n;i>=1;i-=2){
            ret^=gap[i];
        }
        if(ret)cout<<"Georgia will win\n";
        else cout<<"Bob will win\n";
    }
}//https://www.luogu.com.cn/problem/P10507