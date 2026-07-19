#include<bits/stdc++.h>
using namespace std;
//https://ac.nowcoder.com/acm/problem/50614
int main(){
    int n,k;cin>>n>>k;
    if(n%(k+1)){
        cout<<1;
    }
    else{
        cout<<2;
    }
}