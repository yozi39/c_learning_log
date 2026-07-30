#include<bits/stdc++.h>
using namespace std;
using LL=long long;

LL a,b,c;
string s;

int main(){
    cin>>a>>s;
    int len=s.size();
    for(auto ch:s){
        b=10*b+ch-'0';
    }
    for(int i=0;i<6;i++){
        c=c*10+s[i]-'0';
    }
    c*=1000000;

    if(len<12){
        cout<<a+100000000000-b;
    } else {
        cout << min(abs(c+a-b),
            abs(c+a-1000000-b));;
    }
}