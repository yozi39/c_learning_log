#include<bits/stdc++.h>
using namespace std;

const int N=15;

int n;
int s[N],b[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i]>>b[i];
    
    long long ret=1e18;

    for(int mask=1;mask<(1<<n);mask++){
        long long nows=1,nowb=0;

        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                nows*=s[i+1];
                nowb+=b[i+1];
            }
        }

        ret=min(ret,llabs(nows-nowb));
    }

    cout<<ret;
}