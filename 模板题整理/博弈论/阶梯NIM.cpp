#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int m;cin>>m;int a[m+5];
        int ret=0;
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        for(int i=m-1;i>=1;i-=2){
            ret^=a[i];
        }

        if(ret)cout<<"lyw\n";
        else cout<<"zgc\n";
    }
    return 0;
}
//https://ac.nowcoder.com/acm/problem/218562