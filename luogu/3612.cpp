#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string s;
LL n;

int main(){
    cin>>s>>n;

    LL len=s.size();
    LL L=len;

    while(L<n)L*=2;

    while(L>len){
        L/=2;

        if(n>L){
            if(n==L+1)n=L;
            else n=n-L-1;
        }
    }

    cout<<s[n-1];
}