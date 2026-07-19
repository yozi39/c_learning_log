#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        if(n%6!=0){
            cout<<"October wins!\n";
        }
        else{
            cout<<"Roy wins!\n";
        }
    }
}