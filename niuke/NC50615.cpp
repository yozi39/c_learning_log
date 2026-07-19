//https://ac.nowcoder.com/acm/problem/50615
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(i==0)continue;
        a[0]^=a[i];
    }

    if(a[0]!=0)cout<<"win";
    else{
        cout<<"lose";
    }
}