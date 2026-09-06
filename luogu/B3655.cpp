#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+5;

int n;
int a[7];
int t[N];

int main(){
    cin>>n;
    for(int i=1;i<=6;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>t[i];

    int cnt=0;
    LL ret=0;
    for(int i=1;i<=n;i++){
        if(t[i]){
            cnt++;
            if(cnt>=1 && cnt<3){
                ret+=a[1];
            } else if (cnt>=3 && cnt<7){
                ret+=a[2];
            } else if (cnt>=7 && cnt<30){
                ret+=a[3];
            } else if (cnt>=30 && cnt<120){
                ret+=a[4];
            } else if (cnt>=120 && cnt<365){
                ret+=a[5];
            } else {
                ret+=a[6];
            }
        } else {
            cnt=0;
        }
    }

    cout<<ret;
}