#include<bits/stdc++.h>
using namespace std;

const int N=30;
int n;
int pos[N];

int main(){
    cin>>n;
    int i=0;

    if(n&1){
        cout<<-1;
        return 0;
    }

    while(n){
        if(n&1)pos[i]=1;
        n>>=1;
        i++;
    }

    int a=2;
    stack<int> io;
    for(int i=1;i<=N-1;i++){
        if(pos[i])io.push(a);
        a*=2;
    }
    
    while (io.size())
    {
        cout<<io.top()<<' ';
        io.pop();
    }
    
}