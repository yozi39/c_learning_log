#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;cin>>k;
    int day=1,cnt=1;
    long long sum=0;
    while (day<=k)
    {
        for(int i=1;i<=cnt;i++){
            sum+=cnt;
            day++;
            if(day>k) break;
        }
        cnt++;
    }
    cout<<sum;
}